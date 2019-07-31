#pragma once
#include "gtest/gtest.h"
#include <forward_list>

class ReverceForwardList : public ::testing::TestWithParam<std::forward_list<int>>
{
};
class combineVectors : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>
{
};
class MagicNumber : public ::testing::TestWithParam<std::pair<int , int>>
{
};

