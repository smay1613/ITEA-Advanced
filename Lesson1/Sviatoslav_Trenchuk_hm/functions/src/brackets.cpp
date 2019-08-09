#include "brackets.h"
#include <vector>
#include <stack>
#include <iostream>

bool areAllBracketsClosed(const std::string& inputString)
{
  std::vector<char> brackets {};
  for (auto &value : inputString) {
    brackets.push_back(value);
  }

  bool closedBracketsCheck = false;

  if (brackets.size() != 0) {

    std::stack<char, std::vector<char>> bracketsStack {};
    int counter {};

    if (*brackets.begin() == ')' || *brackets.begin() == '}' || *brackets.begin() == ']') {
      return false;
    } else if (brackets.back() == '(' || brackets.back() == '{' || brackets.back() == '[') {
      return false;
    } else {
      for (auto &value : brackets) {
        bracketsStack.push(value);
        if (bracketsStack.top() == '(') {
          ++counter;
        } else if (bracketsStack.top() == '{') {
          counter += 2;
        } else if (bracketsStack.top() == '[') {
          counter += 3;
        } else if (bracketsStack.top() == ')') {
            --counter;
        } else if (bracketsStack.top() == '}') {
          counter -= 2;
        } else if (bracketsStack.top() == ']') {
          counter -= 3;
        }
      }
    }
    if (counter == 0) {
      closedBracketsCheck = true;
    } else {
      closedBracketsCheck = false;
    }
  } else {
    std::cout << "There is no input";
  }
  return closedBracketsCheck;
}
