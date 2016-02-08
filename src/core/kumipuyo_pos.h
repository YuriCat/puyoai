#ifndef CORE_KUMIPUYO_POS_H_
#define CORE_KUMIPUYO_POS_H_

#include <string>

class KumipuyoPos {
public:
    constexpr KumipuyoPos() : x(0), y(0), r(0) {}
    constexpr KumipuyoPos(int x, int y, int r) : x(x), y(y), r(r) {}

    // NOTE(peria): Need constructor declaration prior to this static constexpr for MSVC 2015.
    // https://blogs.msdn.microsoft.com/vcblog/2015/04/29/c11-constant-expressions-in-visual-studio-2015-rc/
    static constexpr KumipuyoPos initialPos() { return KumipuyoPos(3, 12, 0); }

    constexpr int axisX() const { return x; }
    constexpr int axisY() const { return y; }
    constexpr int childX() const { return x + (r == 1) - (r == 3); }
    constexpr int childY() const { return y + (r == 0) - (r == 2); }
    constexpr int rot() const { return r; }

    bool isValid() const { return 1 <= x && x <= 6 && 1 <= y && y <= 13 && 0 <= r && r <= 4; }

    std::string toDebugString() const;

    friend bool operator==(const KumipuyoPos& lhs, const KumipuyoPos& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y && lhs.r == rhs.r; }
    friend bool operator!=(const KumipuyoPos& lhs, const KumipuyoPos& rhs) { return !(lhs == rhs); }
    friend bool operator<(const KumipuyoPos& lhs, const KumipuyoPos& rhs)
    {
        if (lhs.x != rhs.x)
            return lhs.x < rhs.x;
        if (lhs.y != rhs.y)
            return lhs.y < rhs.y;
        return lhs.r < rhs.r;
    }
    friend bool operator>(const KumipuyoPos& lhs, const KumipuyoPos& rhs) { return rhs < lhs; }

public:
    // TODO(mayah): Make these private?
    int x;
    int y;
    int r;
};

#endif
