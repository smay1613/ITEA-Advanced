#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <queue>
#include <stdexcept>

struct ParentandChild;

struct Node
{
    Node* left;
    Node* right;
    Node* next = nullptr;
    Node* parent = nullptr;
    int key;
};

class BinaryTreeWrapper
{
public:
    void push(Node*& tree, int key, Node* parent = nullptr);
    void print(Node* tree);
    void pop(Node*& t, int key);
    std::pair<Node*,Node*> findMinRight(Node* t);
    void linkSamelevel(Node*&);
    void find(Node *&parent, Node*& currentNode, int);
};

class nodeIterator : public std::iterator<std::bidirectional_iterator_tag, int>
{
public:
    explicit nodeIterator(Node* container);
    int operator*() const;
    nodeIterator operator++();

    nodeIterator begin();
    nodeIterator end();
    bool operator!=(const nodeIterator& other) const;
    bool operator==(const nodeIterator& other) const;
private:
    Node* container;
    Node* descent(int count, int count2, int inLoop, Node *&tree, Node *&copyTree);
    int countNodes(Node *tree);

};

#endif // TREE_H
