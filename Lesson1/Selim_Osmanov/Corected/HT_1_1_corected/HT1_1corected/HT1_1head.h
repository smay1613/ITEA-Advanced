#pragma once
#include <vector>
#include <iostream>

template <typename T>
void ShowElements(std::vector<T>const& FirstVector);

template <typename T>
void UniteVectors(std::vector<T>& UnitedVectors, std::vector<T>const& FirstVector,
                  std::vector<T>const& SecondVector);

