#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "reverse.cpp"

using ::testing::Return;
using ::testing::_;

TEST(reverseTest1, reverse) {
  std::forward_list<int> test_list {1, 2, 3, 4, 5};
  std::forward_list<int> comp_list {1, 2, 3, 4, 5};
  reverse(test_list);
  comp_list.reverse();
  EXPECT_EQ(test_list,comp_list);
}

TEST(reverseTest2, reverse) {

}

TEST(reverseTest3, reverse) {

}

TEST(reverseTest4, reverse) {

}

TEST(reverseTest5, reverse) {

}
