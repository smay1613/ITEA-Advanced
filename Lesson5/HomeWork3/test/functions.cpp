#include <gtest/gtest.h>
#include <functions.h>

class getUniqueWords : public ::testing::TestWithParam<std::pair<std::string, std::vector<std::string>>>
{
};

TEST_P(getUniqueWords, testCase)
{
    std::string string = std::get<0> (GetParam());
    std::vector<std::string> result = functions::getUniqueWords(string);
    std::vector<std::string> expected = std::get<1> (GetParam());
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(chekingText, getUniqueWords,::testing::Values
                        (
                            std::make_pair(std::string { "some text here some text here" },
                                           std::vector<std::string> { "here" , "some" , "text" }),

                            std::make_pair(std::string { "1 2 3" },
                                           std::vector<std::string> { "1" , "2" , "3" }),

                            std::make_pair(std::string { "" },
                                           std::vector<std::string> { "" }),

                            std::make_pair(std::string { "a b c d e e f g g" },
                                           std::vector<std::string> { "a" , "b" , "c" , "d" , "e" , "f" , "g"}),

                            std::make_pair(std::string { "run ok run ok" },
                                           std::vector<std::string> { "ok" , "run" })
                            )
                        );

class wordCounter : public ::testing::Test
{
};

TEST_F(wordCounter, testCase_1)
{
    std::string string { "some text here some text here" };
    std::vector<std::pair<std::string, size_t>> result = functions::wordCounter(string);
    std::vector<std::pair<std::string, size_t>> expected {{ "here", 2},{"some", 2}, {"text", 2}};
    EXPECT_EQ(result, expected);
};

TEST_F(wordCounter, testCase_2)
{
    std::string string_2 { "1 2 3 2 2 3 1" };
    std::vector<std::pair<std::string, size_t>> result_2 = functions::wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "1", 2},{"2", 3}, {"3", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounter, testCase_3)
{
    std::string string_2 { "run ok run ok" };
    std::vector<std::pair<std::string, size_t>> result_2 = functions::wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "ok", 2},{ "run", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounter, testCase_4)
{
    std::string string_2 { "a b c c" };
    std::vector<std::pair<std::string, size_t>> result_2 = functions::wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "a", 1},{"b", 1}, {"c", 2}};
    EXPECT_EQ(result_2, expected_2);
};
TEST_F(wordCounter, testCase_5)
{
    std::string string_2 { "test case 5 5 wordCounter" };
    std::vector<std::pair<std::string, size_t>> result_2 = functions::wordCounter(string_2);
    std::vector<std::pair<std::string, size_t>> expected_2 {{ "5", 2},{"case", 1}, {"test", 1}, {"wordCounter", 1}};
    EXPECT_EQ(result_2, expected_2);
};

