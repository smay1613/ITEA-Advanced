#include <forward_list>
#include <string>

inline char OpositBracket(const char BRACKET) {
  if (BRACKET == '(') {return ')';}
  if (BRACKET == '[') {return ']';}
  if (BRACKET == '{') {return '}';}
  return 0;
}

bool isExpressionValid (const std::string& EXPRESSION) {
  std::forward_list<char> flist_brackets;
  const size_t EXPRESSION_SIZE = EXPRESSION.size();
  for (size_t position = 0; position < EXPRESSION_SIZE; ++position) {
    char bracket = EXPRESSION.at(position);
    if (bracket == '(' ||
        bracket == '[' ||
        bracket == '{') {
      flist_brackets.push_front(bracket);
    } else {
      if (flist_brackets.empty()) {return false;}
      if (bracket != OpositBracket(flist_brackets.front())) {
        return false;
      }
      flist_brackets.pop_front();
    }
  }
  return flist_brackets.empty();
}

