#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../task/main.h"

using namespace testing;

TEST(testCase, testSet)
{
    //empty expression
    std::string expression;
    EXPECT_EQ(isExpressionValid(expression), true);
}

TEST(testCase2, testSet)
{
    //valid expression
    std::string expression {"()({}[([{}]()(()))])"};
    EXPECT_EQ(isExpressionValid(expression), true);
}

TEST(testCase3, testSet)
{
    //count of opening brackets equals count of closing btackets
    std::string expression {"{{}()})}])))((([{("};
    EXPECT_EQ(isExpressionValid(expression), false);
}

TEST(testCase4, testSet)
{
    //count of opening brackets < count of closing btackets
    std::string expression {"()[]{}}))))]"};
    EXPECT_EQ(isExpressionValid(expression), false);
}

TEST(testCase5, testSet)
{
    //count of opening brackets > count of closing btackets
    std::string expression {"()[]{}{((((["};
    EXPECT_EQ(isExpressionValid(expression), false);
}

