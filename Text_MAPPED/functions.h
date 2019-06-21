#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>


template <class T>
struct less_second : std::binary_function<T,T,bool>
{
    inline bool operator()( const T& lhs, const T& rhs )
    {
        return lhs.second.value < rhs.second.value;
    }
};

class WordCounter
{
public:
    int value;
    WordCounter() : value( 0 ) {}

    void operator++ (int) { value++; }
};

std::ostream& operator<<(std::ostream& st, WordCounter& wc )
{
    return st << wc.value;
}

// Remove unwanted characters from a string
bool filter(char c)
{
    return isalpha( c ) == 0;
}
