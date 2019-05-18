#include "task.h"



void print_vect(std::vector<int> a_vect){
    for(MySpace::ull i{0}; i < a_vect.size(); i++){
        std::cout << a_vect[i] << " , ";
    }std::cout << std::endl;

}

int task1() //  -----VECTOR-----
{
    std::vector<int> vect_1{};
    std::vector<int> vect_2{};
    for(auto i{0}; i < 10; i++){
        vect_1.push_back(i);
        vect_2.push_back(i);
    }
    std::cout << "Vector 1:" << std::endl;
    print_vect(vect_1);
    std::cout << "Vector 2:" << std::endl;
    print_vect(vect_2);
    std::vector<int> vect_result{};
    vect_result.insert(vect_result.end(), vect_1.begin(), vect_1.end());
    std::cout << "Vector 3+1:" << std::endl;
    print_vect(vect_result);
    vect_result.insert(vect_result.end(), vect_2.begin(), vect_2.end());
    std::cout << "Vector 3+2:" << std::endl;
    print_vect(vect_result);
    return 0;
}
//} //namespace MySpace
