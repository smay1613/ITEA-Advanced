#include <vector>
#include <iostream>
#include <list>
#include <forward_list>

//task_1
std::vector<int> concat (const std::vector<int> &vector_1, const std::vector<int> &vector_2)
{
    //std::vector<int> tmp_vector {vector_1};
    //tmp_vector.insert(tmp_vector.end(), vector_2.begin(), vector_2.end());

    std::vector<int> tmp_vector{};
    tmp_vector.insert(tmp_vector.end(), vector_1.begin(), vector_1.end());
    tmp_vector.insert(tmp_vector.end(), vector_2.begin(), vector_2.end());

    return tmp_vector;
}

//task_2
std::list<int> Mylist (const int N, const int X)
{
    std::list<int> tmp_list {};
    int number {1};
    int first_number {0};
    int last_number {0};
    for(int i = 0; i < X; ++i)
    {
        number *= N;
        first_number = number;
        last_number = number % 10;

        while(first_number >= 10)
        {
            first_number /= 10;
        }
        tmp_list.push_back(first_number);
        tmp_list.push_back(last_number);
    }
    return tmp_list;
}

//tast_3
std::forward_list<int> reverse_forward_list (const std::forward_list<int> &forward_list)
{
    std::forward_list<int> tmp_forward_list {};
    for(const auto &i : forward_list)
    {
        tmp_forward_list.push_front(i);
    }
    return tmp_forward_list;
}
