#include <iostream>
#include <forward_list>


template <typename type> void print_forward_list(std::forward_list<type> &value)
{
    for (const auto& element : value)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


template <typename type> void reverse_forward_list(std::forward_list<type> &value)
{
    std::forward_list<type> value2;
    for (const auto& element : value)
    {
        value2.push_front(element);
    }
    value2.swap(value);
}



int main()
{
    std::forward_list<int> data { 1, 2, 3, 4, 5 };

    print_forward_list(data);

    reverse_forward_list(data);

    print_forward_list(data);

    return 0;
}
