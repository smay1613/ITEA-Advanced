#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <experimental/filesystem>
#include <algorithm>

namespace fs = std::experimental::filesystem;

struct compareTwoFiles{
    bool operator()(const std::string& lhs, const std::string& rhs) const
    {
        std::ifstream lhsFile(lhs, std::ifstream::binary);
        std::ifstream rhsFile(rhs, std::ifstream::binary);

        if(lhsFile.is_open() == false  || rhsFile.is_open() == false)
        {
            return false;
        }

        return  std::equal(std::istream_iterator<std::string>(lhsFile),
                           std::istream_iterator<std::string>(),
                           std::istream_iterator<std::string>(rhsFile));
    }
};

struct hashFunc{
    size_t operator()(const std::string& key) const
    {
        size_t hash {0};

        return hash;
    }
};

std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoFiles>
checkAllFiles(const std::vector<fs::path>& filesVector)
{
    std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoFiles> map;

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
        return fs::is_regular_file(file_path);
    }
};

std::vector<fs::path> findAllFiles(const std::string& absPath)
{
    std::vector<fs::path> directories {absPath};
    std::vector<fs::path> txtFiles;

    for(const auto& directory : directories)
    {
        fs::recursive_directory_iterator begin{directory};
        fs::recursive_directory_iterator end{};

        std::copy_if(begin, end, std::back_inserter(txtFiles), isRegularFIle());
    }

    return txtFiles;
}

void printAllFiles(const std::unordered_map<std::string, std::vector<std::string>, hashFunc, compareTwoFiles>& map)
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
