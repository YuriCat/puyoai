#include "cpu/peria/pai.h"

#include <gflags/gflags.h>
#include <glog/logging.h>

#include <algorithm>
#include <cstdint>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

#include "base/time.h"
#include "core/core_field.h"
#include "core/kumipuyo_seq_generator.h"
#include "core/plan/plan.h"
#include "core/rensa/rensa_detector.h"
#include "cpu/peria/situation.h"

DECLARE_int32(simulate_size);
DECLARE_int32(simulate_width);

namespace peria {

using int64 = std::int64_t;

namespace {

struct State {
  Decision firstDecision;
  CoreField field;
  int score;
  int expectChain;
  int expectScore;
  int frameId;

  double value;
};

void GenerateNext(State state, const RefPlan& plan, std::vector<State>* nextStates) {
  if (!state.firstDecision.isValid()) {
    state.firstDecision = plan.firstDecision();
  }
  state.field = plan.field();
  state.score += plan.score();
  state.frameId = plan.totalFrames();

  int expectScore = 0;
  int expectChain = 0;
  bool prohibits[FieldConstant::MAP_WIDTH] {};
  auto complementCallback = [&expectScore, &expectChain](CoreField&& field, const ColumnPuyoList&) {
      RensaResult result = field.simulate();
      expectScore = std::max(expectScore, result.score);
      expectChain = std::max(expectChain, result.chains);
  };
  RensaDetector::detectByDropStrategy(state.field, prohibits, PurposeForFindingRensa::FOR_FIRE, 2, 13, complementCallback);
  state.expectScore = expectScore;
  state.expectChain = expectChain;

  state.value = expectScore;

  nextStates->push_back(state);
}

bool CompValue(const State& a, const State& b) {
  return a.value > b.value;
};

}  // namespace

Pai::Pai(int argc, char* argv[]): ::AI(argc, argv, "peria") {}

Pai::~Pai() {}

DropDecision Pai::think(int frameId,
                        const CoreField& field,
                        const KumipuyoSeq& seq,
                        const PlayerState& myState,
                        const PlayerState& enemyState,
                        bool fast) const {
  UNUSED_VARIABLE(enemyState);
  std::ostringstream oss;

  int64 startTime = currentTimeInMillis();
  int64 dueTime = startTime + (fast ? 25 : 250);

  const int fullIterationDepth = 20;
  const int detectIterationDepth = std::min(seq.size(), 3);
  const int unknownIterationDepth = fullIterationDepth - detectIterationDepth;
  std::vector<std::vector<State>> states(fullIterationDepth + 1);
  CHECK_GE(unknownIterationDepth, 0);
  LOG(INFO) << detectIterationDepth << " / " << fullIterationDepth << " search";

  Decision finalDecision;
  int bestScore = 0;

  State firstState;
  // intentionally leave firstState.firstDecision unset
  firstState.field = field;
  firstState.score = myState.unusedScore;
  firstState.expectChain = 0;
  firstState.expectScore = 0;
  firstState.frameId = frameId;

  oss << "sizes: ";
  states[0].push_back(firstState);
  for (int i = 0; i < detectIterationDepth; ++i) {
    auto& nextStates = states[i + 1];
    for (const State& s : states[i]) {
      auto generateNext = std::bind(GenerateNext, s, std::placeholders::_1, &nextStates);
      Plan::iterateAvailablePlans(field, {seq.get(i)}, 1, generateNext);
    }
    std::sort(nextStates.begin(), nextStates.end(), CompValue);
    if (static_cast<int>(nextStates.size()) > FLAGS_simulate_width)
      nextStates.resize(FLAGS_simulate_width);

    oss << nextStates.size() << "/";
    for (const State& s : nextStates) {
      if (s.expectScore > bestScore) {
        finalDecision = s.firstDecision;
        bestScore = s.expectScore;
      }
    }
  }
  LOG(INFO) << "<Detective> (" << finalDecision.axisX() << "," << finalDecision.rot() << ") "
            << bestScore << " points";

  oss << detectIterationDepth << "\n";
  if (states[detectIterationDepth].size() == 0) {
    oss << "Die";
    return DropDecision(Decision(3, 0), oss.str());
  }

  int64 detectTime = currentTimeInMillis();
  oss << "Known: " << (detectTime - startTime) << "ms/ "
      << states[detectIterationDepth].size() << " states/ "
      << detectIterationDepth << "-th hands: "
      << "(" << finalDecision.axisX() << "-" << finalDecision.rot() << ")"
      << " with " << bestScore << " points\n";

  int nTest = 0;
  std::map<Decision, std::vector<double>> vote;
  for (nTest = 0; currentTimeInMillis() < dueTime; ++nTest) {
    Decision decision;
    double score = 0;

    KumipuyoSeq pseudoSeq = KumipuyoSeqGenerator::generateRandomSequence(unknownIterationDepth);
    for (int i = detectIterationDepth, j = 0; i < fullIterationDepth; ++i, ++j) {
      auto& nextStates = states[i + 1];
      nextStates.clear();
      for (const State& s : states[i]) {
        auto generateNext = std::bind(GenerateNext, s, std::placeholders::_1, &nextStates);
        Plan::iterateAvailablePlans(field, {seq.get(j)}, 1, generateNext);
      }
      std::sort(nextStates.begin(), nextStates.end(), CompValue);
      if (static_cast<int>(nextStates.size()) > FLAGS_simulate_width) {
        nextStates.resize(FLAGS_simulate_width);
      }

      for (const State& s : nextStates) {
        if (s.score > score) {
          decision = s.firstDecision;
          score = s.score;
        }
      }
    }
    if (decision.isValid()) {
      LOG(INFO) << "vote: " << decision << " " << score;
      vote[decision].push_back(score);
    }
  }

  int64 endTime = currentTimeInMillis();
  oss << "simulation: " << (endTime - detectTime) << "ms (" << nTest << " times)\n";

  if (vote.size()) {
    double bestAvgScore = bestScore * .9;
    for (auto& v : vote) {
      double avg = std::accumulate(v.second.begin(), v.second.end(), 0.0);
      avg /= v.second.size();
      LOG(INFO) << v.first << " " << v.second.size() << " " << avg;
      if (avg > bestAvgScore) {
        bestAvgScore = avg;
        finalDecision = v.first;
      }
    }
    oss << "Final: (" << finalDecision.axisX() << "-" << finalDecision.rot() << ")"
        << " with " << bestAvgScore << " points\n";
  } else {
    oss << "Final: no updates\n";
  }

  return DropDecision(finalDecision, oss.str());
}

}  // namespace peria
