#include <iostream>
#include <forward_list>

#include "ht1_3head.h"
#include "ht1_3lib.cpp"

int main()
{
    size_t sz;
    std::cout << "Enter size of forvard list: ";
    std::cin >> sz;
    std::forward_list<int> MyForwardList(sz);
    EnterElements(MyForwardList);
    std::cout << "My forward list is: [ ";
    ShowElements(MyForwardList);
    std::cout << "]" << std::endl;

    std::forward_list<int> MyNewForwardList;
    ReverseElements(MyForwardList, MyNewForwardList);
    std::cout << "The revers of my forward list is [ ";
    ShowElements(MyNewForwardList);
    std::cout << "]" << std::endl;

    return 0;
}
