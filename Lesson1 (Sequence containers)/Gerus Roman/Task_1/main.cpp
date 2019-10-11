#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>


std::string transformToLowerCase (std::string stringToTransform) {
  std::transform (stringToTransform.begin(), stringToTransform.end(), stringToTransform.begin(), ::tolower);
  return stringToTransform;
}

std::vector<std::string> getUniqueWords (const std::string& text) {
  std::set<std::string> mySet {};
  std::stringstream streamText {text};
  std::string temp_string {};

  while (streamText >> temp_string) {
      temp_string.erase(std::remove_if(temp_string.begin(), temp_string.end(), ispunct), temp_string.end());
      mySet.insert(transformToLowerCase(temp_string));
    }

  std::vector<std::string> uniqueWords {mySet.begin(), mySet.end()};

  for (const auto& temp : uniqueWords) {
      std::cout << temp << " ";
    }
  return uniqueWords;
}

int main()
{

  return 0;
}
