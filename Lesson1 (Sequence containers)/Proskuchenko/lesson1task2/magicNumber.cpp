#include <iostream>
#include <list>
#include <cmath>

size_t magicNumber(const size_t number, const size_t degree){
  std::list<uint8_t> list_result;
  for (uint32_t i = 1; i <= degree; ++i) {
    unsigned number_of_digits = 0;
    uint64_t pow_number = static_cast<uint64_t>(pow(number,i));
    while(static_cast<unsigned>(pow_number / pow(10, number_of_digits))) {
      ++number_of_digits;
    }
    list_result.push_back(static_cast<uint8_t>(pow_number / static_cast<uint64_t>(pow(10, (number_of_digits - 1)))));
    list_result.push_back(pow_number % 10);
  }
  unsigned long result_size = list_result.size();
  unsigned long int_result = 0;
  for (unsigned long i = 0; i < result_size; ++i) {
    unsigned data = list_result.back();
    list_result.pop_back();
    int_result += static_cast<unsigned>(data * pow(10, i));
  }
  return int_result;
}
