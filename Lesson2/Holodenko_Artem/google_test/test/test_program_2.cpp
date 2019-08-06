#include "gtest/gtest.h"
#include "queue"
#include "deque"

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

void linkLevelNodes(node* element)
{
    if (element==nullptr)
    {
        return;
    }
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

struct comporator
{
    bool operator()(const node &lhs, const node &rhs)
    {
        if (lhs.n == rhs.n && lhs.left==rhs.left && lhs.right==rhs.right && lhs.level==rhs.level)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


class link_level_nodes_test : public ::testing::Test
{
public:
    std::deque<node> tree_1 = {1};
    std::deque<node> result_1 = {1};
};

TEST_F(link_level_nodes_test, 1)
{

}
