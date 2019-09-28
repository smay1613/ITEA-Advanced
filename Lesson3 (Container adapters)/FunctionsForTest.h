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

void linkSamelevel(std::shared_ptr<node> t);

bool isExpressionValid (const std::string& expression);

#endif // FUNCTIONSFORTEST_H
