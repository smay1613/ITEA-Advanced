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



std::stringstream& operator>>(std::stringstream& input, std::string& output)
{
    int maxByteSize = 10000;
    char* mas = new char[maxByteSize];
    input.get(mas, 4);
    output = mas;
    delete [] mas;
    return input;
}

size_t myString::myHash(std::string inputString)
{
    std::hash<std::string> hashFunk;
    size_t hashValue = hashFunk(inputString);
    return hashValue;
}


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
    std::fstream file1(key);
    std::stringstream streamFile;
    copy(std::istreambuf_iterator<char>(file1),
         std::istreambuf_iterator<char>(),
         std::ostreambuf_iterator<char>(streamFile));
    std::vector<std::size_t> vectorOfHash;
    while(streamFile.tellg() != -1)
    {
        myString m;
        streamFile >> m;
        vectorOfHash.push_back(m.myHash(m));
    }
    std::size_t hashValue{0};
    for(auto& element: vectorOfHash)
    {
        hashValue = hashValue ^ element;
    }
    return hashValue;
}


void iterateDirectory(std::string path)
{
    std::unordered_map<std::string, std::vector<std::string>, Hash_my, Key_Equal_my> mapOfFiles;
    for (const auto & entry : fs::recursive_directory_iterator(path))
    {
        std::string p = entry.path();
        if(!fs::is_regular_file(p))
        {
            continue;
        }
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
            std::cout << " ";
        }
        std::cout << std::endl << "==========" << std::endl;
    }
}
