#include "vec_test.h"
#include "vectorUnion.h"

TEST_F(UnionTest, ConcatVectorTrue) {

  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {6, 7, 8, 9, 10};
  std::vector<int> result = vectorUnion(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
  std::vector<int> expected_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  EXPECT_EQ(expected_vector, result);
}

TEST_F(UnionTest, VectorIsNotEmpty) {

  std::vector<int> vector1 {1, 2, 3, 4, 5};
  std::vector<int> vector2 {6, 7, 8, 9, 10};
  std::vector<int> result = vectorUnion(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_FALSE(result.empty());

}

TEST_F (UnionTest, EmptyVectors) {

  std::vector<int> vector1 {};
  std::vector<int> vector2 {};
  std::vector<int> result = vectorUnion(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_EQ(result.size(), 0);
}

TEST_F(UnionTest, ConcatVectorFalse) {

  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {6, 7, 8, 9, 10};
  std::vector<int> result = vectorUnion(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
  std::vector<int> expected_vector = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  EXPECT_FALSE(expected_vector == result);
}

TEST_F(UnionTest, EqualVectorsSize) {
  std::vector<int> vector1 = {1, 2, 3, 4, 5};
  std::vector<int> vector2 = {157};
  std::vector<int> result = vectorUnion(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  EXPECT_EQ((vector1.size() + vector2.size()) , result.size());
}


