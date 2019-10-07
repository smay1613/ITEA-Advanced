#include <iostream>
#include <queue>
#include <stdexcept>
#include "tree.h"



nodeIterator nodeIterator::end()
{
    nodeIterator it(nullptr);
    return it;
}

bool nodeIterator::operator!=(const nodeIterator& other) const
{
    return (this->container->key != other.container->key);
}

bool nodeIterator::operator==(const nodeIterator& other) const
{
    return (this->container->key == other.container->key);
}
nodeIterator nodeIterator::begin()
{
    Node* tree = this->container;
    while(tree->parent != nullptr)
    {
        tree = tree->parent;
    }
    nodeIterator it(tree);
    return it;

}

Node* nodeIterator::descent(int count, int count2, int inLoop, Node*& tree, Node*& copyTree)
{
    while((count + 1 != count2) ||(count > 0))
    {
        if(inLoop > 0)
        {
            count --;
            count2 = 0;
            if(tree->right != nullptr)
            {
                tree = tree->right;
            }
            else if(copyTree->left != nullptr)
            {
                tree = tree->left;
            }
        }
        copyTree = tree;

        for(int i = 0; i <= count ; i++)
        {
            if(copyTree->left != nullptr)
            {
                copyTree = copyTree->left;
                count2++;
            }
            else if(copyTree->right != nullptr)
            {
                copyTree = copyTree->right;
                count2++;
            }
        }
        inLoop = 1;
    }
    return copyTree;
}

int nodeIterator::countNodes(Node *tree)
{
    if(tree == nullptr)
    {
        return 0;
    }
    int count = 1;
    if (tree->left != nullptr) {
       count += countNodes(tree->left);
    }
    if (tree->right != nullptr) {
        count += countNodes(tree->right);
    }
    return count;
}



nodeIterator nodeIterator::operator++()
{
    Node* tree = this->container;
    nodeIterator bIt(tree);
    nodeIterator beginIterator = bIt.begin();
    if(tree->next != nullptr)
    {
        nodeIterator it(tree->next);
        return it;
    }
    if(tree->parent == nullptr)
    {
        if(tree->left != nullptr)
        {
            nodeIterator it(tree->left);
            return it;
        }
        else
        {
            nodeIterator it(tree->right);
            return it;
        }
    }

    int count {0};
    Node* copyTree = tree;
    while(copyTree->parent != nullptr)
    {
        copyTree = copyTree->parent;
        count++;
    }
    int count2{0};
    int inLoop = 0;
    copyTree = beginIterator.container;
    tree = beginIterator.container;

    copyTree=descent(count, count2, inLoop, tree, copyTree);
    nodeIterator it(copyTree);
    if(*this == it)
    {
        return it.end();
    }
    return it;
}

std::pair<Node*,Node*> BinaryTreeWrapper::findMinRight(Node* tree)
{
    std::pair<Node*,Node*> pch;
    pch.first = tree;
    pch.second = nullptr;
    while(pch.first->left != nullptr)
    {
        pch.second = pch.first;
        pch.second= pch.second->left;
    }
    return pch;
}

void BinaryTreeWrapper::find(Node *&parent, Node*& currNode, int key)
{
    while(currNode->key != key)
    {
        if(key < currNode->key)
        {
            parent = currNode;
            currNode = currNode->left;
        }
        if(key > currNode->key)
        {
            parent = currNode;
            currNode = currNode->right;
        }
    }
}


void BinaryTreeWrapper::pop(Node *&t, int key)
{
    Node* parent = nullptr;
    Node* currNode = t;
    find(parent,currNode,key);

    if((currNode->right == nullptr)&&(currNode->left==nullptr))
    {
        if(currNode->key > parent->key)
        {
            parent->right = nullptr;
            delete currNode;
        }
        else
        {
            parent->left = nullptr;
            delete currNode;
        }
        return;
    }
    if(currNode->right ==nullptr)
    {
        if(currNode->key < parent->key)
        {
            parent->left = currNode->left;
            parent->left->parent = parent;
            delete currNode;
        }
        else
        {
            parent->right = currNode->left;
            parent->right->parent = parent;
            delete currNode;
        }
    }
    if(currNode->left ==nullptr)
    {
        if(currNode->key < parent->key)
        {
            parent->left = currNode->right;
            parent->left->parent = parent;
            delete currNode;
        }
        else
        {
            parent->right = currNode->right;
            parent->right->parent = parent;
            delete currNode;
        }
    }
    if((currNode->left!=nullptr)&&(currNode->right!=nullptr))
    {
        std::pair<Node*, Node*> minNode = findMinRight(currNode->right);
        currNode->key = minNode.first->key;
        if(currNode->right == minNode.first)
        {
            currNode->right = minNode.first->right;
        }
        else
        {
            minNode.second->left = nullptr;
            delete minNode.first;
        }
    }
    linkSamelevel(t);
}


void BinaryTreeWrapper::linkSamelevel(Node*& t)
{
    std::queue <Node*> q;
    q.push(t);
    q.push(nullptr);
    if(t == nullptr)
    {
        return;
    }
    while (!q.empty())
    {
        Node* p = q.front();
        q.pop();
        if (p != nullptr)
        {
            p->next = q.front();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }

        else if (!q.empty())
            q.push(nullptr);
    }
}


int nodeIterator::operator*() const
{
    return this->container->key;
}

nodeIterator::nodeIterator(Node* container)
{
    this->container = container;
}

void BinaryTreeWrapper::push(Node *&tree, int a, Node* parent)
{
    if(tree == nullptr)
    {
        tree = new Node;
        tree->parent = parent;
        tree->key = a;
        tree->left = nullptr;
        tree->right = nullptr;
        return;

    }
    else
    {
        if(a < tree->key)
        {
            push(tree->left,a, tree);
        }
        else
        {
            push(tree->right,a, tree);
        }
    }
    linkSamelevel(tree);
}

void BinaryTreeWrapper::print(Node* tree)
{
    std::queue<Node*> qTree;
    qTree.push(tree);
    Node* currTree = tree;
    while(!qTree.empty())
    {
        currTree = qTree.front();
        qTree.pop();
        std::cout << currTree->key << " ";
        if(currTree->left!=nullptr)
        {
          qTree.push(currTree->left);
        }
        if(currTree->right!=nullptr)
        {
          qTree.push(currTree->right);
        }
    }
}






