#include <iostream>
#include <vector>
#include <list>

std::vector<int> compoundVectors(std::vector<int>::iterator vectorFirstBegin, std::vector<int>::iterator vectorFirstEnd,
                                std::vector<int>::iterator vectorSecondBegin, std::vector<int>::iterator vectorSecondEnd) {
    std::vector<int>tmp {vectorFirstBegin,vectorFirstEnd};
    tmp.insert(tmp.end(), vectorSecondBegin, vectorSecondEnd);
    return tmp;
}

int main()
{
    {
//--Task1----------------------------------------------------------------------------------------------------------------------------
    std::cout <<"Task 1-------------------------"<<std::endl;
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
    }
//--Task2----------------------------------------------------------------------------------------------------------------------------
  {
    std::cout << std::endl<<std::endl<<"Task 2----------------------"<<std::endl;
    int X;
    int N;
    std::cout <<"Enter N: ";
    std::cin >> N;
    std::cout <<"Enter X: ";
    std::cin >> X;
    std::list<int>result;
    int numberDegree = 1;
    for (int i = 1; i<=X; i++){
        numberDegree *= N;
        int tmpFirstNumber = numberDegree;
        int tmpSecondNubmer = numberDegree % 10;
        while (tmpFirstNumber > 9) {
            tmpFirstNumber /= 10;
        }
        result.push_back(tmpFirstNumber *10 + tmpSecondNubmer);
    }
    for(const auto &value: result){
        std::cout << value;
    }
}
//--Task3----------------------------------------------------------------------------------------------------------------------------
{
        std::cout << std::endl<<std::endl<<"Task 3----------------------"<<std::endl;
        std::forward_list<int>myForvardList{10,20,30,40,50};
        std::forward_list<int>reverseForvardList;
        std::cout <<"myForvardList:\t\t";
        for(const auto &value: myForvardList){
            reverseForvardList.push_front(value);
            std::cout<< value <<" ";
            }
        std::cout << std::endl <<"reverseForvardList:\t";
        for(const auto &value: reverseForvardList){
            std::cout<< value << " ";
        }
        myForvardList = reverseForvardList;
        std::cout << std::endl <<"myForvardList: \t\t";
        for(const auto &value: myForvardList){
            std::cout<< value << " ";
        }
}



    return 0;
}
