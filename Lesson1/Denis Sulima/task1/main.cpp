#include <iostream>
#include <vector>
std::vector<int> compoundVectors(std::vector<int>::iterator vectorFirstBegin, std::vector<int>::iterator vectorFirstEnd,
                                std::vector<int>::iterator vectorSecondBegin, std::vector<int>::iterator vectorSecondEnd) {
    std::vector<int>tmp {vectorFirstBegin,vectorFirstEnd};
    tmp.insert(tmp.end(), vectorSecondBegin, vectorSecondEnd);
    return tmp;
}

int main()
{
    std::vector<int>vectorFirst{ 1,2,3,4,5 };
    std::vector<int>vectorSecond{ 7,8,9,10,11 };
    std::vector<int>vectorFirstPlusSecond {compoundVectors(vectorFirst.begin(), vectorFirst.end(),
                                                          vectorSecond.begin(),vectorSecond.end())};
    for (const auto &value : vectorFirst) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    for (const auto &value : vectorSecond) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    for (const auto &value : vectorFirstPlusSecond) {
        std::cout << value << " ";
    }

    return 0;
}
