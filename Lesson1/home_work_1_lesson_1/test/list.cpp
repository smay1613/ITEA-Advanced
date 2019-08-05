#include <gtest/gtest.h>
#include <functions.h>

class magic_number : public ::testing::TestWithParam<std::tuple<size_t, size_t, size_t>>
{
};

TEST_P(magic_number,)
{
    size_t N = std::get<0>(GetParam());
    size_t X = std::get<1>(GetParam());
    size_t expected = std::get<2>(GetParam());
    size_t result = functions::magic_number(N , X);
    EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_CASE_P(,magic_number,::testing::Values
                        (
                            std::make_tuple ( 19 , 4 , 19316911 ),
                            std::make_tuple ( 10 , 5 , 1010101010 ),
                            std::make_tuple ( 4 , 2 , 4416 ),
                            std::make_tuple ( 6 , 3 , 663626 ),
                            std::make_tuple ( 10 , 2 , 1010 ))
                        );


