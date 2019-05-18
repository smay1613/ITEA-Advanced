#include "task.h"
#include <list>
#include <iterator>



int divide_first(int x){
    if(x >= 100000 && x < 1000000){
    int f{0};
    f = x / 10000 % 10;
    return f;
    }
    else if(x >= 10000 && x < 100000){
        int f{1};
        f = x / 1000 % 10;
        return f;
    }
    else if(x >= 1000 && x < 10000){
        int f{2};
        f = x / 100 % 10;
        return f;
    }
    else if(x >= 100 && x < 1000){
        int f{3};
        f = x / 10 % 10;
        return f;
    }
    else{
        std::cout << "Error: Out of Range!" <<std::endl;
        return 0;
    }
}
int divide_last(int y){
        int l{0};
        l = y % 10;
        return l;
}

std::vector<int> power(int c, int d, std::vector<int> vect_c){
    int r{1};
    for (auto i{1}; i <= d; i++){
        r *= c;
        vect_c.push_back(r);
    }
    return vect_c;
}

void print_vect_b(std::vector<int> vect_c){
    for(MySpace::ull i{0}; i < vect_c.size(); i++){
        std::cout << vect_c[i] << " , ";
    }std::cout << std::endl;

}


void showlist_z(std::list <int> list_z){
    std::list <int> :: iterator it;
    for(it = list_z.begin(); it != list_z.end(); ++it){
        std::cout << '\t' << *it;
        std::cout << std::endl;
    }

}

void fill_list(std::list<int> list_y, std::vector<int> vect_y){
    for (MySpace::ull i{0}; i < vect_y.size(); ++i ){
        list_y.push_back(vect_y[i]);
    }
}
int task2() // -----LIST-----
{
    int x{10};
    int y{5};
    int a{19};
    int b{4};
    std::vector<int> vect_1{};
    std::vector<int> vect_2{};
    std::vector<int> vect_3{};
    std::list<int> list_1;
    std::list<int> list_2;
    power(x,y,vect_1);

    print_vect_b(vect_1);
    power(a,b,vect_2);
    print_vect_b(vect_2);

    for (MySpace::ull i{0}; i < vect_1.size(); i++){
        int k = divide_first(vect_1[i]);
        vect_3.push_back(k);
        int j = divide_last(vect_1[i]);
        vect_3.push_back(j);
    }
    std::cout << "vect_3" <<std::endl;
    print_vect_b(vect_3);
    fill_list(list_1,vect_3);
    std::cout << "List 1" << std::endl;
    showlist_z(list_1);

    for(MySpace::ull i{0}; i < vect_3.size(); ++i){
        vect_3.pop_back();
    }
    for (MySpace::ull i{0}; i < vect_2.size(); i++){
        int k = divide_first(vect_2[i]);
        vect_3.push_back(k);
        int j = divide_last(vect_2[i]);
        vect_3.push_back(j);
    }
    std::cout << "vect_3" <<std::endl;
    print_vect_b(vect_3);
    fill_list(list_2,vect_3);
    std::cout << "List 2" << std::endl;
    showlist_z(list_2);

    return 0;
}

