#include <iostream>
#include <vector>

#include "HT1_1head.h"

template <typename T>
void ShowElements(std::vector<T>const& FirstVector){
    for (const auto &element : FirstVector){
        std::cout << element << " ";
    }
}

template <typename T>
void UniteVectors(std::vector<T>& UnitedVectors, std::vector<T>const& FirstVector,
                  std::vector<T>const& SecondVector){
    UnitedVectors.resize(FirstVector.size() + SecondVector.size());
    for (auto i = 0; i < FirstVector.size(); ++i){
        UnitedVectors[i] = FirstVector[i];
    }
    for (auto i = FirstVector.size(); i < UnitedVectors.size(); ++i){
        UnitedVectors[i] = SecondVector[i - FirstVector.size()];
    }
}

int main ()
{
    std::vector<int> FirstVector {7, 8, 3, 6};
    std::cout << "First vector: [ ";
    ShowElements(FirstVector);
    std::cout << "]" << std::endl << std::endl;

    std::vector<int> SecondVector {12, 43, 9};
    std::cout << "Second vector: [ ";
    ShowElements(SecondVector);
    std::cout << "]" << std::endl << std::endl;

    std::vector<int> UnitedVectors;
    UniteVectors (UnitedVectors, FirstVector, SecondVector);

    std::cout << "United vector: [ ";
    ShowElements(UnitedVectors);
    std::cout << "]" << std::endl << std::endl;

    return 0;
}



