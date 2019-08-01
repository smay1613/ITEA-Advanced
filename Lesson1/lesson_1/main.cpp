#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include "functions.h"

//print function
template <typename Container>
void print(const Container &container)
{
    for(auto i = container.begin(); i != container.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    //task_1
    std::cout << "task _ 1 -------------------------------------------- " << std::endl;
    std::vector<int> vec_1 { 1 , 2 , 3 , 4 , 5 };
    std::vector<int> vec_2 { 6 , 7 , 8 , 9 , 10 };
    std::vector<int> vec_3 = concat(vec_1, vec_2);
    std::cout << "result : ";
    print(vec_3);
    std::cout << std::endl;

    //task_2
    std::cout << "task _ 2 -------------------------------------------- " << std::endl;
    int N { 0 };
    int X { 0 };
    std::cout << "Enter N : ";
    std::cin >> N;
    std::cout << "Enter X : ";
    std::cin >> X;
    std::list<int> list = Mylist(N, X);
    std::cout << "result : ";
    print(list);
    std::cout << std::endl;

    //task _ 3
    std::cout << "task _ 3 -------------------------------------------- " << std::endl;
    std::forward_list<int> forward_list { 1 , 2 , 3 , 4 , 5 };
    std::forward_list<int> new_forward_list = reverse_forward_list(forward_list);
    std::cout << "result : ";
    print(new_forward_list);

    std::cout << "test" << std::endl;

    return 0;
}
