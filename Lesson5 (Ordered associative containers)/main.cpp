#include "tst_hw_3_tests.h"

#include <gtest/gtest.h>

struct caseInsensitiveComparator {
    bool operator()(const std::string& lhs, const std::string& rhs) const {
            if (lhs.size() != rhs.size()) {
                return true;
            }

            for (size_t i = 0; i < rhs.size(); ++i) {
                if (std::toupper(lhs[i]) != std::toupper(rhs[i])) {
                    return true;
                }
            }

            return false;
    }
};

std::vector<std::string> getUniqueWords (const std::string& text)
{
    std::set<std::string, caseInsensitiveComparator> uniqueWords;

    std::string modifiedText {text};
    modifiedText.erase(std::remove_if(modifiedText.begin(), modifiedText.end(), ispunct), modifiedText.end());

    for(auto currentIt = modifiedText.begin(), lastWordStartIt = modifiedText.begin();
        currentIt != modifiedText.end(); ++currentIt)
    {
        if (*currentIt == ' ' || (currentIt == modifiedText.end() - 1))
        {
            size_t position = std::distance(modifiedText.begin(), lastWordStartIt);
            size_t letterCount = std::distance(lastWordStartIt, currentIt);

            if(currentIt == modifiedText.end() - 1)
            {
                letterCount += 1;
            }

            uniqueWords.insert(modifiedText.substr(position, letterCount));

            lastWordStartIt = currentIt + 1;
        }
    }

    std::vector<std::string> wordsVector (uniqueWords.begin(), uniqueWords.end());

    return  wordsVector;
}

std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text)
{
    std::map<std::string, size_t, caseInsensitiveComparator> uniqueWordsCounter;

    std::string modifiedText {text};
    modifiedText.erase(std::remove_if(modifiedText.begin(), modifiedText.end(), ispunct), modifiedText.end());

    for(auto currentIt = modifiedText.begin(), lastWordStartIt = modifiedText.begin();
        currentIt != modifiedText.end(); ++currentIt)
    {
        if (*currentIt == ' ' || (currentIt == modifiedText.end() - 1))
        {
            size_t position = std::distance(modifiedText.begin(), lastWordStartIt);
            size_t letterCount = std::distance(lastWordStartIt, currentIt);

            if(currentIt == modifiedText.end() - 1)
            {
                letterCount += 1;
            }

            auto insertionCheck = uniqueWordsCounter.insert({modifiedText.substr(position, letterCount), 1});

            if(insertionCheck.second == false)
            {
                insertionCheck.first->second += 1;
            }

            lastWordStartIt = currentIt + 1;
        }
    }

    std::vector<std::pair<std::string, size_t>> wordsVector (uniqueWordsCounter.begin(), uniqueWordsCounter.end());

    return  wordsVector;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
