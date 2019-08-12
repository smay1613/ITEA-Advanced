#include "gtest/gtest.h"

#include "test_program_1.cpp"
#include "test_program_2.cpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
