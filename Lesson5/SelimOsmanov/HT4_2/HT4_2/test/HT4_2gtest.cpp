#include <set>
#include <unordered_set>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

void CountsOfSameWords(std::string& EnterText, std::multiset<std::string>& OutText){
    std::stringstream str;
    str << EnterText;
    std::string streamStr;
    while (str >> streamStr){
        OutText.insert(streamStr);
    }
    std::string Rewritable;
    for(auto element : OutText){
        if (element == Rewritable){
            continue;
        }
        Rewritable = element;
        std::cout << element << "\t:\t" << OutText.count(element) << std::endl;
    }
}

void GetCounts(std::multiset<std::string> const& OutText, std::multiset<size_t> & Counts){
    std::string Rewritable;
    for(auto element : OutText){
        if (element == Rewritable){
            continue;
        }
        Rewritable = element;
        Counts.insert(OutText.count(element));
    }
}

TEST(OutTextNotSameWords, Test1){
    std::string EnterText {"hello world, hello cpp ! hello hello hello apple an orange an laptop"};
    std::multiset<std::string> OutText;
    CountsOfSameWords(EnterText, OutText);
    std::multiset<size_t> Counts;
    GetCounts(OutText, Counts);

    EXPECT_THAT(Counts, ::testing::ElementsAre(1, 1, 1, 1, 1, 1, 2, 5));
}

TEST(OutTextNotSameWords, Test2){
    std::string EnterText;
    std::multiset<std::string> OutText;
    CountsOfSameWords(EnterText, OutText);
    std::multiset<size_t> Counts;
    GetCounts(OutText, Counts);

    EXPECT_THAT(Counts, ::testing::ElementsAre());
}

TEST(OutTextNotSameWords, Test3){
    std::string EnterText {"1 1 1 1 1 1 1 1 1 1 2"};
    std::multiset<std::string> OutText;
    CountsOfSameWords(EnterText, OutText);
    std::multiset<size_t> Counts;
    GetCounts(OutText, Counts);

    EXPECT_THAT(Counts, ::testing::ElementsAre(1, 10));
}

TEST(OutTextNotSameWords, Test4){
    std::string EnterText {"hello hello hello"};
    std::multiset<std::string> OutText;
    CountsOfSameWords(EnterText, OutText);
    std::multiset<size_t> Counts;
    GetCounts(OutText, Counts);

    EXPECT_THAT(Counts, ::testing::ElementsAre(3));
}

TEST(OutTextNotSameWords, Test5){
    std::string EnterText {"4 2 2 2 3 3 1 1 1 1"};
    std::multiset<std::string> OutText;
    CountsOfSameWords(EnterText, OutText);
    std::multiset<size_t> Counts;
    GetCounts(OutText, Counts);

    EXPECT_THAT(Counts, ::testing::ElementsAre(1, 2, 3, 4));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
