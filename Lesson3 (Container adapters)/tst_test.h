#ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "FunctionsForTest.h"

using namespace testing;

TEST(IsExpressionValid, Test1)
{
    std::string InpStr = "[][]({})";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test2)
{
    std::string InpStr = "[][]({}]";
    EXPECT_EQ(false, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test3)
{
    std::string InpStr = "[()]{}{[()()]()}";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test4)
{
    std::string InpStr = "[)";
    EXPECT_EQ(false, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test5)
{
    std::string InpStr = "";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}

#endif // TST_TEST_H
