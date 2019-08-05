#include <QCoreApplication>
#include "main.h"

int main()
{
    std::cout << "Enter count of values" << std::endl;
    int count;
    std::cin >>count;
    std::cout << "Enter your values" << std::endl;
    node* root = nullptr;
    for (int i{0}; i < count; i++) {
        int value;
        std::cin >> value;
        node::addToTree(root, value);
    }
    linkLevelNodesAndPrint(root);

    return 0;
}
