#ifndef FORFILEDIRECTORY_H
#define FORFILEDIRECTORY_H
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <string>
#include <map>


class Key_Equal_my
{
public:
    bool operator()(const std::string& fileName1, const std::string& fileName2) const;

};

class Hash_my
{
public:
    std::size_t operator() (std::string const& key) const;

};

void iterateDirectory(std::string path);



#endif // FORFILEDIRECTORY_H
