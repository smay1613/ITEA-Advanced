#include <iostream>
#include <list>
#include <cmath>

#include "ht1_2head.h"
#include "ht1_2lib.cpp"

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
