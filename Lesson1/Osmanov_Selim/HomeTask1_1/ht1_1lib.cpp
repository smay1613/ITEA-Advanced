#pragma once
#include <vector>
#include <iostream>

void EnterElements(std::vector<int>& FirstVector, size_t SizeOfFirstVector){
    for (size_t i = 0; i < SizeOfFirstVector; ++i){
        std::cout << "Enter element № " << i+1 << ":";
        std::cin >> FirstVector[i];
    }
}

void ShowElements(std::vector<int> FirstVector, size_t SizeOfFirstVector){
    for (size_t i = 0; i < SizeOfFirstVector; ++i){
        std::cout << FirstVector[i] << " ";
    }
}

void UniteVectors(std::vector<int>& LastVector, std::vector<int> FirstVector, std::vector<int> SecondVector, size_t SizeOfFirstVector, size_t SizeOfLastVector){
    for (size_t i = 0; i < SizeOfFirstVector; ++i){
        LastVector[i] = FirstVector[i];
    }
    for (size_t i = SizeOfFirstVector; i < SizeOfLastVector; ++i){
        LastVector[i] = SecondVector[i - SizeOfFirstVector];
    }
}
