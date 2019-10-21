#include <iostream>
#include <filesystem>
#include <unordered_set>
#include <map>
#include <fstream>
#include <vector>
#include <iterator>

namespace fs = std::filesystem;

class Hasher {
public:
  size_t operator() (const std::string& filePath) const {
    size_t hashValue {0};
    std::ifstream file (filePath, std::ios::binary);
    char symbol;
    while (file >> symbol) {
      hashValue <<= 1;
      hashValue ^= symbol;
    }
    return hashValue;
  }
};

class Equality {
public:
  bool operator() (const std::string& lhsPath, const std::string& rhsPath) const {
    std::ifstream file1 (lhsPath, std::ios::binary);
    std::ifstream file2 (rhsPath, std::ios::binary);
    size_t lhsSize = std::distance(std::istream_iterator<char> (file1),
                                   std::istream_iterator<char> ());
    size_t rhsSize = std::distance (std::istream_iterator<char> (file2),
                                    std::istream_iterator<char> ());
    if (lhsSize != rhsSize) {
      file1.close();
      file2.close ();
      return false;
    }
    if (std::equal(std::istream_iterator<char>(file1),
                   std::istream_iterator<char>(),
                   std::istream_iterator<char> (file2))) {
      file1.close ();
      file2.close ();
      return true;
    }
    file1.close ();
    file2.close ();
    return false;
  }
};


int main (int argc, char** argv) {
  std::string path{};
  if (argc > 1) {
    path.append(argv[1]);
  }
  std::string delimiter { "=====================================================" };
  std::multimap<uintmax_t, std::string> sortedBySize;
  for (const auto& entry : fs::recursive_directory_iterator(path)) {
    if (!fs::is_directory (entry)) {
      sortedBySize.emplace(entry.file_size(),entry.path().string());
    }
  }
  std::unordered_set<std::string, Hasher, Equality> uniq_set;
  uniq_set.reserve(sortedBySize.size());
  std::multimap<std::string,std::vector<std::string>> result;
  std::cout << "List of files:" << std::endl;
  for (const auto& file : sortedBySize) {
    std::pair<std::unordered_set<std::string, Hasher, Equality>::iterator, bool> pairForUnordered {uniq_set.emplace(file.second)};
    if (pairForUnordered.second) {
      result.emplace(*pairForUnordered.first, std::vector<std::string> {*pairForUnordered.first});
    } else {
      auto IteratorMultiMap = result.find (*pairForUnordered.first);
      IteratorMultiMap->second.push_back(file.second);
    }
  }
  for (const auto& vectors : result) {
    if (vectors.second.size() > 1) {
      for (const auto& strings : vectors.second) {
        std::cout << strings << std::endl;
      }
      std::cout << delimiter << std::endl;
    }
  }
}
