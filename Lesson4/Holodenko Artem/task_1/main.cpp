#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>


std::vector<std::string> getUniqueWords(const std::string& text)
{
    std::set<std::string> words_set;
    std::string word;
    std::stringstream str_stream;

    str_stream << text;
    while(!str_stream.eof())
    {
        str_stream >> word;
        words_set.insert(word);
    }

    std::vector<std::string> words_vector {words_set.begin(), words_set.end()};

    return words_vector;
}

int main()
{
    std::string text = "a b c d  e a  a ";

    for (const auto & element : getUniqueWords(text))
    {
        std::cout << element << std::endl;
    }

    return 0;
}
