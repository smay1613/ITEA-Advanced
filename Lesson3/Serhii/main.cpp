#include <string>
#include <stack>
#include <iostream>

const char getInversion(const char & value) {
    if (value == ')') {
        return '(';
    } else if (value == '}') {
        return '{';
    } else if (value == ']') {
        return '[';
    } else {
        return 0x00;
    }
}

bool isValid(const std::string & value) {
    std::stack<char> stack;
    for (const char & c : value) {
        if (c == '(' || c == '{' ||  c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' ||  c == ']') {
            if (stack.empty() || stack.top() != getInversion(c)) {
                return false;
            }
            stack.pop();
        }
    }
    return true;
}

int main() {
    std::cout << "Task 1" << std::endl;
    std::string v1 = "()";
    std::string v2 = ")(";
    std::string v3 = "((()()())()())";
    std::string v4 = "())(";
    std::string v5 = "[()]{}{()()}";
    std::string v6 = "[(])";
    std::cout << isValid(v1) << std::endl;
    std::cout << isValid(v2) << std::endl;
    std::cout << isValid(v3) << std::endl;
    std::cout << isValid(v4) << std::endl;
    std::cout << isValid(v5) << std::endl;
    std::cout << isValid(v6) << std::endl;

    return 0;
}
