#include <queue>
#include "gtest/gtest.h"


struct node{
    int n;                          //value of node
    struct node *left;              //left subtree
    struct node *right;             //right subtree
    struct node *level;             //level pointer (node "to the right")
};

void linkLevelNodes(node &Node1)
{
    std::queue <node *> FirstLevel;
    FirstLevel.push(&Node1);
    while(!FirstLevel.empty()){
        std::queue<node*> SecondLevel;
        node* NodePointer = FirstLevel.front();
        FirstLevel.pop();
        if(NodePointer->left != nullptr){
            SecondLevel.push( NodePointer->left);
        }
        if(NodePointer->right != nullptr){
            SecondLevel.push(NodePointer->right);
        }
        while(!FirstLevel.empty()){
            NodePointer->level = FirstLevel.front();
            NodePointer = NodePointer->level;
            if(NodePointer->left != nullptr){
                SecondLevel.push( NodePointer->left);
            }
            if(NodePointer->right != nullptr){
                SecondLevel.push(NodePointer->right);
            }
            FirstLevel.pop();
        }
        NodePointer->level = nullptr;
        while (!SecondLevel.empty()){
            FirstLevel.push(SecondLevel.front());
            SecondLevel.pop();
        }
    }
}

TEST(CheckValidString, Test1){
    node Node6;
    Node6.n = 6;
    Node6.left  = nullptr;
    Node6.right  = nullptr;
    Node6.level  = nullptr;

    node Node5;
    Node5.n = 5;
    Node5.left  = nullptr;
    Node5.right  = nullptr;
    Node5.level  = nullptr;

    node Node4;
    Node4.n = 4;
    Node4.left  = nullptr;
    Node4.right  = nullptr;
    Node4.level = nullptr;

    node Node3;
    Node3.n = 3;
    Node3.left = &Node5;
    Node3.right = &Node6;
    Node3.level = nullptr;

    node Node2;
    Node2.n = 2;
    Node2.left = &Node4;
    Node2.right = nullptr;
    Node2.level = nullptr;

    node Node1;
    Node1.n = 1;
    Node1.left = &Node2;
    Node1.right = &Node3;
    Node1.level = nullptr;

    linkLevelNodes(Node1);

    EXPECT_EQ(3, Node2.level->n);
    EXPECT_EQ(5, Node4.level->n);
    EXPECT_EQ(6, Node5.level->n);
    EXPECT_EQ(nullptr, Node3.level);
    EXPECT_EQ(nullptr, Node6.level);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

