#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "combineVectors.cpp"

using ::testing::Return;
using ::testing::_;

TEST(combineVectorsTest1, combineVectors) {
  std::vector<int> firstVect {1, 2, 3};
  std::vector<int> secondVect {1, 2, 3};
  std::vector<int> Output_for_compare {1, 2, 3, 1, 2, 3};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest2, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {1, 2, 4};
  std::vector<int> Output_for_compare {1, 2, 4};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest3, combineVectors) {
  std::vector<int> firstVect {1, 2, 4};
  std::vector<int> secondVect {};
  std::vector<int> Output_for_compare {1, 2, 4};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest4, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {};
  std::vector<int> Output_for_compare {};
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}

TEST(combineVectorsTest5, combineVectors) {
  std::vector<int> firstVect {};
  std::vector<int> secondVect {};
  for (int i = 0; i < 1000; ++i) {
    firstVect.push_back(i);
    secondVect.push_back(i);
  }
  std::vector<int> Output_for_compare {};
  for (uint8_t j = 0; j < 2; ++j) {
    for (int i = 0; i < 1000; ++i) {
      Output_for_compare.push_back(i);
    }
  }
  std::vector<int> Output = combineVectors(firstVect.begin(),firstVect.end(),secondVect.begin(),secondVect.end());
  EXPECT_EQ(Output, Output_for_compare);
}
