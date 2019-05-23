#include "functions.h"

int task1() //  -----VECTOR-----
{
    unsigned long long v_size{10};
    std::vector<int> vect_1{};
    std::vector<int> vect_2{};
    for(size_t i{0}; i < v_size; ++i) {
        vect_1.emplace_back(i);
    }
    for(size_t i{0}; i < v_size; ++i) {
        vect_2.emplace_back(i);
    }
    std::cout << "Vector 1:" << std::endl;
    MFun::print_vect(vect_1);
    std::cout << "Vector 2:" << std::endl;
    MFun::print_vect(vect_2);
    std::vector<int> vect_result{};
    vect_result.insert(vect_result.end(), vect_1.begin(), vect_1.end());
    std::cout << "Vector 3+1:" << std::endl;
    MFun::print_vect(vect_result);
    vect_result.insert(vect_result.end(), vect_2.begin(), vect_2.end());
    std::cout << "Vector 3+2:" << std::endl;
    MFun::print_vect(vect_result);
    return 0;
}
