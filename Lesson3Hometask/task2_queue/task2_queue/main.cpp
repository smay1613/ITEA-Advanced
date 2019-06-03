#include <iostream>
#include <queue>
#include <cassert>
#include <deque>

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

void fill_all_nodes_on_level (const node* const root_node, const size_t level, std::queue <node*> & nodes_queue)
{
    node* right_node = root_node->right;
    node* left_node  = root_node->left;

    if (level != 1) {
        if (left_node != nullptr) {
            fill_all_nodes_on_level (left_node, level - 1, nodes_queue);
        }
        if (right_node != nullptr) {
            fill_all_nodes_on_level (right_node, level - 1, nodes_queue);
        }
        return;
    }

    if (left_node != nullptr) {
        nodes_queue.push (left_node);
    }
    if (right_node != nullptr) {
        nodes_queue.push (right_node);
    }
}

void fill_level_on_nodes (std::queue <node*> & nodes_queue)
{
    node* prev_node {nullptr};
    while (!nodes_queue.empty()) {
        if (prev_node != nullptr) {
            prev_node->level = nodes_queue.front();
        }
        prev_node = nodes_queue.front();
        nodes_queue.pop();
    }
}

void fill_tree_nodes_level (node& root_node)
{
    std::queue <node*> nodes_queue {};
    std::size_t level {0};
    bool nodes_on_level_existed {false};

    do {
        while (!nodes_queue.empty()) {
            nodes_queue.pop();
        }
        level++;

        fill_all_nodes_on_level (&root_node, level, nodes_queue);
        nodes_on_level_existed = !nodes_queue.empty();
        fill_level_on_nodes (nodes_queue);
    }
    while (nodes_on_level_existed);
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

    assert (node2.level == &node3);
    assert (node4.level == &node5);
    assert (node5.level == &node6);

    std::cout << "Complete!" << std::endl;

    return 0;
}
