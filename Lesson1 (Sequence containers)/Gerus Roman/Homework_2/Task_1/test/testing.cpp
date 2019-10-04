#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Brackets_valid.cpp"

using ::testing::Return;
using ::testing::_;

TEST(magicNumberTest1, isExpressionValid) {
    EXPECT_EQ(isExpressionValid("({})"), true);
}

TEST(magicNumberTest2, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("{]"), false);
}

TEST(magicNumberTest3, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("((()()))"), true);
}

TEST(magicNumberTest4, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("{(([]))}"), true);
}


TEST(magicNumberTest5, isExpressionValid) {
  EXPECT_EQ(isExpressionValid("[[[((){)]]]"), false);
}
