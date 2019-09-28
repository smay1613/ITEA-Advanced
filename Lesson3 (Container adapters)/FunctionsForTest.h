#ifndef FUNCTIONSFORTEST_H
#define FUNCTIONSFORTEST_H

#include <iostream>
#include <stack>

struct node
{
    int n;
    struct node* left;
    struct node* right;
    struct node* level;
};

bool isExpressionValid (const std::string& expression);

#endif // FUNCTIONSFORTEST_H
