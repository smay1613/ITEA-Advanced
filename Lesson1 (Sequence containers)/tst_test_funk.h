#ifndef TST_TEST_FUNK_H
#define TST_TEST_FUNK_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Funk.h"

using namespace testing;

TEST(combineVectors, Test1)
{
    std::vector<int> a = {};
    std::vector<int> b = {-384};
    std::vector<int> result = {-384};
    std::vector<int>::const_iterator b1 = a.begin();
    std::vector<int>::const_iterator e1 = a.end();
    std::vector<int>::const_iterator b2 = b.begin();
    std::vector<int>::const_iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
    ASSERT_THAT(0, Eq(0));
}

TEST(combineVectors, Test2)
{
    std::vector<int> a = {};
    std::vector<int> b = {};
    std::vector<int> result = {};
    std::vector<int>::const_iterator b1 = a.begin();
    std::vector<int>::const_iterator e1 = a.end();
    std::vector<int>::const_iterator b2 = b.begin();
    std::vector<int>::const_iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
    ASSERT_THAT(0, Eq(0));
}
TEST(combineVectors, Test3)
{
    std::vector<int> a = {4,3,6,3,656,-5};
    std::vector<int> b = {4,6,2,6};
    std::vector<int> result = {4,3,6,3,656,-5,4,6,2,6};
    std::vector<int>::const_iterator b1 = a.begin();
    std::vector<int>::const_iterator e1 = a.end();
    std::vector<int>::const_iterator b2 = b.begin();
    std::vector<int>::const_iterator e2 = b.end();
    EXPECT_EQ(result, combineVectors(b1,e1,b2,e2));
    ASSERT_THAT(0, Eq(0));
}


TEST(magicNumber, Test1)
{
    size_t N = 10;
    size_t X = 5;
    size_t result = 1010101010;
    ASSERT_THAT(result, magicNumber(N,X));
}

TEST(magicNumber, Test2)
{
    size_t N = 19;
    size_t X = 4;
    size_t result = 19316911;
    ASSERT_THAT(result, magicNumber(N,X));
}

TEST(magicNumber, Test3)
{
    size_t N = 12;
    size_t X = 3;
    size_t result = 121418;
    ASSERT_THAT(result, magicNumber(N,X));
}

TEST(reverse, Test1)
{
    std::forward_list<int> inpList = {1,2,3};
    reverse(inpList);
    std::forward_list <int> result = {3,2,1};
    ASSERT_THAT(result, inpList);
}

TEST(reverse, Test2)
{
    std::forward_list<int> inpList = {};
    reverse(inpList);
    std::forward_list <int> result = {};
    ASSERT_THAT(result, inpList);
}

TEST(reverse, Test3)
{
    std::forward_list<int> inpList = {12};
    reverse(inpList);
    std::forward_list <int> result = {12};
    ASSERT_THAT(result, inpList);
}

#endif // TST_TEST_FUNK_H
