#include "listReverse.h"

void listReverse(std::forward_list<int>& forwardList) {
  std::forward_list<int> tmpForwardList {};

  for(const auto &value: forwardList) {
      tmpForwardList.push_front(value);
  }

  forwardList.clear();
  forwardList.splice_after(forwardList.before_begin(),tmpForwardList);

}
