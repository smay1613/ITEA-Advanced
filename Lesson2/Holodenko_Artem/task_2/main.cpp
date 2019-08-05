#include <iostream>
#include <deque>
#include <queue>
#include <math.h>


struct node
{
    node (int _n)
        : n(_n)
    {}
    node (int _n, node *_left, node *_right)
        : n(_n),
          left(_left),
          right(_right)
    {}
    int n = 0;
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *level = nullptr;
};

void create_tree(std::deque<node> &_tree, node* element)
{
    int n;

    std::cout << element->n << "->";
    std::cin >> n;
    if (n!=0)
    {
        _tree.push_back(node{n});
        element->left = &_tree[_tree.size()-1];
        create_tree(_tree, &_tree[_tree.size()-1]);
    }

    std::cout << element->n << "->";
    std::cin >> n;
    if (n!=0)
    {
        _tree.push_back(node{n});
        element->right = &_tree[_tree.size()-1];
        create_tree(_tree, &_tree[_tree.size()-1]);
    }
}

void create_tree(std::deque<node> &_tree)
{
    int n;
    std::cout << "->";
    std::cin >> n;
    _tree.push_back(node{n});
    create_tree(_tree, &_tree[0]);
}

void print_nodes(node* element)
{
    if (element->left!=nullptr)
    {
        std::cout << element->n << "->" << element->left->n <<std::endl;
    }
    if (element->right!=nullptr)
    {
        std::cout << element->n <<"->" << element->right->n <<std::endl;
    }
    if (element->level!=nullptr)
    {
        std::cout << element->n <<"->" << element->level->n <<std::endl;
    }

    if (element->left!=nullptr)
    {
        print_nodes(element->left);
    }
    if (element->right!=nullptr)
    {
        print_nodes(element->right);
    }
}

void linkLevelNodes(node* element)
{
    std::queue<node*> nodes_queue;
    node* element_level_1 = nullptr;
    node* element_level_2 = element->left;

    nodes_queue.push(element);

    while (!nodes_queue.empty())
    {
        if (nodes_queue.front()->left!=nullptr)
        {
            nodes_queue.push(nodes_queue.front()->left);
        }
        if (nodes_queue.front()->right!=nullptr)
        {
            nodes_queue.push(nodes_queue.front()->right);
        }

        if (element_level_1 == nullptr)
        {
            element_level_1 = nodes_queue.front();
        }
        else
        {
            if (nodes_queue.front() == element_level_2)
            {
                element_level_1 = nodes_queue.front();
                element_level_2 = nodes_queue.front()->left;
            }
            else
            {
                element_level_1->level = nodes_queue.front();
                element_level_1 = nodes_queue.front();
            }
        }
        nodes_queue.pop();
    }
}

int main()
{
    std::deque<node> tree;
    create_tree(tree);

    std::cout <<std::endl;
    print_nodes(&tree[0]);

    linkLevelNodes(&tree[0]);

    std::cout <<std::endl;
    print_nodes(&tree[0]);

    return 1;
}
