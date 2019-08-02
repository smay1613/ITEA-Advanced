#pragma once
#include "gtest/gtest.h"
#include <tuple>

class MagicNumberTest : public ::testing::TestWithParam<std::tuple<size_t,
                                                                   size_t,
                                                                   size_t>>
{

};




