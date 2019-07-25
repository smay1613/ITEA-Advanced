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


template <typename type> void reverse_forward_list(std::forward_list<type> &values_1)
{
    std::forward_list<type> values_2;
    for (const auto& element : values_1)
    {
        values_2.push_front(element);
    }
    values_2.swap(values_1);
}



int main()
{
    std::forward_list<int> data { 1, 2, 3, 4, 5 };

    print_forward_list(data);

    reverse_forward_list(data);

    print_forward_list(data);

    return 0;
}
