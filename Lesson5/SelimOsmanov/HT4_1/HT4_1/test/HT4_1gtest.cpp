#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

void OutTextNotSameWords(std::string const& EnterText, std::set<std::string> & OutText){
    std::stringstream str;
    str << EnterText;
    std::string streamStr;
    while (str >> streamStr){
        OutText.insert(streamStr);
    }
}

bool Comparator (std::set<std::string> const& ExpectWords, std::set<std::string> const& OutText){
    if(OutText == ExpectWords){
        return true;
    }
    else{
        return false;
    }
}

TEST(OutTextNotSameWords, Test1){
    std::string EnterText {"hello world, hello cpp !"};
    std::set<std::string> OutText;
    std::set<std::string> ExpectWords {"hello", "world", "cpp", "!"};
    OutTextNotSameWords(EnterText, OutText);
    Comparator (ExpectWords, OutText);
    EXPECT_TRUE(Comparator);
}

TEST(OutTextNotSameWords, Test2){
    std::string EnterText;
    std::set<std::string> OutText;
    std::set<std::string> ExpectWords;
    OutTextNotSameWords(EnterText, OutText);
    Comparator (ExpectWords, OutText);
    EXPECT_TRUE(Comparator);
}

TEST(OutTextNotSameWords, Test3){
    std::string EnterText {"на дворе трава, на траве дрова!"};
    std::set<std::string> OutText;
    std::set<std::string> ExpectWords {"на", "дворе", "трава,", "траве", "дрова!"};
    OutTextNotSameWords(EnterText, OutText);
    Comparator (ExpectWords, OutText);
    EXPECT_TRUE(Comparator);
}

TEST(OutTextNotSameWords, Test4){
    std::string EnterText {"cpp cpp cpp cpp cpp !"};
    std::set<std::string> OutText;
    std::set<std::string> ExpectWords {"cpp", "!"};
    OutTextNotSameWords(EnterText, OutText);
    Comparator (ExpectWords, OutText);
    EXPECT_TRUE(Comparator);
}

TEST(OutTextNotSameWords, Test5){
    std::string EnterText {"1 2 3 4 5 5 4 3 2 1"};
    std::set<std::string> OutText;
    std::set<std::string> ExpectWords {"1", "2", "3", "4" "5"};
    OutTextNotSameWords(EnterText, OutText);
    Comparator (ExpectWords, OutText);
    EXPECT_TRUE(Comparator);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

