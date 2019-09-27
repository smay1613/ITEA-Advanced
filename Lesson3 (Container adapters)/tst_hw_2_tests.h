#ifndef TST_HW_2_TESTS_H
#define TST_HW_2_TESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

TEST(Hw_2_Tests, Hw_2_Tests)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

#endif // TST_HW_2_TESTS_H
