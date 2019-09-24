#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "magicNumber.cpp"

using ::testing::Return;
using ::testing::_;

TEST(magicNumberTest1, magicNumber) {
    EXPECT_EQ(magicNumber(10,5),1010101010);
}

TEST(magicNumberTest2, magicNumber) {
  EXPECT_EQ(magicNumber(19, 4), 19316911);
}

TEST(magicNumberTest3, magicNumber) {
  EXPECT_EQ(magicNumber(99, 4), 99919991);
}

TEST(magicNumberTest4, magicNumber) {
  EXPECT_EQ(magicNumber(999, 4), 99919991);
}

TEST(magicNumberTest5, magicNumber) {
  EXPECT_EQ(magicNumber(153, 2), 1329);
}
