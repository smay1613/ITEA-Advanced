#include "functions.h"

int task2() // -----LIST-----
{
    int x{10};
    int y{5};
    int a{19};
    int b{4};
    std::vector<int> vect_1(5);
    std::vector<int> vect_2(4);
    std::vector<int> vect_3{};
    std::list<int> list_1;
    std::list<int> list_2;
    MFun::power(x,y,vect_1);
    std::cout << "vector 1" << std::endl;
    MFun::print_vect(vect_1);
    MFun::power(a,b,vect_2);
    std::cout << "vector 2" << std::endl;
    MFun::print_vect(vect_2);
    for (size_t i{0}; i < vect_1.size(); ++i){
        int k = MFun::divide_first(vect_1[i]);
        vect_3.emplace_back(k);
        int j = MFun::divide_last(vect_1[i]);
        vect_3.emplace_back(j);
    }
    std::cout << "vector 3" <<std::endl;
    MFun::print_vect(vect_3);
    MFun::fill_list(list_1,vect_3);
    std::cout << "List 1" << std::endl;
    MFun::showlist_z(list_1);
    while (!vect_3.empty()){
            vect_3.pop_back();
    }
    for (size_t i{0}; i < vect_2.size(); ++i){
        int k = MFun::divide_first(vect_2[i]);
        vect_3.push_back(k);
        int j = MFun::divide_last(vect_2[i]);
        vect_3.push_back(j);
    }
    std::cout << "vect_3" <<std::endl;
    MFun::print_vect(vect_3);
    MFun::fill_list(list_2,vect_3);
    std::cout << "List 2" << std::endl;
    MFun::showlist_z(list_2);
    return 0;
}
