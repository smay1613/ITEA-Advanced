#include <iostream>
#include <vector>

#include "ht1_1head.h"
#include "ht1_1lib.cpp"

int main ()
{
    size_t SizeOfFirstVector;
    std::cout << "Enter size of first vector: ";
    std::cin >> SizeOfFirstVector;
    std::vector<int> FirstVector(SizeOfFirstVector);
    EnterElements(FirstVector, SizeOfFirstVector);
    std::cout << "First vector: [ ";
    ShowElements(FirstVector, SizeOfFirstVector);
    std::cout << "]" << std::endl << std::endl;

    size_t SizeOfSecondVector;
    std::cout << "Enter size of second vector: ";
    std::cin >> SizeOfSecondVector;
    std::vector<int> SecondVector(SizeOfSecondVector);
    EnterElements(SecondVector, SizeOfSecondVector);
    std::cout << "Second vector: [ ";
    ShowElements(SecondVector, SizeOfSecondVector);
    std::cout << "]" << std::endl << std::endl;

    size_t SizeOfLastVector = SizeOfFirstVector + SizeOfSecondVector;
    std::vector<int> LastVector(SizeOfLastVector);
    UniteVectors(LastVector, FirstVector, SecondVector, SizeOfFirstVector, SizeOfLastVector);
    std::cout << "Last vector: [ ";
    ShowElements(LastVector, SizeOfLastVector);
    std::cout << "]" << std::endl << std::endl;

    return 0;
}
