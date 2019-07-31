#pragma once
#include <string>
#include <chrono>
#include <forward_list>
#include <vector>




namespace avprocessing
{
namespace utilities
{
    void reverse(std::forward_list<int> & m_ForvardList);
    std::vector<int> combineVectors(std::vector<int> firstVec, std::vector<int> secondVec);
    std::vector<int> combineVectors(const std::vector<int>::iterator vectorFirstBegin, const std::vector<int>::iterator vectorFirstEnd,
                                    const std::vector<int>::iterator vectorSecondBegin, const std::vector<int>::iterator vectorSecondEnd);
    size_t magicNumber(const size_t  m_number, const size_t  m_degree);
}
}
