#ifndef __PLAYER_INFO_H_
#define __PLAYER_INFO_H_

#include "field.h"
#include "rensa_info.h"

class Decision;
class EvaluationParams;
class KumiPuyo;

class MyPlayerInfo {
public:
    const Field& estimatedField() const { return m_estimatedField; }

    void initialize();

    // For field estimation
    void puyoDropped(const Decision&, const KumiPuyo&);
    void ojamaDropped(const Field&);
    void rensaFinished(const Field&);
    void forceEstimatedField(const Field& field) { m_estimatedField = field; }

private:
    ArbitrarilyModifiableField m_estimatedField;
};

#endif
