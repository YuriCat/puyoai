#include "core/bit_field.h"

#include <gtest/gtest.h>

using namespace std;

class BitFieldTest : public testing::Test {
protected:
    int vanish(BitField* bf, int chain, FieldBits* erased) {
        return bf->vanish(chain, erased);
    }
};

TEST_F(BitFieldTest, ctor)
{
    PlainField pf(
        "OOOOOO"
        "GGGYYY"
        "RRRBBB");

    BitField bf(pf);

    for (int x = 1; x <= 6; ++x) {
        for (int y = 1; y <= 12; ++y) {
            PuyoColor c = pf.color(x, y);
            if (isNormalColor(c) || c == PuyoColor::OJAMA) {
                EXPECT_TRUE(bf.isColor(x, y, c)) << x << ' ' << y << ' ' << c;
            }
        }
    }
}

TEST_F(BitFieldTest, vanish1)
{
    PlainField pf(
        "RRBBBB"
        "RGRRBB");
    BitField bf(pf);

    FieldBits erased;
    int score = vanish(&bf, 2, &erased);

    EXPECT_EQ(60 * 11, score);
    EXPECT_EQ(FieldBits(pf, PuyoColor::BLUE), erased);
}

TEST_F(BitFieldTest, vanish2)
{
    PlainField pf(
        "RRBB.B"
        "RGRRBB");
    BitField bf(pf);

    FieldBits erased;
    int score = vanish(&bf, 2, &erased);

    EXPECT_EQ(0, score);
}

TEST_F(BitFieldTest, vanish3)
{
    PlainField pf(
        "ROOOOR"
        "OBBBBO"
        "ROOOOR");
    BitField bf(pf);

    FieldBits erased;
    int score = vanish(&bf, 1, &erased);

    EXPECT_EQ(40, score);
    EXPECT_TRUE(bf.bits(PuyoColor::BLUE).isEmpty());
    EXPECT_TRUE(bf.bits(PuyoColor::OJAMA).isEmpty());
}

TEST_F(BitFieldTest, vanish4)
{
    PlainField pf(
        "RR.RRR" // 13
        "RRRRRR" // 12
        "OOOOOO"
        "OOOOOO"
        "OOOOOO"
        "OOOOOO" // 8
        "OOOOOO"
        "OOOOOO"
        "OOOOOO"
        "OOOOOO" // 4
        "OOOOOO"
        "OOOOOO"
        "OOOOOO");
    BitField bf(pf);

    FieldBits erased;
    int score = vanish(&bf, 1, &erased);

    EXPECT_EQ(60 * 3, score);
}
