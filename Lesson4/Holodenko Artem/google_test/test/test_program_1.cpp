#include "gtest/gtest.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>


std::vector<std::string> getUniqueWords(const std::string& text)
{
    std::vector<std::string> words_vector;
    std::set<std::string> words_set;
    std::string word;

    for (const auto & element : text)
    {
        if (!ispunct(element) && element != ' ')
        {
            word += tolower(element);
        }
        else
        {
            if (!word.empty())
            {
                words_set.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty())
    {
        words_set.insert(word);
    }

    for (const auto & element : words_set)
    {
        words_vector.push_back(element);
    }

    return words_vector;
}




class get_unique_words_test : public ::testing::Test
{
public:
    std::string str_1 = "The European hare is one of the";
    std::string str_2 = "Native to Europe and parts of Asia";
    std::string str_3 = "a b c d";
    std::string str_4 = "";
    std::string str_5 = "test a a a a a a a a";

    std::set<std::string> result_1 {{"the"},{"european"},{"hare"}, {"is"}, {"one"}, {"of"}};
    std::set<std::string> result_2 {{"native"},{"to"},{"europe"}, {"and"}, {"parts"}, {"of"}, {"asia"}};
    std::set<std::string> result_3 {{"a"},{"b"},{"c"}, {"d"}};
    std::set<std::string> result_4 {};
    std::set<std::string> result_5 {{"test"},{"a"}};
};



TEST_F(get_unique_words_test, 1)
{
    std::vector<std::string> result_vector = getUniqueWords(str_1);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_1);
}

TEST_F(get_unique_words_test, 2)
{
    std::vector<std::string> result_vector = getUniqueWords(str_2);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_2);
}

TEST_F(get_unique_words_test, 3)
{
    std::vector<std::string> result_vector = getUniqueWords(str_3);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_3);
}

TEST_F(get_unique_words_test, 4)
{
    std::vector<std::string> result_vector = getUniqueWords(str_4);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_4);
}

TEST_F(get_unique_words_test, 5)
{
    std::vector<std::string> result_vector = getUniqueWords(str_5);
    std::set<std::string> result_set;
    for (const auto& element : result_vector)
    {
        result_set.insert(element);
    }
    EXPECT_EQ(result_set, result_5);
}
