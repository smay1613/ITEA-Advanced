#include <iostream>
#include <forward_list>

#include "HT1_3head.hpp"

template <typename T>
void ShowElements ( std::forward_list <T> const & MyForwardList) {
    std::cout << "My forward list is: [ ";
    for(auto i : MyForwardList){
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void ReverseElements (std::forward_list <T> & MyForwardList) {
    std::forward_list <T> MyForwardList_copy = MyForwardList;
    MyForwardList.clear();
    for (auto element : MyForwardList_copy){
        MyForwardList.push_front(element);
    }
}

int main()
{
    std::forward_list<int> MyForwardList{1, 2, 3, 4, 5};

    ShowElements(MyForwardList);

    ReverseElements(MyForwardList);

    ShowElements(MyForwardList);

    return 0;
}
