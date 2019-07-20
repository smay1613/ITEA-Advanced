#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int>myForvardList{10,20,30,40,50};
    std::forward_list<int>reverseForvardList;
    std::cout <<"myForvardList:\t\t";
    for(const auto &value: myForvardList){
        reverseForvardList.push_front(value);
        std::cout<< value <<" ";
        }
    std::cout << std::endl <<"reverseForvardList:\t";
    for(const auto &value: reverseForvardList){
        std::cout<< value << " ";
    }
    myForvardList = reverseForvardList;
    std::cout << std::endl <<"myForvardList: \t\t";
    for(const auto &value: myForvardList){
        std::cout<< value << " ";
    }

    return 0;
}
