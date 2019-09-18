#include "gtest/gtest.h"
#include "/home/anyo/Projects/GoogleTests/library.h"

TEST(Vector_Tests, Size_Test)
{
    std::vector<int> a (2);
    std::vector<int> b (2);

    EXPECT_EQ(4, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(MagicNumber_Tests, EQ_Test)
{
    EXPECT_EQ(19316911, magicNumber(19,4));
}

TEST(List_Tests, Reverse_Test)
{
    std::forward_list<int> a {1, 2, 3};
    EXPECT_EQ(1, *a.begin());
    reverse(a);
    EXPECT_EQ(3, *a.begin());
}
