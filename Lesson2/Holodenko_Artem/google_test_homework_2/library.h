#pragma once

#include <iostream>
#include <stack>

struct bracket
{
    bracket(size_t _type) : type(_type)
    {}
    size_t type;
    size_t number = 1;
};

bool is_expression_valid(const std::string &str);
