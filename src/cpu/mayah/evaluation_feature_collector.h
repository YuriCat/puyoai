#ifndef __EVALUATION_FEATURE_COLLECTOR_H_
#define __EVALUATION_FEATURE_COLLECTOR_H_

class CoreField;
class EnemyInfo;
class EvaluationFeature;
class RensaTrackResult;
class Plan;
class PlanEvaluationFeature;
class RensaEvaluationFeature;
struct TrackedPossibleRensaInfo;

class EvaluationFeatureCollector {
public:
    // Collects all features.
    static void collectFeatures(EvaluationFeature&, const Plan&, int numKeyPuyos, int currentFrameId, const EnemyInfo&);

private:
    static void collectPlanFeatures(PlanEvaluationFeature&, const Plan&, int currentFrameId, const EnemyInfo&);

    // Methods to collect plan features.
    static void collectFrameFeature(PlanEvaluationFeature&, const Plan&);
    static void collectConnectionFeature(PlanEvaluationFeature&, const Plan&);
    static void collectDensityFeature(PlanEvaluationFeature&, const Plan&);
    static void collectPuyoPattern33Feature(PlanEvaluationFeature&, const Plan&);
    static void collectFieldHeightFeature(PlanEvaluationFeature&, const Plan&);
    static void collectEmptyAvailabilityFeature(PlanEvaluationFeature&, const Plan&);
    static void collectOngoingRensaFeature(PlanEvaluationFeature&, const Plan&, int currentFrameId, const EnemyInfo&);

private:
    static void collectRensaFeatures(RensaEvaluationFeature&, const Plan&, const TrackedPossibleRensaInfo&);

    // Methods to collect rensa features.
    static void collectRensaChainFeature(RensaEvaluationFeature&, const Plan&, const TrackedPossibleRensaInfo&);
    static void collectRensaHandWidthFeature(RensaEvaluationFeature&, const Plan&, const TrackedPossibleRensaInfo&);
    static void collectRensaConnectionFeature(RensaEvaluationFeature&, const CoreField& fieldAfterRensa, const CoreField& fieldAfterDrop);
    static void collectRensaGarbageFeature(RensaEvaluationFeature&, const Plan&, const CoreField& fieldAfterDrop);
};

#endif
