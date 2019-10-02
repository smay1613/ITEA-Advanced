#include <set>
#include <map>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

std::string str_tolower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c){ return std::tolower(c);});
  return s;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string & text) {
  std::map<std::string, size_t> uniqueWordsMap;
  std::vector<std::pair<std::string, size_t>> OutWords;
  std::stringstream full_string{text};
  std::string word;
  while(full_string >> word) {
    word.erase(std::remove_if(word.begin(), word.end(), std::function<bool(char)>(ispunct)),
              word.end());
    if (word.size() == 0) {
      continue;
    }
    std::map<std::string, size_t>::iterator it = uniqueWordsMap.find(str_tolower(word));
    if (it == uniqueWordsMap.end()) {
      uniqueWordsMap.emplace(std::pair{str_tolower(word), 1});
    } else {
      ++(it->second);
    }
  }
  for (const auto& pair : uniqueWordsMap) {
    OutWords.push_back(pair);
  }
  return OutWords;
}
