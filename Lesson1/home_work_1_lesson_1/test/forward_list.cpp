#include <gtest/gtest.h>
#include <functions.h>
#include <forward_list>

class reverse : public ::testing::TestWithParam<std::tuple<std::forward_list<int>, std::forward_list<int>>>
{
};

TEST_P(reverse,)
{
    std::forward_list<int> list = std::get<0> (GetParam());
    functions::reverse(list);
    std::forward_list<int> expected = std::get<1> (GetParam());
    EXPECT_EQ(list, expected);
}

INSTANTIATE_TEST_CASE_P(,reverse,::testing::Values
                        (
                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 },
                                             std::forward_list<int> { 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 1 , 1 , 1 , 9 },
                                             std::forward_list<int> { 9 , 1 , 1 , 1 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 }),

                            std::make_tuple (std::forward_list<int> { 1 , 2 , 3 , 4 },
                                             std::forward_list<int> { 4 , 3 , 2 , 1 })),

                        );

