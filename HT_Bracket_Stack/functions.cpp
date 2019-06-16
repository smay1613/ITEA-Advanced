#include "functions.h"

void check_brackets()
{
    std::stack<char> brackets;
    std::string text;
    std::cout << "Please enter text:";
    std::cin >> text;

    int break_point{0};
    for(size_t i{0}; i < text.length(); i++)
    {
        if(text[i] == '{' || text[i] == '[' || text[i] == '(')
        {
            brackets.push(text[i]);
            break_point = 1;
        }
        if(!brackets.empty())
        {
            if(text[i] == '}')
            {
                if(brackets.top() == '{')
                {
                    brackets.pop();
                    continue ;
                }
                break;
            }
            if(text[i] == ']')
            {
                if(brackets.top() == '[')
                {
                    brackets.pop();
                    continue ;
                }
                break;
            }
            if(text[i] == ')')
            {
                if(brackets.top() == '(')
                {
                    brackets.pop();
                    continue ;
                }
                break;
            }
        }
    }

    if((brackets.empty()) && (break_point == 1))
        std::cout<< "true" <<std::endl ;
    else
        std::cout<< "false" <<std::endl ;
}
