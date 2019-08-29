#include <vector>
#include "gmock/gmock.h"

template <typename T>
void UniteVectors(std::vector<T>& UnitedVectors, std::vector<T>const& FirstVector,
                  std::vector<T>const& SecondVector){
    UnitedVectors.resize(FirstVector.size() + SecondVector.size());
    for (auto i = 0; i < FirstVector.size(); ++i){
        UnitedVectors[i] = FirstVector[i];
    }
    for (auto i = FirstVector.size(); i < UnitedVectors.size(); ++i){
        UnitedVectors[i] = SecondVector[i - FirstVector.size()];
    }
}

TEST(UniteVectorsTest, Test1){
    std::vector<float>UnitedVectors;
    std::vector<float>FirstVector{1.43, 2.12, 3.81};
    std::vector<float>SecondVector{4.65, 5.0};
    UniteVectors(UnitedVectors, FirstVector, SecondVector);


    EXPECT_THAT(UnitedVectors, ::testing::ElementsAre(1.43, 2.12, 3.81, 4.65, 5));
}

TEST(UniteVectorsTest, Test2){
    std::vector<int>UnitedVectors;
    std::vector<int>FirstVector{99, 6, 105};
    std::vector<int>SecondVector{54, 19, 77, 45, 90};
    UniteVectors(UnitedVectors, FirstVector, SecondVector);


    EXPECT_THAT(UnitedVectors, ::testing::ElementsAre(99, 6, 105, 54, 19, 77, 45, 90));
}

TEST(UniteVectorsTest, Test3){
    std::vector<int>UnitedVectors;
    std::vector<int>FirstVector{};
    std::vector<int>SecondVector{1, 2, 3};
    UniteVectors(UnitedVectors, FirstVector, SecondVector);


    EXPECT_THAT(UnitedVectors, ::testing::ElementsAre(1, 2, 3));
}

TEST(UniteVectorsTest, Test4){
    std::vector<size_t>UnitedVectors;
    std::vector<size_t>FirstVector{};
    std::vector<size_t>SecondVector{};
    UniteVectors(UnitedVectors, FirstVector, SecondVector);


    EXPECT_THAT(UnitedVectors, ::testing::ElementsAre());
}

TEST(UniteVectorsTest, Test5){
    std::vector<int>UnitedVectors;
    std::vector<int>FirstVector{5, 4, 7};
    std::vector<int>SecondVector{};
    UniteVectors(UnitedVectors, FirstVector, SecondVector);


    EXPECT_THAT(UnitedVectors, ::testing::ElementsAre(5, 4, 7));
}



int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

