#include <iostream>
#include <forward_list>

void EnterElements (std::forward_list<int>& MyForwardList) {
    for (std::forward_list<int>::iterator i = MyForwardList.begin(); i != MyForwardList.end(); ++i){
        std::cout << "Enter element №" << (*i)+1 << ":";
        std::cin >> *i;
    }
}

void ShowElements (std::forward_list<int>& MyForwardList) {
    for(std::forward_list<int>::iterator i = MyForwardList.begin(); i != MyForwardList.end(); ++i){
        std::cout << *i << " ";
    }
}

void ReverseElements (std::forward_list<int>& MyForwardList, std::forward_list<int>& MyNewForwardList) {
    for(std::forward_list<int>::iterator i = MyForwardList.begin(); i != MyForwardList.end(); ++i) {
        MyNewForwardList.push_front(*i);
    }
}
