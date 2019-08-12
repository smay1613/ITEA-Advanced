#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>


std::vector<std::pair<std::string, size_t>> wordCounter(const std::string& text)
{
    std::vector<std::pair<std::string, size_t>> words_vector;
    std::map<std::string, size_t> words_map;
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
                if (words_map.empty())
                {
                    words_map.insert(std::make_pair(word, 1));
                    word.clear();
                }
                else
                {
                    std::map<std::string, size_t>::iterator element = words_map.find(word);

                    if (element != words_map.end())
                    {
                        element->second++;
                        word.clear();
                    }
                    else {
                        words_map.insert(std::make_pair(word, 1));
                        word.clear();
                    }
                }
            }
        }
    }
    if (!word.empty())
    {
        if (words_map.empty())
        {
            words_map.insert(std::make_pair(word, 1));
            word.clear();
        }
        else
        {
            std::map<std::string, size_t>::iterator element = words_map.find(word);

            if (element != words_map.end())
            {
                element->second++;
                word.clear();
            }
            else {
                words_map.insert(std::make_pair(word, 1));
                word.clear();
            }
        }
    }

    for (const auto & element : words_map)
    {
        words_vector.push_back(element);
    }

    return words_vector;
}

class word_counter_test : public ::testing::Test
{
public:
    std::string str_1 = "a a a a a a a a";
    std::string str_2 = "A A A a a.";
    std::string str_3 = "d c b a";
    std::string str_4 = "";
    std::string str_5 = "test!!! !! ! a a a a a a a a";

    std::vector<std::pair<std::string, size_t>> result_1 {{"a", 8}};
    std::vector<std::pair<std::string, size_t>> result_2 {{"a", 5}};
    std::vector<std::pair<std::string, size_t>> result_3 {{"a", 1}, {"b", 1}, {"c", 1}, {"d", 1}};
    std::vector<std::pair<std::string, size_t>> result_4 {};
    std::vector<std::pair<std::string, size_t>> result_5 {{"a", 8}, {"test", 1}};
};

TEST_F(word_counter_test, 1)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_1);
    EXPECT_EQ(result_vector.size(), result_1.size());
    for (int i=0; i < result_vector.size(); i++)
    {
        EXPECT_EQ(result_vector[i].first, result_1[i].first);
        EXPECT_EQ(result_vector[i].second, result_1[i].second);
    }
}

TEST_F(word_counter_test, 2)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_2);
    EXPECT_EQ(result_vector.size(), result_2.size());
    for (int i=0; i < result_vector.size(); i++)
    {
        EXPECT_EQ(result_vector[i].first, result_2[i].first);
        EXPECT_EQ(result_vector[i].second, result_2[i].second);
    }
}

TEST_F(word_counter_test, 3)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_3);
    EXPECT_EQ(result_vector.size(), result_3.size());
    for (int i=0; i < result_vector.size(); i++)
    {
        EXPECT_EQ(result_vector[i].first, result_3[i].first);
        EXPECT_EQ(result_vector[i].second, result_3[i].second);
    }
}

TEST_F(word_counter_test, 4)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_4);
    EXPECT_EQ(result_vector.size(), result_4.size());
    for (int i=0; i < result_vector.size(); i++)
    {
        EXPECT_EQ(result_vector[i].first, result_4[i].first);
        EXPECT_EQ(result_vector[i].second, result_4[i].second);
    }
}

TEST_F(word_counter_test, 5)
{
    std::vector<std::pair<std::string, size_t>> result_vector = wordCounter(str_5);
    EXPECT_EQ(result_vector.size(), result_5.size());
    for (int i=0; i < result_vector.size(); i++)
    {
        EXPECT_EQ(result_vector[i].first, result_5[i].first);
        EXPECT_EQ(result_vector[i].second, result_5[i].second);
    }
}
