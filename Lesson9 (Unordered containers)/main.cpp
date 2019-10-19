#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <algorithm>

#include "xxhash.hpp"

namespace fs = std::experimental::filesystem;

struct compareTwoKeys{
    bool operator()(const std::string& lhs, const std::string& rhs) const
    {
        return lhs != rhs;
    }
};

struct hashFunc{
    size_t operator()(const std::string& key) const
    {
        std::ifstream file(key, std::ifstream::binary);
        std::vector<char> fileVector;

        if(file.is_open() == false || file.fail() == true)
        {
            return false;
        }

        std::copy(std::istreambuf_iterator<char>(file),
                  std::istreambuf_iterator<char>(),
                  std::back_inserter(fileVector));

        xxh::hash_t<32> hash = xxh::xxhash<32>(fileVector);

        return hash;
    }
};

std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoKeys>
checkAllFiles(const std::vector<fs::path>& filesVector)
{
    std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoKeys> map;

    for(const auto& element : filesVector)
    {
        std::vector<std::string> a {element};
        auto it = map.insert({element, a});
        if(it.second == false)
        {
            it.first->second.push_back(element);
        }
    }

    return map;
}

struct isRegularFIle{
    bool operator()(const fs::path& file_path)
    {
        return fs::is_regular_file(file_path) && (file_path.extension() == ".txt" || file_path.extension() == ".bin");
    }
};

std::vector<fs::path> findAllFiles(const std::string& absPath)
{
    std::vector<fs::path> directories {absPath};
    std::vector<fs::path> Files;

    for(const auto& directory : directories)
    {
        fs::recursive_directory_iterator begin{directory};
        fs::recursive_directory_iterator end{};

        std::copy_if(begin, end, std::back_inserter(Files), isRegularFIle());
    }

    return Files;
}

void printAllFiles(const std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoKeys>& map)
{
    std::cout << "==========" << std::endl;

    for(const auto& allFiles : map)
    {
        if(allFiles.second.size() > 1)
        {
            for(const auto& equalFiles : allFiles.second)
            {
                std::cout << equalFiles << std::endl;
            }

            std::cout << "==========" << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    std::string PATH = argv[1];

    printAllFiles(checkAllFiles(findAllFiles(PATH)));

    return 0;
}
