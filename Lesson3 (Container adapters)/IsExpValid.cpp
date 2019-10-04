#include <iostream>
#include <stack>
#include <queue>
#include "IsExpValid.h"


bool isExpressionValid (const std::string& expression)
{
    std::stack<char> MyStack;
    char popStack;
    bool result {true};
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
