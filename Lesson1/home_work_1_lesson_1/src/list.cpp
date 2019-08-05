#include <../include/functions.h>
#include <cmath>
#include <list>

namespace functions
{
//TASK _ 2
size_t magic_number(const size_t N, const size_t X) {

    std::list<size_t> tmp_list {};

    size_t number {1};
    size_t first_number {0};
    size_t last_number {0};

    for(size_t i = 0; i < X; ++i)
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

    size_t result {};

    for (const auto &i : tmp_list)
    {
        result = result * 10 + i;
    }

    return result;
}
}//namespace functions
