#include "main.cpp"
#include <gtest/gtest.h>

template <class T>
std::vector<T> concat(const std::vector<T> &data_vector_1, const std::vector<T> &data_vector_2);

namespace {
class TestConcat : public ::testing::Test{

};
TEST_F(TestConcat, Concat_Vector){
    std::vector<int> some_data_1 = {1,2,3,4,5};
    std::vector<int> some_data_2 = {6,7,8,9,10};
    std::vector<int> result = concat(some_data_1,some_data_2);
    EXPECT_EQ("1,2", result);
}
}


