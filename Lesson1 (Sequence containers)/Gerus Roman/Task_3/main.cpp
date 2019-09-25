#include <iostream>
#include <forward_list>

void reverse(std::forward_list<int>& listToReverse) {
  std::forward_list<int> modifiedListToReverse {};

  for (std::forward_list<int>::iterator it = listToReverse.begin(); it != listToReverse.end(); ++it) {
      modifiedListToReverse.insert_after(modifiedListToReverse.before_begin(), *it);
    }
  std::cout << "Reversed forward_list: ";
  for (auto i : modifiedListToReverse) {
      std::cout << i << " ";
    }
}

int main()
{
  std::forward_list<int> fList {1, 2, 3, 4, 5, 9, 45, 13, 64, 53};
  std::cout << "Original forward_list: ";
  for (auto i : fList) {
      std::cout << i << " ";
    }
  std::cout << std::endl;
  reverse(fList);
  return 0;
}

