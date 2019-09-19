#include "gtest/gtest.h"
#include "/home/anyo/Projects/GoogleTests/library.h"

TEST(Vector_Tests, Size_Test)
{
    std::vector<int> a (2);
    std::vector<int> b (2);

    EXPECT_EQ(4, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Max)
{
    uint test_size = 100000000;
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Empty)
{
    uint test_size = 0;
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(Vector_Tests, Size_Test_Wrong)
{
    char test_size = 'k';
    std::vector<int> a (test_size);
    std::vector<int> b (test_size);

    EXPECT_EQ(2 * test_size, combineVectors(a.begin(), a.end(), b.begin(), b.end()).size());
}

TEST(MagicNumber_Tests, EQ_Test)
{
    EXPECT_EQ(19316911, magicNumber(19,4));
}

TEST(MagicNumber_Tests, Test_16_9)
{
    EXPECT_EQ(162646661616264666, magicNumber(16,9));
}

TEST(MagicNumber_Tests, Test_17_13)
{
    EXPECT_EQ(5201518695802786717, magicNumber(17,13));
}

TEST(MagicNumber_Tests, Test_Zero)
{
    EXPECT_EQ(0, magicNumber(0,13));
}

TEST(MagicNumber_Tests, Test_One)
{
    EXPECT_EQ(10, magicNumber(10,0));
}

TEST(List_Tests, Reverse_Test_1)
{
    std::forward_list<int> a {1, 2, 3};
    std::forward_list<int> b = a;
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}

TEST(List_Tests, Reverse_Test_2)
{
    std::forward_list<int> a;
    for (int i = 0; i < 1000000; ++i){
        a.push_front(i);
    }
    std::forward_list<int> b = a;
    b.reverse();
    reverse(a);
    EXPECT_EQ(b, a);
}
