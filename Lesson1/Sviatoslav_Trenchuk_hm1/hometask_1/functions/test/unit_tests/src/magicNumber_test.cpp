#include "magicNumber_test.h"
#include "magicNumber.h"

TEST_P(MagicNumberTest, TrueCalculationResultTests) {
  const size_t number = std::get<0>(GetParam());
  const size_t degree = std::get<1>(GetParam());
  const size_t expectReluslt = std::get<2>(GetParam());
  size_t result = magicNumber(number, degree);

  EXPECT_EQ(result, expectReluslt);
}


INSTANTIATE_TEST_CASE_P(DifferentValuesTest,
                        MagicNumberTest,
                        ::testing::Values(
                                            std::make_tuple(19, 4, 19316911),
                                            std::make_tuple(10, 5, 1010101010),
                                            std::make_tuple(1, 5, 1111111111),
                                            std::make_tuple(1, 0, 0),
                                            std::make_tuple(322, 2, 3214)));



