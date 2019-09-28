#include <iostream>
#include <stack>
#include <queue>
#include <memory>
#include "FunctionsForTest.h"

bool isExpressionValid (const std::string& expression)
{
    std::stack<char> MyStack;
    char popStack;
    bool result = true;
    for(const auto& element : expression)
    {
        if ((element == '[')||(element == '(')||(element =='{'))
        {
            MyStack.push(element);
        }
        else
        {
            if(MyStack.empty())
            {
                result = false;
                break;
            }
            popStack = MyStack.top();
            MyStack.pop();
            if (!(((element == ')')&&(popStack=='('))||
                    ((element == '}')&&(popStack=='{'))||
                    ((element == ']')&&(popStack=='['))))
            {
                result = false;
                break;
            }

        }

    }
    if(!MyStack.empty())
    {
        result = false;
    }
    return result;
}

void linkSamelevel(std::shared_ptr<node> t)
{
    std::queue <std::shared_ptr<node>> q;
    q.push(t);
    q.push(nullptr);
    while (!q.empty())
    {
        std::shared_ptr<node> p = q.front();
        q.pop();
        if (p != nullptr)
        {
            p->level = q.front();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }

        else if (!q.empty())
            q.push(nullptr);
    }
}
