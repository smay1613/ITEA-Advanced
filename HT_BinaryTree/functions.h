#pragma once

#include <iostream>
#include <queue>


class node{
public:

    int value;
    node *right;
    node *left;
    node(int m_value,node *m_left,node *m_right);
};




void show_tree(node* head);


