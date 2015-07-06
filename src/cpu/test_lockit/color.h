#ifndef TEST_LOCKIT_COLOR_H_
#define TEST_LOCKIT_COLOR_H_

#include "core/puyo_color.h"

namespace test_lockit {

// PuyoColor for test_lockit. When all puyo color is converted to this enum,
// the real PuyoColor should be used.
enum TLColor {
    TL_EMPTY = 0,
    TL_RED = 1,
    TL_BLUE = 2,
    TL_YELLOW = 3,
    TL_GREEN = 4,
    TL_OJAMA = 9,

    TL_UNKNOWN = 10,
};

inline bool isNormalTLColor(TLColor color)
{
    switch (color) {
    case TL_RED:
    case TL_BLUE:
    case TL_YELLOW:
    case TL_GREEN:
        return true;
    default:
        return false;
    }
}

// Color coverter
TLColor toTLColor(PuyoColor pc);
PuyoColor toPuyoColor(TLColor c);

TLColor toValidTLColor(TLColor c);

}  // namespace test_lockit

#endif
