#pragma once
#include "gtest/gtest.h"

class isExpressionValidTrue : public ::testing::TestWithParam<std::string>
{
};
class isExpressionValidFalse : public ::testing::TestWithParam<std::string>
{
};
