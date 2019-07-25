#include <iostream>
#include <stack>
#include <string>

void print_stack(std::stack<char> stack)
{
    while(!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

std::stack<char> string_to_stack(std::string *_str)
{
    std::stack<char> data_stack;
    const char* str = _str->c_str();
    const size_t size =  _str->size();

    for (size_t i=0; i< size; i++)
    {
        data_stack.push(str[size-i-1]);
    }

    return data_stack;
}

bool func(std::stack<char> stack)
{
    int x = 0;

    while(!stack.empty())
    {
        if (stack.top()=='(')
        {
            x++;
        }
        else if (stack.top()==')')
        {
            x--;
        }

        //std::cout << x << std::endl;

        if (x < 0)
        {
            return false;
        }

        stack.pop();
    }
    if (x!=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    std::string data_str;

    std::cin >> data_str;

    std::stack<char> data_stack {std::move(string_to_stack(&data_str))};
    print_stack(data_stack);
    std::cout << func(data_stack) << std::endl;

    return 0;
}
