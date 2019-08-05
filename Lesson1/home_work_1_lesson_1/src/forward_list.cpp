#include <../include/functions.h>
#include <forward_list>

namespace functions
{
//TASK _ 3
void reverse(std::forward_list<int> &forward_list)
{
    std::forward_list<int> tmp_forward_list {};

    for(const auto &i : forward_list)
    {
        tmp_forward_list.push_front(i);
    }

    forward_list.clear();
    forward_list.swap(tmp_forward_list);
}
}// namespace functions
