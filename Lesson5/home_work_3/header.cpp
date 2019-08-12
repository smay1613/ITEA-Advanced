#include "header.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>

void print(const std::vector<std::string> &container)
{
    for(const auto &i : container)
    {
        std::cout << " | " << i << " | ";
    }
}
void print(const std::vector<std::pair<std::string, size_t> > &container)
{
    for (const auto &i : container)
    {
        std::cout  << " | " << i.first << " | " << i.second << "  - repeats " << std::endl;;
    }
}

std::vector<std::string> getUniqueWords(const std::string& text)
{
    std::string word {};
    std::stringstream SString {text};
    std::set<std::string> resultSet;

    while (!SString.eof())
    {
        SString >> word;
        resultSet.insert(word);
    }
    std::vector<std::string> resultVector {resultSet.begin(), resultSet.end()};
    return resultVector;
}

std::vector<std::pair<std::string, size_t>> wordCounter(const std::string& text)
{
    std::string word {};
    std::stringstream SString {text};
    std::map<std::string, size_t> resultMap;

    while (std::getline(SString, word, ' '))
    {
        resultMap[word] = resultMap[word] + 1;
    }

    std::vector<std::pair<std::string, size_t>> resultVector {resultMap.begin(), resultMap.end()};

    return resultVector;
}
