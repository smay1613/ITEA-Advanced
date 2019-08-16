#pragma once
#include "gtest/gtest.h"
#include <forward_list>

class getUniqueWordsData : public ::testing::TestWithParam<std::string>
{
public:
    std::vector<std::set<std::string>> correctResult {{{"Container"},{"adapters"},{"are"}, {"a"}, {"special"}, {"type"}, {"of"}, {"class."}},
                                                      {{"AaA"}},
                                                      {{"AAA"}, {"sss"}, {"www"}, {"xxx"}},
                                                      {{""}},
                                                      {{"123,"}, {"321,"}, {"A,"}}
                                                      };
};

class wordCounterData : public ::testing::TestWithParam<std::string>
{
public:
       std::vector<std::vector<std::pair<std::string, size_t>>> correctResult {{{"Container", 2},{"adapters", 1},{"are", 1}, {"a", 1}, {"special", 1}, {"type", 1}, {"of", 1}, {"class.", 1}},
                                                                               {{"AaA", 4}},
                                                                               {{"AAA", 2}, {"sss", 2}, {"www", 1}, {"xxx", 1}},
                                                                               {{}},
                                                                               {{"123,", 1}, {"321,", 1}, {"A,", 2}}};
};

