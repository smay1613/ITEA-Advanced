#pragma once
#include <vector>

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* rigth;
    TreeNode* level;
};
void linkLevelNodes(TreeNode* );
