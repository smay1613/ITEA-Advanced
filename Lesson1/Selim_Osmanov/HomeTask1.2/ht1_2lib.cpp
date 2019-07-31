#include <iostream>
#include <list>
#include <cmath>
void TakeNumbers(size_t Exponent, size_t Basis, std::list<size_t>& OutList){
    for (size_t i = 1; i <= Exponent; ++i){
        size_t var = pow (Basis, i);
        size_t firstNumber = var;
        while(firstNumber >= 10){
            firstNumber /= 10;
        };
        size_t lastNumber = var%10;
        OutList.push_back(firstNumber);
        OutList.push_back(lastNumber);
    }
}

void ShowResult(std::list<size_t>& OutList){
    for (std::list<size_t>::iterator i = OutList.begin(); i != OutList.end(); ++i){
        std::cout << *i << " ";
    }
}
