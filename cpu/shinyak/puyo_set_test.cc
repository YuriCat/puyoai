#include "puyo_set.h"

#include <gtest/gtest.h>

TEST(PuyoSetTest, AddPuyoColor)
{
    PuyoSet set;
    set.add(RED, 1);

    EXPECT_EQ(set.red(), 1U);
    EXPECT_EQ(set.blue(), 0U);
    EXPECT_EQ(set.yellow(), 0U);
    EXPECT_EQ(set.green(), 0U);
}

TEST(PuyoSetTest, AddPuyoSet)
{
    PuyoSet set1, set2;
    set1.add(RED, 1);
    set1.add(GREEN, 1);
    set2.add(RED, 1);
    set2.add(BLUE, 1);

    PuyoSet set;
    set.add(set1);
    set.add(set2);
    EXPECT_EQ(set.red(), 2U);
    EXPECT_EQ(set.blue(), 1U);
    EXPECT_EQ(set.yellow(), 0U);
    EXPECT_EQ(set.green(), 1U);
}
