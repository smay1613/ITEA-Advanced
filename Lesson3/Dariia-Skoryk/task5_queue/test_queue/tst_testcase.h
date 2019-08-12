#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <../task/main.h>

using namespace testing;

bool isEqual(const node *node1, const node *node2)
{
    if ((node1 == nullptr) && (node2 == nullptr))
        return true;
    if ((node1 == nullptr) || (node2 == nullptr))
        return false;
    if (node1->value != node2->value)
        return false;
    return isEqual(node1->left, node2->left) && isEqual(node1->right, node2->right) && isEqual(node1->level, node2->level);
}

TEST(testCase, testSet)
{
    //empty tree
    node *root = nullptr;
    node *resultRoot = nullptr;
    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

TEST(testCase2, testSet)
{
    //tree with one node
    node *root = new node;
    root->left = root->right = root->level = nullptr;
    root->value = 0;
    node *resultRoot = new node;
    resultRoot->left = resultRoot->right = resultRoot->level = nullptr;
    resultRoot->value = 0;
    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

TEST(testCase3, testSet)
{
    //binary tree                                                           1
    node *root = new node;                  //                 2                         3
    root->value = 1;                        //          4           5               6         NULL
    root->left = new node;                  //      NULL NULL   NULL NULL       NULL NULL
    root->left->value = 2;
    root->left->left = new node;
    root->left->left->value = 4;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right = new node;
    root->left->right->value = 5;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right = new node();
    root->right->value = 3;
    root->right->left = new node;
    root->right->left->value = 6;
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right = nullptr;

    root->level = nullptr;
    root->left->level = nullptr;
    root->right->level = nullptr;
    root->left->left->level = nullptr;
    root->left->right->level = nullptr;
    root->right->left->level = nullptr;

    node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = new node;
    resultRoot->left->value = 2;
    resultRoot->left->left = new node;
    resultRoot->left->left->value = 4;
    resultRoot->left->left->left = nullptr;
    resultRoot->left->left->right = nullptr;
    resultRoot->left->right = new node;
    resultRoot->left->right->value = 5;
    resultRoot->left->right->left = nullptr;
    resultRoot->left->right->right = nullptr;
    resultRoot->right = new node();
    resultRoot->right->value = 3;
    resultRoot->right->left = new node;
    resultRoot->right->left->value = 6;
    resultRoot->right->left->left = nullptr;
    resultRoot->right->left->right = nullptr;
    resultRoot->right->right = nullptr;

    resultRoot->level = nullptr;
    resultRoot->left->level = resultRoot->right;
    resultRoot->right->level = nullptr;
    resultRoot->left->left->level = resultRoot->left->right;
    resultRoot->left->right->level = resultRoot->right->left;
    resultRoot->right->left->level = nullptr;

    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

TEST(testCase4, testSet)
{
    //custom tree                                                           1
    node *root = new node;                  //                 2                         3
    root->value = 1;                        //          4          NULL           NULL          7
    root->left = new node;                  //      NULL NULL                               NULL NULL
    root->left->value = 2;
    root->left->left = new node;
    root->left->left->value = 4;
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right = nullptr;
    root->right = new node();
    root->right->value = 3;
    root->right->left = nullptr;
    root->right->right = new node;
    root->right->right->value = 7;
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    root->level = nullptr;
    root->left->level = nullptr;
    root->right->level = nullptr;
    root->left->left->level = nullptr;
    root->right->right->level = nullptr;

    node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = new node;
    resultRoot->left->value = 2;
    resultRoot->left->left = new node;
    resultRoot->left->left->value = 4;
    resultRoot->left->left->left = nullptr;
    resultRoot->left->left->right = nullptr;
    resultRoot->left->right = nullptr;
    resultRoot->right = new node();
    resultRoot->right->value = 3;
    resultRoot->right->left = nullptr;
    resultRoot->right->right = new node;
    resultRoot->right->right->value = 7;
    resultRoot->right->right->left = nullptr;
    resultRoot->right->right->right = nullptr;

    resultRoot->level = nullptr;
    resultRoot->left->level = resultRoot->right;
    resultRoot->right->level = nullptr;
    resultRoot->left->left->level = resultRoot->right->right;
    resultRoot->right->right->level = nullptr;

    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

TEST(testCase5, testSet)
{
    node *root = new node;
    root->value = 1;
    root->left = nullptr;
    root->right = new node;
    root->right->value = 0;
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->level = nullptr;

    node *resultRoot = new node;
    resultRoot->value = 1;
    resultRoot->left = nullptr;
    resultRoot->right = new node;
    resultRoot->right->value = 0;
    resultRoot->right->left = nullptr;
    resultRoot->right->right = nullptr;
    resultRoot->level = nullptr;

    linkLevelNodes(root);
    EXPECT_TRUE(isEqual(root, resultRoot));
}

