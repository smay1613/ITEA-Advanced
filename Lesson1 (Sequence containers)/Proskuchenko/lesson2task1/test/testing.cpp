#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "isExpressionValid.cpp"

using ::testing::Return;
using ::testing::_;

TEST(isExpressionValidTest1, isExpressionValid) {
  EXPECT_EQ(isExpressionValid(""),true);
}

TEST(isExpressionValidTest2, isExpressionValid) {
  EXPECT_EQ(isExpressionValid(")([{}])("),false);
}

TEST(isExpressionValidTest3, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("({[]}))("),false);
}

TEST(isExpressionValidTest4, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("[]({[]})({})"),true);
}

TEST(isExpressionValidTest5, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("(((({{{{[[[["),false);
}
