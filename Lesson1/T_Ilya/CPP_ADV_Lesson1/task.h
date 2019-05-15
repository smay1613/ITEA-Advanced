#pragma once
#include <vector>
#include <iostream>
#include <list>

namespace MySpace{
using ull = unsigned long long;

void print_vect(std::vector<int> a_vect){
    for(ull i{0}; i < a_vect.size(); i++){
        std::cout << a_vect[i] << " , ";
    }std::cout << std::endl;

}
void showlist(std::list <int> list_n){
    std::list <int> :: iterator it;
    for(it = list_n.begin(); it != list_n.end(); ++it){
        std::cout << '\t' << *it;
        std::cout << std::endl;
    }

}
int task1();
int task2();
int task3();


} // namespace MySpace
