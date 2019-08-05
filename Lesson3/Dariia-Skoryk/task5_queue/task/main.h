#pragma once

#include <iostream>
#include <queue>

struct node {
public:
    int value;
    node *left, *right, *level;

    node(int value) {
        this->value = value;
        left = right = level = nullptr;
    }

    node() {}

    static void addToTree(node * &root, int value) {
        if (root == nullptr) {
            root = new node(value);
            return;
        }
        findPlace(root, value);
    }
private:
    static void findPlace(node * nodePointer, int value) {
        if (value < nodePointer->value) {
            if (nodePointer->left == nullptr) {
                nodePointer->left = new node(value);
            }
            else findPlace(nodePointer->left, value);
        }
        else {
            if (nodePointer->right == nullptr) {
                nodePointer->right = new node(value);
            }
            else findPlace(nodePointer->right, value);
        }
    }
};

void linkLevelNodesAndPrint(node *root) {
    std::cout << "Result" << std::endl;
    std::queue<node *> level;
    level.push(root);
    while (!level.empty()) {
        std::queue<node *> nextLevel;
        node* nodePointer = level.front();
        level.pop();
        std::cout << nodePointer->value << ' ';

        if (nodePointer->left != nullptr) {
            nextLevel.push(nodePointer->left);
        }
        if (nodePointer->right != nullptr) {
            nextLevel.push(nodePointer->right);
        }

        while (!level.empty()) {
            nodePointer->level = level.front();
            nodePointer = nodePointer->level;
            if (nodePointer->left != nullptr) {
                nextLevel.push(nodePointer->left);
            }
            if (nodePointer->right != nullptr) {
                nextLevel.push(nodePointer->right);
            }
            level.pop();
            std::cout << nodePointer ->value << ' ';
        }
        nodePointer->level = nullptr;

        while (!nextLevel.empty()) {
            level.push(nextLevel.front());
            nextLevel.pop();
        }
        std::cout << std::endl;
    }
}

void linkLevelNodes(node *root) {
    std::queue<node *> level;
    level.push(root);
    while (!level.empty()) {
        std::queue<node *> nextLevel;
        node* nodePointer = level.front();
        level.pop();
        if (nodePointer->left != nullptr) {
            nextLevel.push(nodePointer->left);
        }
        if (nodePointer->right != nullptr) {
            nextLevel.push(nodePointer->right);
        }

        while (!level.empty()) {
            nodePointer->level = level.front();
            nodePointer = nodePointer->level;
            if (nodePointer->left != nullptr) {
                nextLevel.push(nodePointer->left);
            }
            if (nodePointer->right != nullptr) {
                nextLevel.push(nodePointer->right);
            }
            level.pop();
        }
        nodePointer->level = nullptr;

        while (!nextLevel.empty()) {
            level.push(nextLevel.front());
            nextLevel.pop();
        }
    }
}

