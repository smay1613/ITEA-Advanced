#include "magicNumber.h"
#include <cmath>

size_t magicNumber(const size_t inputNumber, const size_t degree) {
  std::list<size_t> resultList {};
  size_t calcResult = 0, lastDigit = 0, firstDigit = 0;

  for (size_t counter = 1; counter <= degree; ++counter) {
    calcResult = static_cast<size_t>(pow(inputNumber, counter)) ;
    lastDigit = calcResult % 10;
    while (calcResult) {
      firstDigit = calcResult % 10;
      calcResult /= 10;
    }
    resultList.push_back(firstDigit);
    resultList.push_back(lastDigit);
  }

  size_t result {};

  for (const size_t& elements : resultList) {
         result = result * 10 + elements;
     }

  return result;
}

