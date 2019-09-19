#include <iostream>
#include <vector>
#include <forward_list>


std::vector<int> combineVectors(std::vector<int>::const_iterator begin1, std::vector<int>::const_iterator end1,
                            std::vector<int>::const_iterator begin2,
                            std::vector<int>::const_iterator end2)
{
    std::vector<int> v;
    v.reserve((std::distance(begin1,end1)+std::distance(begin2,end2)));
    v.insert(v.end(), begin1, end1);
    v.insert(v.end(), begin2, end2);
    return v;
}

size_t magicNumber(const size_t digit, const size_t num)
{
    std::vector<size_t> v;
    v.reserve(num);
    for(size_t i = 0; i < num; i++)
    {
        if(i == 0)
        {
            v.push_back(digit);
        }
        else
        {   size_t element = (*(v.end()-1))*digit;
            v.push_back(element);
        }
    }



    std::vector<size_t> resultVect;
    size_t resultDigit {0};
    resultVect.reserve(20);
   for(std::vector<size_t>::const_iterator it = v.begin(); it!=v.end(); it++)
   {
       size_t n = *it;
       size_t lastDigit = n % 10;
       while (n >= 10)
            n /= 10;
       size_t firstDigit = n;
       resultVect.push_back(firstDigit);
       resultVect.push_back(lastDigit);
    }

   size_t count{1};
   for( std::vector<size_t>::reverse_iterator it = resultVect.rbegin(); it!= resultVect.rend(); it++)
   {
       resultDigit += (*it)*count;
       count *= 10;
   }


   return resultDigit;


}

void reverse(std::forward_list<int>& listToReverse)
{
    std::forward_list<int> reverseList{};
    while(!listToReverse.empty())
    {
        int a = listToReverse.front();
        reverseList.push_front(a);
        listToReverse.pop_front();
    }
    listToReverse.splice_after(listToReverse.before_begin(),reverseList);
}

