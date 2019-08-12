#pragma once
#include <vector>
#include <string>

std::vector<std::string> getUniqueWords(const std::string& text);
std::vector<std::pair<std::string, size_t>> wordCounter(const std::string& text);
void print(const std::vector<std::string> &container);
void print(const std::vector<std::pair<std::string, size_t>> &container);
