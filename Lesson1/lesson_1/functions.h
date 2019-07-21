#pragma once
#include <vector>
#include <list>
#include <forward_list>

namespace functions
{
    //print vector
    void print_vector (const std::vector<int> vector);

    //print list
    void print_list (const std::list<int> list);

    //print forward_list
    void print_forward_list (const std::forward_list<int> forward_list);

    //task_1
    std::vector<int> concat (const std::vector<int> vector_1, const std::vector<int> vector_2);

    //task_2
    std::list<int> list (const int &N, const int &X);

    //task_3
    std::forward_list<int> reverse_forward_list (const std::forward_list<int> forward_list);

}//namespace functions
