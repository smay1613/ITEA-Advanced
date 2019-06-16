#include "functions.h"


int main()
{
    node *head;
    head = new node(1,0,0);
    head->left = new node(2,0,0);
    head->right = new node(3,0,0);
    head->left->left = new node(4,0,0);
    head->left->right = new node(5,0,0);
    head->right->left = new node(6,0,0);
    head->right->right = new node(7,0,0);

    show_tree(head);
    return 0;
}
