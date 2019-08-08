#pragma once
#include <string>

struct Node
{
    int value{};
    Node *left{nullptr};
    Node *right{nullptr};
    Node *level{nullptr};
};

bool isExpressionValid (const std::string& expression);
void linkLevelNodes(Node *root);

