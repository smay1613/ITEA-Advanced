#include <../include/functions.h>
#include <stack>
namespace functions
{
bool isExpressionValid(const std::string &expression)
{
    std::stack <char> bracecStack{};

    for(size_t i = 0; i < expression.length(); ++i)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            bracecStack.push(expression[i]);
        }

        if(bracecStack.empty())
        {
            return false;
        }

        if(!bracecStack.empty())
        {
            // ()
            if(expression[i] == ')')
            {
                if(bracecStack.top() == '(')
                {
                    bracecStack.pop();
                    continue;
                }
                break;
            }

            // {}
            if(expression[i] == '}')
            {
                if(bracecStack.top() == '{')
                {
                    bracecStack.pop();
                    continue;
                }
                break;
            }

            // []
            if(expression[i] == ']')
            {
                if(bracecStack.top() == '[')
                {
                    bracecStack.pop();
                    continue;
                }
                break;
            }
        }
    }
    return bracecStack.empty();
}
}//namespace functions
