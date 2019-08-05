#include <gtest/gtest.h>
#include <functions.h>

class concat : public ::testing::TestWithParam<std::tuple<const std::vector<int>, const std::vector<int>, const std::vector<int>>>
{
};

TEST_P(concat,)
{
    std::vector<int> vec_1 = std::get<0> (GetParam());
    std::vector<int> vec_2 = std::get<1> (GetParam());
    std::vector<int> expected = std::get<2> (GetParam());
    std::vector<int> result = functions::concat(vec_1.begin(), vec_1.end(), vec_2.begin(), vec_2.end());
    EXPECT_EQ(result, expected);
};

INSTANTIATE_TEST_CASE_P(,concat,::testing::Values
                        (
                            std::make_tuple(std::vector<int> { 1 , 2 , 3 , 4 , 5 },
                                            std::vector<int> { 6 , 7 , 8  , 9 , 10 },
                                            std::vector<int> { 1 , 2 ,  3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 }),

                            std::make_tuple(std::vector<int> { 1 , 2 , 3 },
                                            std::vector<int> { 4 , 5 , 6 },
                                            std::vector<int> { 1 , 2 ,  3 , 4 , 5 , 6 }),

                            std::make_tuple(std::vector<int> { 4 , 5 , 6 },
                                            std::vector<int> { 7 , 8 },
                                            std::vector<int> { 4 , 5 , 6 , 7 , 8 }),

                            std::make_tuple(std::vector<int> { 1, 2 , 7 , 8 , 9 , 10 },
                                            std::vector<int> {},
                                            std::vector<int> {1 , 2 , 7 , 8 , 9 , 10 }),

                            std::make_tuple(std::vector<int> {},
                                            std::vector<int> {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10},
                                            std::vector<int> {1 , 2 ,  3 , 4 , 5 , 6 , 7 , 8 , 9 , 10})
                            )
                        );
