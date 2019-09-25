#include <iostream>
#include <vector>
#include <forward_list>
#include <list>


std::vector<int> combineVectors(std::vector<int>::const_iterator begin1, std::vector<int>::const_iterator end1,
                            std::vector<int>::const_iterator begin2,
                            std::vector<int>::const_iterator end2)
{
    std::vector<int> resultVector;
    resultVector.reserve((std::distance(begin1,end1)+std::distance(begin2,end2)));
    resultVector.insert(resultVector.end(), begin1, end1);
    resultVector.insert(resultVector.end(), begin2, end2);
    return resultVector;
}

size_t magicNumber(const size_t digit, const size_t num)
{
    std::vector<size_t> VectorOfDig;
    size_t resultDigit = 0;
    std::list<size_t> resultList;
    VectorOfDig.reserve(num);
    for(size_t i = 0; i < num; i++)
    {
        if(i == 0)
        {
            VectorOfDig.push_back(digit);
        }
        else
        {   size_t element = (*(VectorOfDig.end()-1))*digit;
            VectorOfDig.push_back(element);
        }
    }
    for(auto number : VectorOfDig)
    {
        std::list<size_t> ListOfDig;
        while (number > 0)
        {
            size_t digit = number%10;
            ListOfDig.push_back(digit);
            number /= 10;
        }
        resultList.push_back(ListOfDig.back());
        resultList.push_back(ListOfDig.front());

    }
    size_t count{1};
    for( std::list<size_t>::reverse_iterator it = resultList.rbegin(); it!= resultList.rend(); it++)
    {
       resultDigit += (*it)*count;
       count *= 10;
    }
   return resultDigit;
    \
}

void reverse(std::forward_list<int>& listToReverse)
{

    std::forward_list<int> reverseList{};
    for(auto& element : listToReverse)
    {
        reverseList.push_front(element);
    }
    listToReverse.swap(reverseList);

}

