#include <../include/functions.h>
#include <stack>
namespace functions
{
bool isExpressionValid(const std::string &expression)
{
    std::stack <char> bracecStack{};

    for(const auto &brace : expression)
    {
        if(brace == '(' || brace == '{' || brace == '[')
        {
            bracecStack.push(brace);
        }

        if(bracecStack.empty())
        {
            return false;
        }

        if(!bracecStack.empty())
        {
            // ()
            if(brace == ')')
            {
                if(bracecStack.top() == '(')
                {
                    bracecStack.pop();
                }
            }

            // {}
            if(brace == '}')
            {
                if(bracecStack.top() == '{')
                {
                    bracecStack.pop();
                }
            }

            // []
            if(brace == ']')
            {
                if(bracecStack.top() == '[')
                {
                    bracecStack.pop();
                }
            }
        }
    }
    return bracecStack.empty();
}
}//namespace functions
