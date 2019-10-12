 #ifndef TST_TEST_H
#define TST_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <vector>
#include <iostream>
#include "TestFunctions.h"
#include <algorithm>


using namespace testing;

TEST(getUniqueWords, Test1)
{
    std::string InpStr {"hi Hi   *h Lol"};
    std::vector<std::string> OutVector{"hi", "h", "lol"};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(true, std::is_permutation(OutVector.begin(), OutVector.end(), vectFromFunk.begin()));
}

TEST(getUniqueWords, Test2)
{
    std::string InpStr {" "};
    std::vector<std::string> OutVector{};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(true, std::is_permutation(OutVector.begin(), OutVector.end(), vectFromFunk.begin()));
}

TEST(getUniqueWords, Test3)
{
    std::string InpStr {"//////*0 i"};
    std::vector<std::string> OutVector{"0" , "i"};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(true, std::is_permutation(OutVector.begin(), OutVector.end(), vectFromFunk.begin()));
}

TEST(getUniqueWords, Test4)
{
    std::string InpStr {"b B    * b"};
    std::vector<std::string> OutVector{"b"};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(true, std::is_permutation(OutVector.begin(), OutVector.end(), vectFromFunk.begin()));;
}

TEST(getUniqueWords, Test5)
{
    std::string InpStr {"*)(*^  /)"};
    std::vector<std::string> OutVector{};
    std::vector<std::string> vectFromFunk = getUniqueWords(InpStr);
    EXPECT_EQ(true, std::is_permutation(OutVector.begin(), OutVector.end(), vectFromFunk.begin()));
}

TEST(wordCounter, Test1)
{
    std::string InpStr {"Goo"};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"goo",1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test2)
{
    std::string InpStr {"Good go od  m nddd "};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"good", 1},
                                                            {"go", 1},
                                                            {"od", 1},
                                                            {"m", 1},
                                                            {"nddd", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test3)
{
    std::string InpStr {"will  Will Be*)  "};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"will", 2},
                                                            {"be", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test4)
{
    std::string InpStr {"will  Will  Be*) *Our,, Empl  will"};
    std::vector<std::pair<std::string,size_t>> OutVector = {{"will", 3},
                                                            {"be", 1},
                                                            {"our", 1},
                                                            {"empl", 1}};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}

TEST(wordCounter, Test5)
{
    std::string InpStr {""};
    std::vector<std::pair<std::string,size_t>> OutVector = {};
    std::vector<std::pair<std::string,size_t>> vectfromFunk = wordCounter(InpStr);
    EXPECT_EQ(true,std::is_permutation(OutVector.begin(),OutVector.end(),vectfromFunk.begin()));
}


#endif // TST_TEST_H
