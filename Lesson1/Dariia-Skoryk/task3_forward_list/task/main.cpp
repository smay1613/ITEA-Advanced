#include "main.h"

int main() {
    srand(clock());
    std::forward_list<int> forwardList;
    int size = rand() % 10 + 1;
    for (int i = 0; i < size; i++) {
        forwardList.push_front(rand() - RAND_MAX / 2);
    }
    output(forwardList);
    reverse(forwardList);
    output(forwardList);

    return 0;
}
