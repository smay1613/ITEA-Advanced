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
    void push(Node*& tree, int a, Node* z = nullptr);
    void print(Node* tree);
    void pop(Node*& t, int key);
    ParentandChild findMinRight(Node* t);
    void linkSamelevel(Node*&);
    void find(Node *&parent, Node*& currentNode, int);

};

struct ParentandChild
{
    Node* parent;
    Node* child;
};


class nodeIterator : public std::iterator<std::output_iterator_tag, int>
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
};

#endif // TREE_H
