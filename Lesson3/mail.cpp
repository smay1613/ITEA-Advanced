#include <string>
#include <iostream>

bool isValid(const std::string & value) {
    int coefficient = 0;
    for (const char & c : value) {
        if (c == ')') {
            --coefficient;
        } else if (c == '(') {
            ++coefficient;
        }
        if (0 > coefficient) {
            return false;
        }
    }
    return !coefficient;    
}

int main() {
    std::cout << "Task 1" << std::endl;
    
    std::string v1 = "()";
    std::string v2 = ")(";
    std::string v3 = "((()()())()())";
    std::string v4 = "())(";
    
    std::cout << isValid(v1) << std::endl;
    std::cout << isValid(v2) << std::endl;
    std::cout << isValid(v3) << std::endl;
    std::cout << isValid(v4) << std::endl;
    
    return 0;
}
