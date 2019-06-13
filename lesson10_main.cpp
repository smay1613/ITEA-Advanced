#include <iostream>
#include <string>
#include <cassert>
#include <deque>
#include <stack>
#include <sstream>
#include <algorithm>
#include <iterator>

void reverse_text (std::string& text)
{
    //1) split to words
    std::istringstream test_stream {text};
    std::deque<std::string> text_in_words {};
    std::string word {};
    while ( test_stream >> word ) {
        text_in_words.push_front(std::move(word));
    }

    //2) reversing
    std::ostringstream result_stream{};
    std::copy(std::make_move_iterator(text_in_words.begin()),
              std::make_move_iterator(text_in_words.end()),
              std::ostream_iterator<std::string>(result_stream, " "));

    text = result_stream.str();
    std::cout << *text_in_words.begin() << std::endl;
}

int main()
{
    std::string test_str1 { "Test1 Test2 Test3" };
    std::string reverse_test_str1 { "Test3 Test2 Test1 "};
    reverse_text (test_str1);
    assert(test_str1 == reverse_test_str1);

    std::cout << "Ok!!" << std::endl;
    return 0;
}
