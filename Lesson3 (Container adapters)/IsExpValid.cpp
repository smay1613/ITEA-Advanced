#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include "IsExpValid.h"


bool isExpressionValid (const std::string& expression)
{
    std::stack<char> MyStack;
    bool result {true};
    std::set<char> openBrack{'(', '{', '['};
    for(const auto& element : expression)
    {

        if (openBrack.find(element) != openBrack.end())
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
            char popStack;
            popStack = MyStack.top();
            MyStack.pop();

            result = check(element, popStack);
            if (result == false)
            {
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

bool check(char element,char popStack)
{
    bool result {true};
    if (!(((element == ')')&&(popStack=='('))||
            ((element == '}')&&(popStack=='{'))||
            ((element == ']')&&(popStack=='['))))
    {
        result = false;
    }
    return result;
}
