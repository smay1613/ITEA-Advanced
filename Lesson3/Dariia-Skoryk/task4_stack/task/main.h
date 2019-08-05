#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <exception>

bool isExpressionValid(const std::string & expression) {
    //smth
    bool result = true;
    std::stack<char> openBrackets;
    for (const char entry: expression) {
        switch (entry) {
            case '(':
            {
                openBrackets.push('(');
                break;
            }
            case '{':
            {
                openBrackets.push('{');
                break;
            }
            case '[':
            {
                openBrackets.push('[');
                break;
            }
            case ')':
            {
                if ((!openBrackets.empty()) && (openBrackets.top() == '(')) {
                    openBrackets.pop();
                }
                else {
                    result = false;
                }
                break;
            }
            case '}':
            {
                if (!openBrackets.empty() && openBrackets.top() == '{') {
                    openBrackets.pop();
                }
                else {
                    result = false;
                }
                break;
            }
            case ']':
            {
                if (!openBrackets.empty() && openBrackets.top() == '[') {
                    openBrackets.pop();
                }
                else {
                    result = false;
                }
                break;
            }
            default: {
                result = false;
                throw std::invalid_argument("Message: string is not sequence of brackets");
            }
        }
    }
    if (!openBrackets.empty())
        result = false;
    return result;
}
