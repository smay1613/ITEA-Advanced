#include <gtest/gtest.h>
#include <functions.h>

class isExpressionValid : public ::testing::TestWithParam<std::pair<std::string, bool>>
{
};

TEST_P(isExpressionValid, testCase)
{
    std::string string = std::get<0> (GetParam());
    bool expected = std::get<1> (GetParam());
    bool result = functions::isExpressionValid(string);
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(chekingExpression, isExpressionValid,::testing::Values
                        (
                            std::make_pair(std::string { "()" },                bool {true}),
                            std::make_pair(std::string { ")(" },                bool {false}),
                            std::make_pair(std::string { "((()()())()())" },    bool {true}),
                            std::make_pair(std::string { "())(" },              bool {false}),
                            std::make_pair(std::string { "[)" },                bool {false}),
                            std::make_pair(std::string { "([])" },              bool {true}),
                            std::make_pair(std::string { "[()]{}{[()()]()}" },  bool {true})
                            )
                        );
