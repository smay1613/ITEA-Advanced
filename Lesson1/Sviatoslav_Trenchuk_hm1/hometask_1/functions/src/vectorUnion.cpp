#include "vectorUnion.h"

std::vector<int> vectorUnion(const std::vector<int>::iterator firstVectorBeginIterator, const std::vector<int>::iterator firstVectorEndIterator,
                             const std::vector<int>::iterator secondVectorBeginIterator, const std::vector<int>::iterator secondVectorEndIterator) {

  std::vector<int> unitedVector {};

  unitedVector.insert(unitedVector.end(), firstVectorBeginIterator, firstVectorEndIterator);
  unitedVector.insert(unitedVector.end(), secondVectorBeginIterator, secondVectorEndIterator);

  return unitedVector;

}
