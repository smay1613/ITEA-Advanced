#include <stack>
#include <string>
#include <map>

inline char OpositBracket(const char BRACKET) {
  std::map<char, char> bracketsMap {{'(',')'},{'[',']'},{'{','}'}};
  return bracketsMap.at(BRACKET);
}

bool isExpressionValid (const std::string& expression) {
  std::stack<char> bracketsStack;
  for (char bracket : expression) {
    if (bracket == '(' ||
        bracket == '[' ||
        bracket == '{') {
      bracketsStack.push(bracket);
    } else {
      if (bracketsStack.empty()) {return false;}
      if (bracket != OpositBracket(bracketsStack.top())) {
        return false;
      }
      bracketsStack.pop();
    }
  }
  return bracketsStack.empty();
}

