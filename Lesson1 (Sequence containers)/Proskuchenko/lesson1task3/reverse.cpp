#include <iostream>
#include <forward_list>

template<typename T>
void reverse(std::forward_list<T>& listToReverse){
  std::forward_list<T> temprorary_flist{};
  while(!listToReverse.empty()) {
    temprorary_flist.push_front(listToReverse.front());
    listToReverse.pop_front();
  }
  listToReverse = std::move(temprorary_flist);
}
