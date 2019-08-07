#include <iostream>
#include <stack>

bool isExpressionValid (const std::string& expression)
{
    std::stack<char> result {};
    for (size_t i = 0; i < expression.length(); ++i)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            result.push(expression[i]);
        } 
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if
            (
                result.empty() 
                ||((expression[i] == ')') ^ (result.top() == '(')) 
                ||((expression[i] == '}') ^ (result.top() == '{'))
                ||((expression[i] == ']') ^ (result.top() == '['))
            )
            {
                return false;
            }
            result.pop();
        }
    }
    return result.empty();
}

int main()
{
    std::string some_data {"({[([ )])]})"};
    std::cout << 
        (isExpressionValid(some_data) ? 
        "Parenthesis balance saved":
        "Parenthesis balance don`t saved") 
    << std::endl;
}