#ifndef CORE_ALGORITHM_PLAN_H_
#define CORE_ALGORITHM_PLAN_H_

#include <functional>
#include <string>
#include <vector>

#include "base/base.h"
#include "core/decision.h"
#include "core/field/core_field.h"
#include "core/field/rensa_result.h"

class KumipuyoSeq;
class RefPlan;

class Plan {
public:
    Plan() {}
    Plan(const CoreField& field, const std::vector<Decision>& decisions,
         const RensaResult& rensaResult, int numChigiri, int framesToInitiate, int lastDropFrames) :
        field_(field), decisions_(decisions), rensaResult_(rensaResult),
        numChigiri_(numChigiri), framesToInitiate_(framesToInitiate), lastDropFrames_(lastDropFrames)
    {
    }

    typedef std::function<void (const RefPlan&)> IterationCallback;
    // if |kumipuyos.size()| < |depth|, we will add extra kumipuyo.
    static void iterateAvailablePlans(const CoreField&, const KumipuyoSeq&, int depth, IterationCallback);

    const CoreField& field() const { return field_; }

    const Decision& firstDecision() const { return decisions_[0]; }
    const Decision& decision(int nth) const { return decisions_[nth]; }
    const std::vector<Decision>& decisions() const { return decisions_; }

    const RensaResult& rensaResult() const { return rensaResult_; }
    int framesToInitiate() const { return framesToInitiate_; }
    int lastDropFrames() const { return lastDropFrames_; }

    int score() const { return rensaResult_.score; }
    int chains() const { return rensaResult_.chains; }

    int numChigiri() const { return numChigiri_; }
    int totalFrames() const { return framesToInitiate_ + lastDropFrames_ + rensaResult_.frames; }

    bool isRensaPlan() const { return rensaResult_.chains > 0; }

    std::string decisionText() const;

    friend bool operator==(const Plan& lhs, const Plan& rhs);

private:
    CoreField field_;      // Future field (after the rensa has been finished).
    std::vector<Decision> decisions_;
    RensaResult rensaResult_;
    int numChigiri_;
    int framesToInitiate_;
    int lastDropFrames_;
};

// RefPlan is almost same as plan, but holding references so that field copy will not occur.
// You can convert this to Plan with calling toPlan().
class RefPlan : noncopyable {
public:
    explicit RefPlan(const Plan& plan) :
        field_(plan.field()), decisions_(plan.decisions()), rensaResult_(plan.rensaResult()),
        numChigiri_(plan.numChigiri()), framesToInitiate_(plan.framesToInitiate()), lastDropFrames_(plan.lastDropFrames())
    {
    }

    RefPlan(const CoreField& field, const std::vector<Decision>& decisions,
            const RensaResult& rensaResult, int numChigiri, int framesToInitiate, int lastDropFrames) :
        field_(field), decisions_(decisions), rensaResult_(rensaResult),
        numChigiri_(numChigiri), framesToInitiate_(framesToInitiate), lastDropFrames_(lastDropFrames)
    {
    }

    const CoreField& field() const { return field_; }
    const std::vector<Decision>& decisions() const { return decisions_; }
    const Decision& decision(int nth) const { return decisions_[nth]; }
    const RensaResult& rensaResult() const { return rensaResult_; }

    int chains() const { return rensaResult_.chains; }
    int score() const { return rensaResult_.score; }

    // framesToInitiate returns how many frames are required just before the last hand.
    int framesToInitiate() const { return framesToInitiate_; }
    int lastDropFrames() const { return lastDropFrames_; }
    int totalFrames() const { return framesToInitiate_ + lastDropFrames_ + rensaResult_.frames; }
    int numChigiri() const { return numChigiri_; }

    bool isRensaPlan() const { return rensaResult_.chains > 0; }

    Plan toPlan() const { return Plan(field_, decisions_, rensaResult_, numChigiri_, framesToInitiate_, lastDropFrames_); }

    std::string decisionText() const;

private:
    const CoreField& field_;
    const std::vector<Decision>& decisions_;
    const RensaResult& rensaResult_;
    int numChigiri_;
    int framesToInitiate_;
    int lastDropFrames_;
};

#endif
