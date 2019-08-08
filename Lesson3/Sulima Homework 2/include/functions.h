#pragma once
#include <string>

struct node
{
    int value{};
    node *left{nullptr};
    node *right{nullptr};
    node *level{nullptr};
};

bool isExpressionValid (const std::string& expression);
void linkLevelNodes(node *root);

