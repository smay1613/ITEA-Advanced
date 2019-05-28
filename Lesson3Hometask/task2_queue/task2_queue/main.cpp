#include <iostream>
#include <queue>
#include <cassert>

struct node
{
    int   n     {};        // value of node
    node* left  {nullptr}; // left subtree
    node* right {nullptr}; // right subtree
    node* level {nullptr}; // node "to the right"

    node (int n_, node* left_ = nullptr, node* right_ = nullptr)
        : n     {n_    }
        , left  {left_ }
        , right {right_}
    {}
};

void fill_tree_nodes_level (node& root_node)
{

}

int main()
{
    node node4 {4};
    node node5 {5};
    node node6 {6};

    node node2 {2, &node4};
    node node3 {3, &node5, &node6};

    node node1 {1, &node2, &node3};

    fill_tree_nodes_level (node1);

    return 0;
}
