#include <iostream>
#include <set>
#include <vector>
#include <string>


std::vector<std::string> getUniqueWords(const std::string& text)
{
    std::vector<std::string> words_vector;
    std::set<std::string> words_set;
    std::string word;

    for (const auto & element : text)
    {
        if (!ispunct(element) && element != ' ')
        {
            word += tolower(element);
        }
        else
        {
            if (!word.empty())
            {
                words_set.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty())
    {
        words_set.insert(word);
    }

    for (const auto & element : words_set)
    {
        words_vector.push_back(element);
    }

    return words_vector;
}

int main()
{
    std::string text = "a b c d e";

    for (const auto & element : getUniqueWords(text))
    {
        std::cout << element << std::endl;
    }

    return 0;
}
