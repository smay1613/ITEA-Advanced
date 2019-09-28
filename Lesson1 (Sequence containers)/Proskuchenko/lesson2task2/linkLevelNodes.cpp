#include <iostream>
#include <queue>
#include <cmath>

struct node {
  int n = 1;
  node* left = nullptr;
  node* right = nullptr;
  node* level = nullptr;
};

void linkLevelNodes(node* root) {
  if (nullptr == root) {
    return;
  }
  std::queue<node*> ptrNode;
  ptrNode.push(root);
  size_t NextLevelNodes = 0;
  size_t expectedNodes = 2;
  bool isPointToNext = true;
  node* previusNodePtr = nullptr;
  while (!ptrNode.empty()) {
    node& currentNode = *(ptrNode.front());
    if (isPointToNext) {
      currentNode.level = previusNodePtr;
    }
    isPointToNext = true;
    if (currentNode.right != nullptr) {
      ptrNode.push(currentNode.right);
      ++NextLevelNodes;
    } else {
      --expectedNodes;
    }
    if (currentNode.left != nullptr) {
    ptrNode.push(currentNode.left);
      ++NextLevelNodes;
    } else {
      --expectedNodes;
    }
    if (expectedNodes == NextLevelNodes) {
      expectedNodes = pow(2, expectedNodes);
      NextLevelNodes = 0;
      isPointToNext = false;
    }
    previusNodePtr = &currentNode;
    ptrNode.pop();
  }
}
