#include <iostream>
#include <vector>

std::vector<int> combineVectors (const std::vector<int>::iterator Vector1BeginIterator,
                                 const std::vector<int>::iterator Vector1EndIterator,
                                 const std::vector<int>::iterator Vector2BeginIterator,
                                 const std::vector<int>::iterator Vector2EndIterator) {
  if ((Vector1BeginIterator == Vector1EndIterator) && (Vector2BeginIterator == Vector2EndIterator)) {
    return std::vector<int> {};
  }
  if (Vector1BeginIterator == Vector1EndIterator) {
    return std::vector<int> {Vector2BeginIterator,Vector2EndIterator};
  }
  if (Vector2BeginIterator == Vector2EndIterator) {
    return std::vector<int> {Vector1BeginIterator,Vector1EndIterator};
  }
  std::vector<int> Output{Vector1BeginIterator,Vector1EndIterator};
  uint32_t i = 0;
  while ((Vector2BeginIterator + i) != Vector2EndIterator) {
    Output.emplace_back(*(Vector2BeginIterator + i));
    ++i;
  }
  return Output;
}
