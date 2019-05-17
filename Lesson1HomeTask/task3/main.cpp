#include <iostream>
#include <forward_list>
#include <vector>

template <typename T>
void print_list (const std::forward_list<T>& f_list)
{
    for (const auto& el : f_list)
    {
        std::cout << el << " ";
    }
}

template <typename T>
void reverse_list_1 (std::forward_list<T>& f_list)
{
    std::forward_list<T> tmp_flist;
    for (const auto& el : f_list)
    {
        tmp_flist.push_front (el);
    }
    f_list.swap(tmp_flist);
}


template <typename T>
void reverse_list_2 (std::forward_list<T>& f_list)
{
    using fw_list_it = typename std::forward_list<T>::iterator;

    std::vector<fw_list_it> f_list_iterators;

    for (fw_list_it it = f_list.begin(); it != f_list.end(); it++)
    {
        f_list_iterators.push_back (it);
    }

    const auto f_list_iterators_size = f_list_iterators.size();

    for (size_t i = 0; i < f_list_iterators_size/2; i++)
    {
        std::iter_swap( f_list_iterators[i],  f_list_iterators[f_list_iterators_size -1 - i]);
    }
}


template <typename T>
void run_test (std::forward_list<T>& f_list, void (*reverse_func)(std::forward_list<T>& f_list))
{
    std::cout << std::endl << "-----------------------------------------" << std::endl;
    std::cout << "Test:" << std::endl;

    std::cout << "List Before: ";
    print_list (f_list);
    std::cout << std::endl;

    std::forward_list<T> f_list_copy {f_list};

    reverse_func (f_list);

    std::cout << "List Reversed: ";
    print_list (f_list);
    std::cout << std::endl;

    f_list_copy.reverse();

    if (f_list == f_list_copy)
    {
        std::cout << "Reversing ok!";
    }
    else
    {
        std::cout << "REVERSING WRONG! Must be: ";
        print_list (f_list_copy);
    }

    std::cout << std::endl;
}


int main()
{
    std::forward_list<int> fl0 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int> fl1 {4, 99, 734, 1,  0, 845, 26, 79, 71};

    auto fl0_copy {fl0};
    auto fl1_copy {fl1};

    std::cout << std::endl << "=========================================" << std::endl;
    std::cout << "Testing with 'reverse_list_1' function..." << std::endl;
    run_test (fl0, reverse_list_1);
    run_test (fl1, reverse_list_1);

    std::cout << std::endl << "=========================================" << std::endl;
    std::cout << "Testing with 'reverse_list_2' function..." << std::endl;
    run_test (fl0_copy, reverse_list_2);
    run_test (fl1_copy, reverse_list_2);

    return 0;
}
