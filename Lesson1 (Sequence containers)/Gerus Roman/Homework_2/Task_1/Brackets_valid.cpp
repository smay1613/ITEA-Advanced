#include <iostream>
#include <stack>

bool bracketsCheck (std::stack<char> & stack_with_brackets) {
  int circleBracket_count = 0;
  int figureBracket_count = 0;
  int squareBracket_count = 0;

  while (!stack_with_brackets.empty()) {
      if (stack_with_brackets.top() == *"(") {
            --circleBracket_count;
            stack_with_brackets.pop();
        } else if (stack_with_brackets.top() == *")") {
          ++circleBracket_count;
          stack_with_brackets.pop();
        } else if (stack_with_brackets.top() == *"[") {
          --squareBracket_count;
          stack_with_brackets.pop();
        } else if (stack_with_brackets.top() == *"]") {
          ++squareBracket_count;
          stack_with_brackets.pop();
        } else if (stack_with_brackets.top() == *"{") {
          --figureBracket_count;
          stack_with_brackets.pop();
        } else if (stack_with_brackets.top() == *"}") {
          ++figureBracket_count;
          stack_with_brackets.pop();
        } else {
          stack_with_brackets.pop();
        }
      if (circleBracket_count < 0 || figureBracket_count < 0 || squareBracket_count < 0) {
          break;
        }
    }
  if (circleBracket_count == 0 &&
      figureBracket_count == 0 &&
      squareBracket_count == 0) {
      return true;
    } else {
      return false;
    }
}

bool isExpressionValid (const std::string & expression) {
  std::stack<char> expressionStack {};
  for (size_t i = 0; i < expression.size(); ++i) {
      expressionStack.push(expression[i]);
    }
  return bracketsCheck(expressionStack);
}

int main()
{
  std::cout << "Enter your string: ";
  std::string user_string {};
  std::cin >> user_string;
  if (isExpressionValid(user_string) == true) {
      std::cout << "All brackets are closed" << std::endl;
    } else {
      std::cout << "Brackets aren't closed!" << std::endl;
    }
  return 0;
}

