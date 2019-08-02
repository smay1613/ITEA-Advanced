#include "listReverse_test.h"
#include "listReverse.h"

TEST_F(listReverseTest, TrueReverse) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  std::forward_list<int> expectResult {4, 3, 2, 1};
  listReverse(inputList);

  EXPECT_EQ(inputList, expectResult);

}

TEST_F(listReverseTest, FalseReverse) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  std::forward_list<int> expectResult {4, 3, 2, 1, 1, 2, 3 , 4};
  listReverse(inputList);

  EXPECT_FALSE(inputList == expectResult);
}

TEST_F(listReverseTest, NoChanges) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  listReverse(inputList);
  std::forward_list<int> expectResult {1, 2, 3, 4};

  EXPECT_FALSE(inputList == expectResult);
}

TEST_F(listReverseTest, FunctionSizeBug) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  listReverse(inputList);
  std::forward_list<int> expectResult {4, 4, 3, 2, 1};

  EXPECT_FALSE(inputList.max_size() != expectResult.max_size());
}

TEST_F(listReverseTest, CleaningAfterCallingFunction) {
  std::forward_list<int> inputList {1, 2, 3, 4};
  listReverse(inputList);

  EXPECT_TRUE(!(inputList.empty()));
}

