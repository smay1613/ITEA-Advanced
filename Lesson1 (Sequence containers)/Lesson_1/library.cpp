#include <iostream>
#include "library.h"



std::vector<int> combineVectors (const std::vector<int>::iterator& begin1, const std::vector<int>::iterator& end1, const std::vector<int>::iterator& begin2, const std::vector<int>::iterator& end2)
{
    ulong size = (end1 - begin1) + (end2 - begin2);
    std::vector<int> tmp;
    tmp.reserve(size);
    tmp.insert(tmp.begin(), begin1, end1);
    tmp.insert(tmp.end(),begin2, end2);

    return tmp;
};

size_t magicNumber(const size_t number, const size_t degree)
{
    size_t wantedNumber = 0;
    std::list<int> numbers;
    numbers.push_back(number);

    for (auto&& it = numbers.begin(); it != numbers.end(); ++it) {
        if (numbers.size() < degree)
            numbers.push_back(*(--numbers.end()) * *(numbers.begin()));

        int first = *it;
        int last = (*it) % 10;

        while (first > 10)
            first /= 10;

        wantedNumber = wantedNumber * 100 + first * 10 + last;
    }

    return wantedNumber;
};

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> tmp_list;

    while (!listToReverse.empty())
    {
        tmp_list.push_front(*listToReverse.begin());
        listToReverse.pop_front();
    }

    tmp_list.swap(listToReverse);
};
