#ifndef FUNCTIONSFORTEST_H
#define FUNCTIONSFORTEST_H

#include <iostream>
#include <stack>
#include <memory>

struct node
{
    int n;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
    std::shared_ptr<node> level;
};

bool isExpressionValid (const std::string& expression);

#endif // FUNCTIONSFORTEST_H
