#include "Utils.h"
#include <vector>
#include <string>
#include <forward_list>
#include <list>

namespace avprocessing
{
    namespace utilities
    {
    //Task1 ---------------------------------------------------------------------------
    std::vector<int> combineVectors(const std::vector<int>::iterator vectorFirstBegin, const std::vector<int>::iterator vectorFirstEnd,
                                    const std::vector<int>::iterator vectorSecondBegin, const std::vector<int>::iterator vectorSecondEnd){
        std::vector<int>tmp {vectorFirstBegin,vectorFirstEnd};
        tmp.insert(tmp.end(), vectorSecondBegin, vectorSecondEnd);
        return tmp;
    }
    std::vector<int> combineVectors(std::vector<int> firstVec, std::vector<int> secondVec){
        std::vector<int>vectorFirst{firstVec};
        std::vector<int>vectorSecond{secondVec};
        std::vector<int>vectorFirstPlusSecond {combineVectors(vectorFirst.begin(), vectorFirst.end(),
                                                              vectorSecond.begin(),vectorSecond.end())};
        return vectorFirstPlusSecond;
    }
    //Task2 ---------------------------------------------------------------------------
    size_t magicNumber(const size_t  m_number, const size_t  m_degree){
        size_t degree{m_degree};
        size_t number{m_number};
        if (number < 0)
            number *= -1;
        std::list<size_t>resultList;
        size_t result{0};
        int numberDegree = 1;
        for (int i = 1; i<=degree; i++){
            int tmpFirstNumber{};
            int tmpSecondNubmer{};
            numberDegree *= number;
            if(numberDegree > 9){
                tmpFirstNumber = numberDegree;
                tmpSecondNubmer = numberDegree % 10;
                while (tmpFirstNumber > 9) {
                    tmpFirstNumber /= 10;
                }
                resultList.push_back(tmpFirstNumber *10 + tmpSecondNubmer);
            }
            else{
                tmpFirstNumber = numberDegree;
                resultList.push_back(tmpFirstNumber);
            }
        }
        for(const auto &value: resultList){
            if(value<10){
                result*= 10;
            }
            else{
                result*= 100;
            }
            result += value;
        }
        return result;
    }

    //Task3 ---------------------------------------------------------------------------
    void reverse(std::forward_list<int> & m_ForvardList){
        std::forward_list<int>reverseForvardListData;
        for(const auto &value: m_ForvardList){
            reverseForvardListData.push_front(value);
        }
        const std::forward_list<int> returnlist{reverseForvardListData};
        reverseForvardListData.swap(m_ForvardList);

    }
    }
}
