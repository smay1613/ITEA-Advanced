#pragma once
#include <vector>
#include <iostream>

void EnterElements(std::vector<int>& FirstVector, size_t SizeOfFirstVector);
void ShowElements(std::vector<int> FirstVector, size_t SizeOfFirstVector);
void UniteVectors(std::vector<int>& LastVector, std::vector<int> FirstVector,
                  std::vector<int> SecondVector, size_t SizeOfFirstVector,
                  size_t SizeOfLastVector);
