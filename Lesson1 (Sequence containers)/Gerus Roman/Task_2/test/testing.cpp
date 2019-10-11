#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "main.cpp"

using ::testing::Return;
using ::testing::_;

TEST(wordCounterTest1, wordCounter) {
    EXPECT_EQ(isExpressionValid("Hello world, HELLO cpp!"), ({"hello", 2}, {"cpp", 1}, {"world", 1}));
}

TEST(wordCounterTest2, wordCounter) {
  EXPECT_EQ(isExpressionValid("You said that you said it"), ({"you", 2}, {"said", 2}, {"that", 1}, {"it", 1}));
}

TEST(wordCounterTest3, wordCounter) {
  EXPECT_EQ(isExpressionValid("What it's about? what?"), ({"what", 2}, {"it's", 1}, {"about", 1}));
}

TEST(wordCounterTest4, wordCounter) {
  EXPECT_EQ(isExpressionValid("Hello, my name is hello!"), ({"hello", 2}, {"my", 1}, {"name", 1}, {"is", 1}));
}

TEST(wordCounterTest5, wordCounter) {
  EXPECT_EQ(isExpressionValid("Test test for testing of test!!!!!!!"), ({"test", 3}, {"for", 1}, {"testing", 1}, {"of", 1}));
}
