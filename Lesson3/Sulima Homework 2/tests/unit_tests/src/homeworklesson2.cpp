#include "homeworklesson2.h"
#include "functions.h"

INSTANTIATE_TEST_CASE_P(TrueBrackets,
                        isExpressionValidTrue,
                        ::testing::Values("()()([][]{})", "[][]", "{}{}{()()(){}[()()]}()()", "{}()[]", ""
                                          ));

TEST_P(isExpressionValidTrue, IsTrue)
{

    bool result = isExpressionValid(GetParam());
    EXPECT_EQ(result, true);
}


INSTANTIATE_TEST_CASE_P(FalseBrackets,
                        isExpressionValidFalse,
                        ::testing::Values("{}{}{}{", "()(()([][]{})" , ")(}{[]", "][", "{}}{"
                                          ));

TEST_P(isExpressionValidFalse, IsFalse)
{

    bool result = isExpressionValid(GetParam());
    EXPECT_EQ(result, false);
}






