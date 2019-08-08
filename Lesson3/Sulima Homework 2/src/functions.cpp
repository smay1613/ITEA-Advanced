#include "functions.h"
#include <stack>
#include <queue>

char reverseRightToLeftBracketsFunction(const char m_rightBrackets){
    switch (m_rightBrackets)
    {
    case '}':
    {
        return '{';
    }
    case ')':
    {
        return '(';
    }
    case ']':
    {
        return '[';
    }
    default:
        return NULL;
    }
}


bool isExpressionValid (const std::string& expression){
    std::stack<char>stackOpenBrackets;
    for(const auto &value: expression){
        if(value == '{' || value == '(' || value == '[')
        {
            stackOpenBrackets.push(value);
        }
        else {
            if(stackOpenBrackets.empty()){
                return false;
            }

            char reverseRightToLeftBrackets{reverseRightToLeftBracketsFunction(value)};

            if(stackOpenBrackets.top() != reverseRightToLeftBrackets )
            {
                return false;
            }
            else
            {
                stackOpenBrackets.pop();
            }
        }
    }
    if(stackOpenBrackets.empty()){
        return true;
    }
    return false;
}


void linkLevelNodes(Node *root)
{
    std::queue<Node *> firstLevel;
    firstLevel.push(root);
    while (!firstLevel.empty())
    {
        std::queue<Node *> secondLevel;
        if (firstLevel.front()->left != nullptr)
        {
            secondLevel.push(firstLevel.front()->left);
        }
        if (firstLevel.front()->right != nullptr)
        {
            secondLevel.push(firstLevel.front()->right);
        }
        Node* tmp = firstLevel.front();
        firstLevel.pop();
        while (!firstLevel.empty())
        {
            tmp->level = firstLevel.front();
            tmp = tmp->level;
            if (tmp->left != nullptr)
            {
                secondLevel.push(tmp->left);
            }
            if (tmp->right != nullptr)
            {
                secondLevel.push(tmp->right);
            }
            firstLevel.pop();
        }
        tmp->level = nullptr;
        firstLevel = secondLevel;
    }
}
