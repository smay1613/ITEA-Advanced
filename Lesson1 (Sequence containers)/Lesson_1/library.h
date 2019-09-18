#pragma once

#include <forward_list>
#include <vector>
#include <list>
#include <iterator>

std::vector<int> combineVectors(const std::vector<int>::iterator& begin1, const std::vector<int>::iterator& end1, const std::vector<int>::iterator& begin2, const std::vector<int>::iterator& end2);

size_t magicNumber(const size_t number, const size_t degree);

void reverse(std::forward_list<int>& listToReverse);
