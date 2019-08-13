#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>


std::vector<std::pair<std::string, size_t>> wordCounter(const std::string& text)
{
    std::vector<std::pair<std::string, size_t>> words_vector;
    std::map<std::string, size_t> words_map;
    std::string word;
    std::stringstream str_stream;

    str_stream << text;
    while(!str_stream.eof())
    {
        str_stream >> word;
        if (words_map.empty())
        {
            words_map.insert(std::make_pair(word, 1));
            word.clear();
        }
        else
        {
            std::map<std::string, size_t>::iterator element = words_map.find(word);

            if (element != words_map.end())
            {
                element->second++;
                word.clear();
            }
            else {
                words_map.insert(std::make_pair(word, 1));
                word.clear();
            }
        }
    }

    for (const auto & element : words_map)
    {
        words_vector.push_back(element);
    }

    return words_vector;
}

int main()
{
    std::vector<std::pair<std::string, size_t>> data;
    std::string text = "a a a a a a a b b c d a";

    data = wordCounter(text);

    for (const auto & element : data)
    {
       std::cout << element.first << " " << element.second << std::endl;
    }


    return 0;
}
