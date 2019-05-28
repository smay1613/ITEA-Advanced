#include <iostream>
#include <stack>
#include <cassert>
#include <exception>


bool is_valid (const std::string& text)
{
    std::stack<char> text_stack {};

    for (const auto& bracket: text) {
        if (bracket == '(') {
            text_stack.push (bracket);
        }
        else if (bracket == ')') {
            if (!text_stack.empty()) {
                text_stack.pop();
            }
            else {
                return false;
            }
        }
        else {
            throw std::logic_error("Bad symbol!");
        }
    }

    if (text_stack.empty()) {
        return true;
    }

    return false;
    //NOTE: я бы использовал тут просто int, и проверял бы "int < 0" и "int == 0"
}


int main()
{
    std::string valid_str1 {"()"};
    std::string valid_str2 {"((()()())()())"};

    std::string invalid_str1 {")("};
    std::string invalid_str2 {"())("};

    try {
        assert (is_valid (valid_str1));
        assert (is_valid (valid_str2));

        assert (is_valid (invalid_str1) == false);
        assert (is_valid (invalid_str2) == false);

        std::cout << "All tests are valid!" << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << std::endl << "ERROR! Take exception: " << ex.what() << std::endl;
    }

    return 0;
}
