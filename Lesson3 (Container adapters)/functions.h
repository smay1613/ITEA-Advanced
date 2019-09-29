#pragma once

bool isExpressionValid (const std::string& expression);

struct node
{
    int n;
    struct node *left;
    struct node *right;
    struct node *level;
};

int getNodeLevel (node* nodeToObserve, node* nodeTofind, int level);

void linkLevelNodes(node* root);
