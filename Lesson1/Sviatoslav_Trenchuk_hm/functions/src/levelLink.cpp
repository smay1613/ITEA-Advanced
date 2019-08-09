#include "levelLink.h"
#include <queue>


void linkLevelNodes(TreeNode* root)
{
  if (root == nullptr) {
    return;
  }
  std::queue<TreeNode*> tree {};
  tree.push(root);

}
