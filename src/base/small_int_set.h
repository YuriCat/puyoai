#ifndef BASE_SMALL_INT_SET_H_
#define BASE_SMALL_INT_SET_H_

#include <cstdint>
#include <glog/logging.h>

#include "base/builtin.h"

// SmallIntSet is an integer set that contains [0, 31].
class SmallIntSet {
public:
    void set(int x)
    {
        DCHECK(0 <= x && x < 32) << x;
        v_ |= (1 << x);
    }

    void unset(int x)
    {
        DCHECK(0 <= x && x < 32) << x;
        v_ &= ~(1 << x);
    }

    bool isSet(int x) const
    {
        DCHECK(0 <= x && x < 32) << x;
        return v_ & (1 << x);
    }

    bool isEmpty() const { return v_ == 0; }
    int size() const { return popCount32(v_); }

    int smallest() const
    {
        DCHECK(!isEmpty());
        return countTrailingZeros32(v_);
    }

    void removeSmallest()
    {
        v_ = v_ & (v_ - 1);
    }

    friend bool operator==(SmallIntSet lhs, SmallIntSet rhs) { return lhs.v_ == rhs.v_; }
    friend bool operator!=(SmallIntSet lhs, SmallIntSet rhs) { return lhs.v_ != rhs.v_; }

private:
    std::uint32_t v_ = 0;
};

#endif // BASE_SMALL_INT_SET_H_
