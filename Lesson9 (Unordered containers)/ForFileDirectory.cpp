#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <string>
#include <map>
#include "ForFileDirectory.h"
namespace fs = std::experimental::filesystem;



bool Key_Equal_my::operator()(const std::string& fileName1, const std::string& fileName2) const
{
    std::ifstream file1(fileName1, std::ifstream::binary|std::ifstream::ate);
    std::ifstream file2(fileName2, std::ifstream::binary|std::ifstream::ate);


    if (file1.fail() || file2.fail())
    {
        return false;
    }
    file1.seekg(0, std::ifstream::beg);
    file2.seekg(0, std::ifstream::beg);
    std::istreambuf_iterator<char> eos;
    std::istreambuf_iterator<char> it1 (file1.rdbuf());
    std::istreambuf_iterator<char> it2 (file2.rdbuf());
    return std::equal(it1, eos, it2);
}

std::size_t Hash_my::operator() (std::string const& key) const
{
    std::size_t randomHash = 145;
    return randomHash;
}



void iterateDirectory(std::string path)
{
    std::unordered_map<std::string, std::vector<std::string>, Hash_my, Key_Equal_my> mapOfFiles;
    for (const auto & entry : fs::recursive_directory_iterator(path))
    {
        std::string p = entry.path();
        std::cout << p << std::endl;
        std::ifstream currentFile(entry.path());
        if(!fs::is_regular_file(p))
        {
            continue;
        }
        std::string str((std::istreambuf_iterator<char>(currentFile)),
                         std::istreambuf_iterator<char>());
        std::vector<std::string> v;
        auto it = mapOfFiles.insert(std::pair<std::string, std::vector<std::string>>(p,v));
        if (it.second == false)
        {
            it.first->second.push_back(p);
        }

    }

    for(auto el : mapOfFiles)
    {
        std::cout << el.first << " ";
        for(auto vectorElement : el.second)
        {
            std::cout << vectorElement;
        }
        std::cout << std::endl << "==========" << std::endl;
    }
}
