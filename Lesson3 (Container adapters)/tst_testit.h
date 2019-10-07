#ifndef TST_TESTIT_H
#define TST_TESTIT_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "tree.h"
#include "IsExpValid.h"

using namespace testing;


TEST(Test_Iterator_Push_Pop, Test1)
{
    Node* n1 = new Node;
    n1->key = 4;
    n1->next = nullptr;
    n1->parent = nullptr;
    Node* n2 = new Node;
    n2->key = 6;
    n2->next = nullptr;
    n1->right = n2;
    Node* n3 = new Node;
    n3->key = 8;
    n3->parent = n2;
    n3->left = nullptr;
    n2->right = n3;
    Node* n4 = new Node;
    n4->key = 9;
    n4->parent = n3;
    n3->right = n4;
    n4->left = nullptr;
    Node* n5 = new Node;
    n5->key = 5;
    n5->next = n3;
    n5->parent = n2;
    n5->left = nullptr;
    n2->left = n5;
    Node* n6 = new Node;
    n6->key = 3;
    n6->next = n2;
    n6->parent = n1;
    n6->left = nullptr;
    n6->left = nullptr;
    nodeIterator outpIt(n5);


    BinaryTreeWrapper controlTree;

    Node* tree = nullptr;
    controlTree.push(tree, 4);
    controlTree.push(tree, 6);
    controlTree.push(tree, 8);
    controlTree.push(tree, 9);
    controlTree.push(tree, 5);
    controlTree.push(tree, 3);
    nodeIterator it(tree);
    it = ++it;
    EXPECT_EQ(3, *it);
}

TEST(Test_Iterator_Push, Test1)
{
    BinaryTreeWrapper controlTree;
    Node* tree = nullptr;
    controlTree.push(tree, 4);
    controlTree.push(tree, 5);
    controlTree.push(tree, 7);
    controlTree.push(tree, 10);
    controlTree.push(tree, 6);
    controlTree.push(tree, 3);
    nodeIterator it(tree);
    for(int i = 0; i < 5; i++)
    {
        it = ++it;
    }


    EXPECT_EQ(*it, 10);
}

TEST(Test_Iterator_Push_Pop, Test2)
{
    BinaryTreeWrapper controlTree;
    Node* tree = nullptr;
    controlTree.push(tree, 4);
    controlTree.push(tree, 5);
    controlTree.push(tree, 7);
    controlTree.push(tree, 10);
    controlTree.pop(tree,5);
    controlTree.push(tree, 6);
    controlTree.push(tree, 3);
    nodeIterator it(tree);
    it = ++it;
    EXPECT_EQ(*it, 3);
}

TEST(Test_Iterator_Push_Pop, Test3)
{
    BinaryTreeWrapper controlTree;
    Node* tree = nullptr;
    controlTree.push(tree, 4);
    controlTree.push(tree, 10);
    controlTree.pop(tree, 10);
    controlTree.push(tree, 6);
    nodeIterator it(tree);
    for(int i = 0; i < 1; i++)
    {
        it = ++it;
    }


    EXPECT_EQ(*it, 6);
}

TEST(Test_Iterator_Push_Pop, Test4)
{
    BinaryTreeWrapper controlTree;
    Node* tree = nullptr;
    controlTree.push(tree, 3);
    controlTree.push(tree, 6);
    controlTree.push(tree, 2);
    controlTree.push(tree, 5);
    controlTree.push(tree, 4);
    controlTree.push(tree, 7);
    controlTree.push(tree, 8);
    controlTree.push(tree, 10);
    controlTree.pop(tree, 6);


    nodeIterator it(tree);
    for(int i = 0; i < 2; i++)
    {
        it = ++it;
    }


    EXPECT_EQ(*it, 7);
}

TEST(Test_Iterator_Push_Pop, Test5)
{
    BinaryTreeWrapper controlTree;
    Node* tree = nullptr;
    controlTree.push(tree, 4);
    controlTree.push(tree, 5);
    controlTree.push(tree, 7);
    controlTree.push(tree, 10);
    controlTree.push(tree, 3);
    controlTree.push(tree, 6);


    nodeIterator it(tree);
    for(int i = 0; i < 5; i++)
    {
        it = ++it;
    }


    EXPECT_EQ(*it, 10);
}

TEST(IsExpressionValid, Test1)
{
    std::string InpStr = "[][]({})";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test2)
{
    std::string InpStr = "[][]({}]";
    EXPECT_EQ(false, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test3)
{
    std::string InpStr = "[()]{}{[()()]()}";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test4)
{
    std::string InpStr = "[)";
    EXPECT_EQ(false, isExpressionValid(InpStr));
}

TEST(IsExpressionValid, Test5)
{
    std::string InpStr = "";
    EXPECT_EQ(true, isExpressionValid(InpStr));
}


#endif // TST_TESTIT_H
