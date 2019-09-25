#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> combineVectors (const std::vector<int>::iterator begin_1, const std::vector<int>::iterator end_1,
                                 const std::vector<int>::iterator begin_2, const std::vector<int>::iterator end_2) {
  std::vector<int> vector_result {};
  vector_result.insert(vector_result.end(), std::make_move_iterator(begin_1), std::make_move_iterator(end_1));
  vector_result.insert(vector_result.end(), std::make_move_iterator(begin_2), std::make_move_iterator(end_2));
  std::cout << "Combined vector: ";
  for (auto vec : vector_result) {
      std::cout << vec << " ";
    }
  return vector_result;
}

int main() {
  std::cout << "Vector 1: ";
  std::vector<int> vector1 {1, 2, 3, 4};
  for (auto vec1 : vector1) {
      std::cout << vec1 << " ";
    }
  std::cout << std::endl << "Vector 2: ";
  std::vector<int> vector2 {5, 6, 7, 8};
  for (auto vec2 : vector2) {
      std::cout << vec2 << " ";
    }
  std::cout << std::endl;
  combineVectors (vector1.begin(), vector1.end(), vector2.begin(), vector2.end());

  return 0;
}
