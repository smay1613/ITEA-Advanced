#include "gtest/gtest.h"
#include <stack>
//#include "library.h"

struct bracket
{
    bracket(size_t _type) : type(_type)
    {}
    size_t type;
    size_t number = 1;
};


bool is_expression_valid(const std::string &str)
{
    std::stack<bracket> data_stack;
    if (str.empty())
    {
        return true;
    }
    else
    {
        for (const char& c : str)
        {
            switch (c)
            {
                case '(':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{0});
                    }
                break;
                case ')':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 0)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{0});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '[':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{1});
                    }
                break;
                case ']':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 1)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{1});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
                case '{':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number++;
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        data_stack.emplace(bracket{2});
                    }
                break;
                case '}':
                    if (!data_stack.empty())
                    {
                        if (data_stack.top().type == 2)
                        {
                            data_stack.top().number--;
                            if (data_stack.top().number == 0)
                            {
                                data_stack.pop();
                            }
                        }
                        else
                        {
                            data_stack.emplace(bracket{2});
                        }
                    }
                    else
                    {
                        return false;
                    }
                break;
            }
        }

        if (!data_stack.empty())
        {
            return false;
        }

        else
        {
            return true;
        }
    }
}



class is_expression_valid_test : public ::testing::Test
{
public:
    std::string is_expression_valid_str_1 = "[]";
    bool is_expression_valid_result_1 = true;

    std::string is_expression_valid_str_2 = "[)";
    bool is_expression_valid_result_2 = false;

    std::string is_expression_valid_str_3 = "sefmweokfmowefowfm";
    bool is_expression_valid_result_3 = true;

    std::string is_expression_valid_str_4 = "()[]{}({[]})";
    bool is_expression_valid_result_4 = true;

    std::string is_expression_valid_str_5 = "";
    bool is_expression_valid_result_5 = true;
};



TEST_F(is_expression_valid_test, 1)
{
    bool result = is_expression_valid(is_expression_valid_str_1);
    EXPECT_EQ(result, is_expression_valid_result_1);
}

TEST_F(is_expression_valid_test, 2)
{
    bool result = is_expression_valid(is_expression_valid_str_2);
    EXPECT_FALSE(result != is_expression_valid_result_2);
}

TEST_F(is_expression_valid_test, 3)
{
    bool result = is_expression_valid(is_expression_valid_str_3);
    EXPECT_EQ(result, is_expression_valid_result_3);
}

TEST_F(is_expression_valid_test, 4)
{
    bool result = is_expression_valid(is_expression_valid_str_4);
    EXPECT_EQ(result, is_expression_valid_result_4);
}

TEST_F(is_expression_valid_test, 5)
{
    bool result = is_expression_valid(is_expression_valid_str_5);
    EXPECT_EQ(result, is_expression_valid_result_5);
}

