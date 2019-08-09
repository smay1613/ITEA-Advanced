#include "brackets_test.h"
#include "brackets.h"



TEST_P(AllBracketsClosed, DifferentIncome) {
  std::string inputString = std::get<0>(GetParam());
  bool expectedResult = std::get<1>(GetParam());
  EXPECT_EQ(areAllBracketsClosed(inputString), expectedResult);
}

INSTANTIATE_TEST_CASE_P(AllClosed,
                        AllBracketsClosed,
                        ::testing::Values (std::make_tuple("()", true),
                                           std::make_tuple("())(", false),
                                           std::make_tuple("(){}[]", true),
                                           std::make_tuple("({[)}]", true),
                                           std::make_tuple("{{((()))}[]]", false)
                                           ));
