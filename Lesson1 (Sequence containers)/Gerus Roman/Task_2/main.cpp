#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <functional>
#include <algorithm>


std::string transformToLowerCase (std::string stringToTransform) {
  std::transform (stringToTransform.begin(), stringToTransform.end(), stringToTransform.begin(), ::tolower);
  return stringToTransform;
}

std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text) {
  std::map<std::string, size_t> myMap {};
  std::stringstream streamText {text};
  std::string temp_string {};

  while (streamText >> temp_string) {
      temp_string.erase(std::remove_if(temp_string.begin(), temp_string.end(), ispunct), temp_string.end());
      std::map<std::string, size_t>::iterator search {myMap.find(transformToLowerCase(temp_string))};

      if (search == myMap.end()) {
          myMap.emplace(transformToLowerCase(temp_string), 1);
        } else {
          ++search->second;
        }
    }

  std::vector<std::pair<std::string, size_t>> uniqueWords {myMap.begin(), myMap.end()};
}
int main()
{
  return 0;
}
