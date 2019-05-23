#include "functions.h"

int task3()  // -----FORWARD LIST-------
{
    std::vector<int> vect_a{};
    std::cout << "vector a: " << std::endl;
    MFun::print_vect(vect_a);
    std::forward_list<int> fwd_list_a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "list a: " << std::endl;
    MFun::showlist_fwd(fwd_list_a);
    while(!fwd_list_a.empty()) {
        vect_a.emplace_back(fwd_list_a.front());
        fwd_list_a.pop_front();
    }
    std::cout << "vector a: " << std::endl;
    MFun::print_vect(vect_a);
    std::cout << "list a: " << std::endl;
    MFun::showlist_fwd(fwd_list_a);
    for(size_t i{0}; i < vect_a.size(); ++i) {
        fwd_list_a.push_front(vect_a[i]);
    }
    vect_a.clear();
    std::cout << "Reversed list: " << std::endl;
    MFun::showlist_fwd(fwd_list_a);
    std::cout << "vector a: " << std::endl;
    MFun::print_vect(vect_a);
    return 0;
}
