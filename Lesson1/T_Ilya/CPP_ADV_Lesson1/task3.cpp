#include "task.h"
#include <forward_list>
#include <iterator>



void showlist_fwd(std::forward_list <int> list_n)
{
    std::forward_list <int> :: iterator it;
    for(it = list_n.begin(); it != list_n.end(); ++it){
        std::cout << ' ' << *it << std::endl;
    }
}
void print_vect_a(std::vector<int> a_vect){
    for(MySpace::ull i{0}; i < a_vect.size(); i++){
        std::cout << a_vect[i] << " , ";
    }std::cout << std::endl;

}
int task3()  // -----FORWARD LIST-------
{
    std::vector<int> vect_a;
    std::forward_list<int> fwd_list_a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "list a: " << std::endl;
    showlist_fwd(fwd_list_a);
    std::forward_list<int> fwd_list_b{};
    for(auto i = 0; i < 9; i++){

        vect_a.emplace_back(fwd_list_a.front());
        fwd_list_a.pop_front();

    }
    std::cout << "list a: " << std::endl;
    showlist_fwd(fwd_list_a);
    std::cout << "vector a: " << std::endl;
    print_vect_a(vect_a);
    for(MySpace::ull i{0}; i < 9; i++){
    fwd_list_a.push_front(vect_a[i]);
    }
    std::cout << "Reversed list: " << std::endl;
    showlist_fwd(fwd_list_a);
    return 0;
}

