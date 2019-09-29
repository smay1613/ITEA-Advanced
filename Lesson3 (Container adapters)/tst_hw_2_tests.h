#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "functions.h"

using namespace testing;

TEST(Parentheses_Test, Test_1)
{
    std::string input {"{{}[[()]()]{}}"};
    bool answer = isExpressionValid(input);

    EXPECT_EQ(answer, true);
}

TEST(Parentheses_Test, Test_2)
{
    std::string input {""};
    bool answer = isExpressionValid(input);

    EXPECT_EQ(answer, true);
}

TEST(Parentheses_Test, Test_3)
{
    std::string input {"{{}[[(]()]{}}"};
    bool answer = isExpressionValid(input);

    EXPECT_EQ(answer, false);
}
TEST(Parentheses_Test, Test_4)
{
    std::string input {"{{}[[]()]{}}({])"};
    bool answer = isExpressionValid(input);

    EXPECT_EQ(answer, false);
}
TEST(Parentheses_Test, Test_5)
{
    std::string input {"{{{}[[()]()]}{}}"};
    bool answer = isExpressionValid(input);

    EXPECT_EQ(answer, true);
}

TEST(Tree_Test, Test_1)
{
    node a, b, c, d, e, f, g;
    a = {1, &b, &c, nullptr};
    b = {2, &d, &e, nullptr};
    c = {3, nullptr, &f, nullptr};
    d = {4, &g, nullptr, nullptr};
    e = {5, nullptr, nullptr, nullptr};
    f = {6, nullptr, nullptr, nullptr};
    g = {7, nullptr, nullptr, nullptr};
    node* tree_root = &a;
    linkLevelNodes(tree_root);

    EXPECT_EQ(a.level, nullptr);
    EXPECT_EQ(b.level, &c);
    EXPECT_EQ(c.level, nullptr);
    EXPECT_EQ(d.level, &e);
    EXPECT_EQ(e.level, &f);
    EXPECT_EQ(f.level, nullptr);
    EXPECT_EQ(g.level, nullptr);
}

