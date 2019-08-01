#include <iostream>
#include <stack>
#include <string>


struct bracket
{
    bracket(size_t _type) : type(_type)
    {}
    size_t type;
    size_t number = 1;
};

bool is_expression_valid(const std::string &str)
{
    std::stack<bracket> data_stack;
    if (str.empty())
    {
        return false;
    }
    else
    {
        for (const char& c : str)
        {
            switch (c)
            {
                case '(':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{0});
                    }
                break;
                case ')':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '[':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{1});
                    }
                break;
                case ']':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '{':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{2});
                    }
                break;
                case '}':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
            }
        }

        if (!data_stack.empty())
        {
            return false;
        }

        else
        {
            return true;
        }
    }
}

int main()
{
    std::string data_str;

    std::cin >> data_str;

    std::cout << is_expression_valid(data_str) << std::endl;

    return 0;
}
