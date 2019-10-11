#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "main.cpp"

using ::testing::Return;
using ::testing::_;

TEST(uniqueWordsTest1, getUniqueWords) {
    EXPECT_EQ(getUniqueWords("Hello world, HELLO cpp!"), ("hello cpp world"));
}

TEST(uniqueWordsTest2, getUniqueWords) {
  EXPECT_EQ(isExpressionValid("You said that you said it"), ("you said that it"));
}

TEST(uniqueWordsTest3, getUniqueWords) {
  EXPECT_EQ(isExpressionValid("What it's about? what?"), ("what it's about"));
}

TEST(uniqueWordsTest4, getUniqueWords) {
  EXPECT_EQ(isExpressionValid("Hello, my name is hello!"), ("hello my name is"));
}

TEST(uniqueWordsTest5, getUniqueWords) {
  EXPECT_EQ(isExpressionValid("Test test for testing of test!!!!!!!"), ("test for testing of"));
}
