#include <iostream>
#include <list>
#include <cmath>

#include "HT1_2head.hpp"

template <typename T>
void TakeNumbers(T Exponent, T Basis, std::list<T>& OutList){
    for (auto i = 1; i <= Exponent; ++i){
        T var = pow (Basis, i);
        T firstNumber = var;
        while(firstNumber >= 10){
            firstNumber /= 10;
        };
        T lastNumber = var%10;
        OutList.push_back(firstNumber);
        OutList.push_back(lastNumber);
    }
}

template <typename T>
void ShowResult(std::list<T>& OutList){
    for (auto i = OutList.begin(); i != OutList.end(); ++i){
        std::cout << *i << " ";
    }
}

int main ()
{
    size_t Basis;
    size_t Exponent;

    std::cout << "Enter BASIS: ";
    std::cin >> Basis;

    std::cout << "Enter EXPONENT: ";
    std::cin >> Exponent;
    std::list<size_t> OutList;
    TakeNumbers (Exponent, Basis, OutList);
    std::cout << "Out list is [ ";
    ShowResult (OutList);
    std::cout << "]." << std::endl;


    return 0;
}
