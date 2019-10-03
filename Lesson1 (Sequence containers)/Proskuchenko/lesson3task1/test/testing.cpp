#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "wordCounter.cpp"
#include <set>
#include <map>

using ::testing::Return;
using ::testing::_;

TEST(Test1, getUniqueWords) {
  std::string test_string {"Hello world, Hello cpp!"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  std::set<std::string> setOfWords {"hello","cpp","world"};
  std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test2, getUniqueWords) {
  std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  std::set<std::string> setOfWords {"my","friend","is"};
  std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test3, getUniqueWords) {
  std::string test_string {"Who is it??? It is joke."};
  std::vector<std::string> result{getUniqueWords(test_string)};
  std::set<std::string> setOfWords {"who","is","it","joke"};
  std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test4, getUniqueWords) {
  std::string test_string {"Who is it? ...  It is joke. joke"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  std::set<std::string> setOfWords {"who","is","it","joke"};
  std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test5, getUniqueWords) {
  std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  std::set<std::string> setOfWords {"some","words","for","joke"};
  std::vector<std::string> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test1, wordCounter) {
  std::string test_string {"Hello world, Hello cpp!"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  std::map<std::string, size_t> setOfWords {{"hello", 2},
                                            {"world", 1},
                                            {"cpp", 1}};
  std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test2, wordCounter) {
  std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  std::map<std::string, size_t> setOfWords {{"my", 3},
                                            {"friend", 2},
                                            {"is", 1}};
  std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test3, wordCounter) {
  std::string test_string {"Who is it? It is joke."};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  std::map<std::string, size_t> setOfWords {{"who", 1},
                                            {"is", 2},
                                            {"it", 2},
                                            {"joke", 1}};
  std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test4, wordCounter) {
  std::string test_string {"Who is it? ...  It is joke."};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  std::map<std::string, size_t> setOfWords {{"who", 1},
                                            {"is", 2},
                                            {"it", 2},
                                            {"joke", 1}};
  std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}

TEST(Test5, wordCounter) {
  std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  std::map<std::string, size_t> setOfWords {{"some", 3},
                                            {"words", 2},
                                            {"for", 2},
                                            {"joke", 1}};
  std::vector<std::pair<std::string, size_t>> for_compare {setOfWords.begin(),setOfWords.end()};
  EXPECT_EQ(result, for_compare);
}
