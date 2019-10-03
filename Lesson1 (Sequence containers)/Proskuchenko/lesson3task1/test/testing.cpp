#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "wordCounter.cpp"

using ::testing::Return;
using ::testing::_;

TEST(Test1, getUniqueWords) {
  std::string test_string {"Hello world, Hello cpp!"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i) == "hello") {
    } else if (result.at(i) == "world") {
    } else if (result.at(i) == "cpp") {
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 3);
}

TEST(Test2, getUniqueWords) {
  std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i) == "friend") {
    } else if (result.at(i) == "is") {
    } else if (result.at(i) == "my") {
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 3);
}

TEST(Test3, getUniqueWords) {
  std::string test_string {"Who is it??? It is joke."};
  std::vector<std::string> result{getUniqueWords(test_string)};
  for (size_t i = 0; i < 4; ++i) {
    if (result.at(i) == "who") {
    } else if (result.at(i) == "is") {
    } else if (result.at(i) == "it") {
    } else if (result.at(i) == "joke") {
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}

TEST(Test4, getUniqueWords) {
  std::string test_string {"Who is it? ...  It is joke."};
  std::vector<std::string> result{getUniqueWords(test_string)};
  for (size_t i = 0; i < 4; ++i) {
    if (result.at(i) == "who") {
    } else if (result.at(i) == "is") {
    } else if (result.at(i) == "it") {
    } else if (result.at(i) == "joke") {
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}

TEST(Test5, getUniqueWords) {
  std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
  std::vector<std::string> result{getUniqueWords(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i) == "some") {
    } else if (result.at(i) == "words") {
    } else if (result.at(i) == "for") {
    } else if (result.at(i) == "joke") {
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}

TEST(Test1, wordCounter) {
  std::string test_string {"Hello world, Hello cpp!"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i).first == "hello") {
      EXPECT_EQ(result.at(i).second, 2);
    } else if (result.at(i).first == "world") {
      EXPECT_EQ(result.at(i).second, 1);
    } else if (result.at(i).first == "cpp") {
      EXPECT_EQ(result.at(i).second, 1);
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 3);
}

TEST(Test2, wordCounter) {
  std::string test_string {"My. friend, ,IS! my FRIEND MY!"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i).first == "friend") {
      EXPECT_EQ(result.at(i).second, 2);
    } else if (result.at(i).first == "is") {
      EXPECT_EQ(result.at(i).second, 1);
    } else if (result.at(i).first == "my") {
      EXPECT_EQ(result.at(i).second, 3);
    } else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 3);
}

TEST(Test3, wordCounter) {
  std::string test_string {"Who is it? It is joke."};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  for (size_t i = 0; i < 4; ++i) {
    if (result.at(i).first == "who") {
      EXPECT_EQ(result.at(i).second, 1);
    } else if (result.at(i).first == "is") {
      EXPECT_EQ(result.at(i).second, 2);
    } else if (result.at(i).first == "it") {
      EXPECT_EQ(result.at(i).second, 2);
    }else if (result.at(i).first == "joke") {
      EXPECT_EQ(result.at(i).second, 1);
    }else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}

TEST(Test4, wordCounter) {
  std::string test_string {"Who is it? ...  It is joke."};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  for (size_t i = 0; i < 4; ++i) {
    if (result.at(i).first == "who") {
      EXPECT_EQ(result.at(i).second, 1);
    } else if (result.at(i).first == "is") {
      EXPECT_EQ(result.at(i).second, 2);
    } else if (result.at(i).first == "it") {
      EXPECT_EQ(result.at(i).second, 2);
    }else if (result.at(i).first == "joke") {
      EXPECT_EQ(result.at(i).second, 1);
    }else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}

TEST(Test5, wordCounter) {
  std::string test_string {"  some   WORDS for  SOME words  FOR  some JoKe"};
  std::vector<std::pair<std::string, size_t>> result{wordCounter(test_string)};
  for (size_t i = 0; i < 3; ++i) {
    if (result.at(i).first == "some") {
      EXPECT_EQ(result.at(i).second, 3);
    } else if (result.at(i).first == "words") {
      EXPECT_EQ(result.at(i).second, 2);
    } else if (result.at(i).first == "for") {
      EXPECT_EQ(result.at(i).second, 2);
    }else if (result.at(i).first == "joke") {
      EXPECT_EQ(result.at(i).second, 1);
    }else {
      EXPECT_EQ("we have problem","");
    }
  }
  EXPECT_EQ(result.size(), 4);
}
