#include "functions.h"


int main()
{
    node *head;
    head = new node(1,nullptr,nullptr);
    head->left = new node(2,nullptr,nullptr);
    head->right = new node(3,nullptr,nullptr);
    head->left->left = new node(4,nullptr,nullptr);
    head->left->right = new node(5,nullptr,nullptr);
    head->right->left = new node(6,nullptr,nullptr);
    head->right->right = new node(7,nullptr,nullptr);

    show_tree(head);
    return 0;
}
