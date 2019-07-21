#include <vector>
#include <iostream>
#include <list>
#include <forward_list>


namespace functions
{
    //print vector
    void print_vector (const std::vector<int> vector)
    {
        for(auto &i : vector)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    //print list
    void print_list (const std::list<int> list)
    {
        for(auto &i : list)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    //print forward_list
    void print_forward_list (const std::forward_list<int> forward_list)
    {
        for(auto &i : forward_list)
        {
            std::cout << i;
        }
        std::cout << std::endl;
    }

    //task_1
    std::vector<int> concat (const std::vector<int> vector_1, const std::vector<int> vector_2)
    {
        std::vector<int> tmp_vector {vector_1};
        tmp_vector.insert(tmp_vector.end(), vector_2.begin(), vector_2.end());
        return tmp_vector;
    }

    //task_2
    std::list<int> list (const int &N, const int &X)
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
            tmp_list.emplace_back(first_number * 10 + last_number);
        }
        return tmp_list;
    }

    //tast_3
    std::forward_list<int> reverse_forward_list (const std::forward_list<int> forward_list)
    {
        std::forward_list<int> tmp_forward_list {};
        for(auto &i : forward_list)
        {
            tmp_forward_list.push_front(i);
        }
        return tmp_forward_list;
    }
}//namespace functions
