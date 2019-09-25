#include <iostream>
#include <list>
#include <math.h>

size_t magicNumber(const size_t number, const size_t degree) {
  std::list<int> list {};

  for (size_t i = 1; i <= degree; ++i) {
    list.push_back(static_cast<int>(std::pow(number,i)));
    }
  ulong num = 0;
for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
    uint32_t temp_for_num = *it % 10;
    while (*it != 0) {
      *it /= 10;
      if (*it >= 1 && *it <= 9) {
          num = (num * 10) + *it % 10;
          num = (num * 10) + temp_for_num;
        }
    }
  }
return num;
}

int main()
{
  std::cout << "Enter number above 9 and any degree: ";
  size_t num, deg;
  std::cin >> num >> deg;
  if (num < 10) {
      std::cout << "You entered wrong number!" << std::endl;
      return 0;
    }

  std::cout << "Your final number: " << magicNumber(num, deg) << std::endl;
  return 0;
}
