#include <iostream>
#include <filesystem>
#include <unordered_set>
#include <map>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

class Hasher {
public:
  size_t operator() (const std::pair<uintmax_t, std::string>& file) const {
    return static_cast<size_t>(file.first);
  }
};

class Equality {
public:
  bool operator() (const std::pair<uintmax_t, std::string>& lhsPath, const std::pair<uintmax_t, std::string>& rhsPath) const {
    std::ifstream fin1 (lhsPath.second, std::ios::binary);
    std::ifstream fin2 (rhsPath.second, std::ios::binary);
    char ch1, ch2;
    while ((fin1 >> ch1) && (fin2 >> ch2)) {
      if (ch1 != ch2) {
        return false;
      }
    }
    if ((fin2 >> ch2) || (fin1 >> ch1)) {
      return false;
    }
    return true;
  }
};


int main () {
  std::string path {};
  std::string delimiter { "=====================================================" };
  std::cout << "Please enter absolute or relative path" << std::endl;
  std::cin >> path;
  std::multimap<uintmax_t, std::string> sortedBySize;
  for (const auto& entry : fs::recursive_directory_iterator(path)) {
    if (!fs::is_directory (entry)) {
      sortedBySize.emplace(entry.file_size(),entry.path().string());
    }
  }
  std::unordered_set<std::pair<uintmax_t, std::string>, Hasher, Equality> uniq_set;
  double loadFactor {0.7};
  uniq_set.max_load_factor(loadFactor);
  uniq_set.reserve(sortedBySize.size());
  uniq_set.emplace (*sortedBySize.begin());
  std::cout << "List of folders:" << std::endl;
  std::vector<std::string> resultVector;
  bool onlyOneObject = false;
  for (const auto& file : sortedBySize) {
    std::pair<std::unordered_set<std::pair<uintmax_t, std::string>, Hasher, Equality>::iterator, bool> pairForUnordered {uniq_set.emplace(file)};
    if (pairForUnordered.second) {
      if (onlyOneObject) {
        resultVector.pop_back ();
        resultVector.pop_back ();
      }
      onlyOneObject = true;
      resultVector.emplace_back(delimiter);
      resultVector.emplace_back (file.second);
    } else {
      resultVector.emplace_back(file.second);
      onlyOneObject = false;
    }
  }
  if (*(++resultVector.rbegin ()) == delimiter) {
    resultVector.pop_back();
    resultVector.pop_back();
  }
  for (const auto& outString : resultVector) {
    std::cout << outString << std::endl;
  }
}
