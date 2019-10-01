#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "functions.h"

using namespace testing;

TEST(Set_Tests, Test_1)
{
    std::string text = "Hello world, hello cpp!";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"cpp", "world", "Hello"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Set_Tests, Test_2)
{
    std::string text = "or or!= do) dO ant !Ant";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"ant", "do", "or"};

    EXPECT_EQ(a.size(), b.size());
}

TEST(Set_Tests, Test_3)
{
    std::string text = "and and and aNd";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"and"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Set_Tests, Test_4)
{
    std::string text = "hot hoW %to Tp To& trade? tRaDE+";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b (5);

    EXPECT_EQ(a.size(), b.size());
}

TEST(Set_Tests, Test_5)
{
    std::string text = "inktober, InKtObEr! INKtoBer+)))) InktOBER+@ ^%InkTobeR";
    std::vector<std::string> a = getUniqueWords(text);
    std::vector<std::string> b {"inktober"};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_1)
{
    std::string text = "Hello world, hello cpp!";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"cpp", 1}, {"world", 1}, {"Hello", 2}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_2)
{
    std::string text = "or or!= do) dO ant !Ant";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"ant", 2}, {"do", 2}, {"or", 2}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_3)
{
    std::string text = "and and and aNd";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"and", 4}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_4)
{
    std::string text = "hot hoW %to Tp To& trade? tRaDE+";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"trade", 2}, {"Tp", 1}, {"to", 2}, {"hoW", 1}, {"hot", 1}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}

TEST(Map_Tests, Test_5)
{
    std::string text = "inktober, InKtObEr! INKtoBer+)))) InktOBER+@ ^%InkTobeR";
    std::vector<std::pair<std::string, size_t>> a = wordCounter(text);
    std::vector<std::pair<std::string, size_t>> b {{"inktober", 5}};

    EXPECT_EQ(std::equal(a.begin(), a.end(), b.begin()), true);
}
