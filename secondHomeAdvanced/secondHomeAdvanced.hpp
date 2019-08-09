#ifndef FIRSTHOMEADVANCED_HPP  //add include guard
#define FIRSTHOMEADVANCED_HPP

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <cmath>
#include <algorithm>
#include <iterator>     //to use std::merge 

#include <regex>
#include <stack>
#include <queue>

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

bool isExpressionValid (const std::string& expression); 
void linkLevelNodes(Node* root);

#endif
