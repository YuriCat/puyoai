#ifndef __CORE_SCORE_H_
#define __CORE_SCORE_H_

#include <glog/logging.h>

#include "core/constant.h"

inline int scoreForOjama(int num)
{
    return num * SCORE_FOR_OJAMA;
}

inline int chainBonus(int nthChain)
{
    DCHECK(0 <= nthChain && nthChain <= 19) << nthChain;
    return CHAIN_BONUS[nthChain];
}

inline int colorBonus(int numColors)
{
    DCHECK(0 <= numColors && numColors <= 5);
    return COLOR_BONUS[numColors];
}

inline int longBonus(int numPuyos)
{
    DCHECK(0 <= numPuyos);
    if (numPuyos > 11)
        numPuyos = 11;

    return LONG_BONUS[numPuyos];
}

inline int calculateRensaBonusCoef(int chainBonusCoef, int longBonusCoef, int colorBonusCoef)
{
    int coef = chainBonusCoef + longBonusCoef + colorBonusCoef;
    if (coef == 0)
        return 1;
    if (coef > 999)
        return 999;
    return coef;
}

#endif  // __CORE_SCORE_H_

