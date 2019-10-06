#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include "cctype"



std::vector<std::string> getUniqueWords (const std::string& text)
{
    std::vector<std::string> outpVector;
    std::string copyText = text;
    std::set<std::string> setOfWords;
    std::replace_if(copyText.begin(), copyText.end(), [](unsigned char c){ return std::ispunct(c); }, ' ');
    std::stringstream streamText(copyText);
    while (streamText >> copyText)
    {
        std::transform(copyText.begin(), copyText.end(), copyText.begin(), tolower);
        auto it = setOfWords.insert(copyText);
        if (it.second == true)
        {
            outpVector.emplace_back(copyText);
        }
    }

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
            mapOfWords[copyText] += 1;
        }

    }

    return std::vector<std::pair<std::string,size_t>>(mapOfWords.begin(),mapOfWords.end());

}
