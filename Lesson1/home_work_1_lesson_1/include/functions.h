#pragma once
#include <vector>
#include <forward_list>

namespace functions
{
//TASK _ 1
std::vector<int> concat (const std::vector<int>::iterator vec_1_begin, const std::vector<int>::iterator vec_1_end,
                        const std::vector<int>::iterator vec_2_begin, const std::vector<int>::iterator vec_2_end);

//TASK _ 2
size_t magic_number(const size_t  N, const size_t  X);

//TASK _ 3
void reverse (std::forward_list<int> & forward_list);
}
