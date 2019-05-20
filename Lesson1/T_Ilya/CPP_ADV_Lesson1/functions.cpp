#include "functions.h"
#include "task.h"

namespace MFun{
void print_vect(std::vector<int>& a_vect){
    for(const int& value: a_vect){
        std::cout << value << " , ";
    }
    std::cout << std::endl;

}
int divide_first(int x){
    while(x >= 10){
        x /= 10;
    }
    return x;
}
int divide_last(int y){
    return (y % 10);

}
void power(int c, int d, std::vector<int>& vect_c){
    int r{1};
    for (auto i{0}; i < d; ++i){
        r *= c;
        vect_c.emplace_back(r);
    }
}
void print_vect_b(const std::vector<int>& vect_c){
    for(const int& value: vect_c)
    {
        std::cout << value << " , ";
    }
    std::cout << std::endl;
}
void showlist_z(std::list<int>& list_z){
    for(const auto& value: list_z)
    {
        std::cout << '\t' << value;
    }
    std::cout << std::endl;
}
void fill_list(std::list<int>& list_y, std::vector<int>& vect_y){
    list_y = std::list<int>(vect_y.cbegin(), vect_y.cend());
}
void showlist_fwd(std::forward_list<int>& list_n)
{
    for(const auto& value: list_n){
        std::cout << '\t' << value;
    }
    std::cout << std::endl;
}
void print_vect_a(std::vector<int>& a_vect){
    for(const int& value: a_vect){
        std::cout << value << " , ";
    }
    std::cout << std::endl;

}
} // namespace MFun
