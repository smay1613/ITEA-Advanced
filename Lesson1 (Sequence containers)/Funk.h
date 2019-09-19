#ifndef FUNK_H
#define FUNK_H
#include <iostream>
#include <vector>
#include <forward_list>

std::vector<int> combineVectors(std::vector<int>::const_iterator begin1, std::vector<int>::const_iterator end1,
                            std::vector<int>::const_iterator begin2,
                            std::vector<int>::const_iterator end2);

size_t magicNumber(const size_t digit, const size_t num);
void reverse(std::forward_list<int>& listToReverse);
#endif // FUNK_H
