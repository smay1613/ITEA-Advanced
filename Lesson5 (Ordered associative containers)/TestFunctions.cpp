#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>
#include "cctype"



std::vector<std::string> getUniqueWords (const std::string& text)
{
    std::string copyText = text;
    std::set<std::string> setOfWords;
    std::replace_if(copyText.begin(), copyText.end(), [](unsigned char c){ return std::ispunct(c); }, ' ');
    std::stringstream streamText(copyText);
    while (streamText >> copyText)
    {
        std::transform(copyText.begin(), copyText.end(), copyText.begin(), tolower);
        setOfWords.insert(copyText);
    }
    std::vector<std::string> outpVector(std::make_move_iterator(setOfWords.begin()),
                                        std::make_move_iterator(setOfWords.end()));

    return outpVector;
}

std::vector<std::pair<std::string,size_t>> wordCounter (const std::string& text)
{
    std::string copyText = text;
    std::map<std::string,size_t> mapOfWords;
    std::replace_if(copyText.begin(), copyText.end(), [](unsigned char c){ return std::ispunct(c); }, ' ');
    std::stringstream streamText(copyText);
    while (streamText >> copyText)
    {
        std::transform(copyText.begin(), copyText.end(), copyText.begin(), tolower);
        auto it = mapOfWords.insert(std::pair<std::string,size_t>(copyText,1));
        if (!it.second)
        {
            mapOfWords[copyText]++;
        }

    }

    return std::vector<std::pair<std::string,size_t>>(std::make_move_iterator(mapOfWords.begin()),
                                                      std::make_move_iterator(mapOfWords.end()));

}
