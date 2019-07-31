#include "TestMetadataUtils.h"
#include "Utils.h"


INSTANTIATE_TEST_CASE_P(Values,
                        combineVectors,
                        ::testing::Values(std::make_pair(std::vector<int>{1,2,3},        std::vector<int>{4,5,6}),
                                          std::make_pair(std::vector<int>{1,2,3,4,5,6},  std::vector<int>{}),
                                          std::make_pair(std::vector<int>{},             std::vector<int>{1,2,3,4,5,6}),
                                          std::make_pair(std::vector<int>{1},            std::vector<int>{2,3,4,5,6}),
                                          std::make_pair(std::vector<int>{1,2,3,4,5},    std::vector<int>{6})
                                          ));

TEST_P(combineVectors, combineVectors)
{
std::vector<int> firstVec = std::get<0>(GetParam());
std::vector<int> secondVec = std::get<1>(GetParam());
const std::vector<int> result {avprocessing::utilities::combineVectors(firstVec.begin(), firstVec.end(),
                                                                       secondVec.begin(), secondVec.end())};
EXPECT_EQ(result, (std::vector<int>{1, 2, 3, 4, 5, 6}));
}

const size_t checkResultMagicNumber[]{19316911, 1010101010, 525156535, 24, 0, 3719, 7493321171983, 0, 1};
size_t numbersMagicNumberTest {0};

INSTANTIATE_TEST_CASE_P(Values,
                        MagicNumber,
                        ::testing::Values(std::make_pair(size_t {19}, size_t{4}),
                                          std::make_pair(size_t {10}, size_t{5}),
                                          std::make_pair(size_t {5},  size_t{5}),
                                          std::make_pair(size_t {2},  size_t{2}),
                                          std::make_pair(size_t {0},  size_t{0}),
                                          std::make_pair(size_t {37}, size_t{2}),
                                          std::make_pair(size_t {7},  size_t{7}),
                                          std::make_pair(size_t {10}, size_t{0}),
                                          std::make_pair(size_t {1},  size_t{1})
                                          ));

TEST_P(MagicNumber, MagicNumber)
{
    const size_t number = std::get<0>(GetParam());
    const size_t degree = std::get<1>(GetParam());
    const size_t result {avprocessing::utilities::magicNumber(number, degree)};
    EXPECT_EQ(result, (checkResultMagicNumber[numbersMagicNumberTest]));
    numbersMagicNumberTest++;
}


std::vector<std::forward_list<int>>checkResultForwardListReverce{{5, 4, 3, 2, 1},
                                                                 {100, 200, 300, 400, 500},
                                                                 {},
                                                                 {1},
                                                                 {50, 50}
                                                                };
size_t numbersForwardListTest {0};

INSTANTIATE_TEST_CASE_P(ReverseForList,
                        ReverceForwardList,
                        ::testing::Values(std::forward_list<int>{1, 2, 3, 4, 5},
                                          std::forward_list<int>{500, 400, 300, 200, 100},
                                          std::forward_list<int>{},
                                          std::forward_list<int>{1},
                                          std::forward_list<int>{50,50}
                                          ));

TEST_P(ReverceForwardList, IsReversing)
{
    std::forward_list<int>forwardListToReverse{GetParam()};
    avprocessing::utilities::reverse(forwardListToReverse);
    EXPECT_EQ(forwardListToReverse, checkResultForwardListReverce[numbersForwardListTest]);
    numbersForwardListTest++;

}







