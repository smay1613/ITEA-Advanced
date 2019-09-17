#include <list>
#include <cmath>
#include "gmock/gmock.h"

template <typename T>
void TakeNumbers(T Exponent, T Basis, std::list<T>& OutList){
    for (auto i = 1; i <= Exponent; ++i){
        T var = pow (Basis, i);
        T firstNumber = var;
        while(firstNumber >= 10){
            firstNumber /= 10;
        };
        T lastNumber = var%10;
        OutList.push_back(firstNumber);
        OutList.push_back(lastNumber);
    }
}

TEST(TakeNumbers, Test1){
    size_t Exponent = 1;
    size_t Bazis =1;
    std::list<size_t>OutList;
    TakeNumbers(Exponent, Bazis, OutList);


    EXPECT_THAT(OutList, ::testing::ElementsAre(1, 1));
}

TEST(TakeNumbers, Test2){
    size_t Exponent = 2;
    size_t Bazis =1;
    std::list<size_t>OutList;
    TakeNumbers(Exponent, Bazis, OutList);


    EXPECT_THAT(OutList, ::testing::ElementsAre(1, 1, 1, 1));
}

TEST(TakeNumbers, Test3){
    size_t Exponent = 0;
    size_t Bazis =1;
    std::list<size_t>OutList;
    TakeNumbers(Exponent, Bazis, OutList);


    EXPECT_THAT(OutList, ::testing::ElementsAre());
}

TEST(TakeNumbers, Test4){
    size_t Exponent = 1;
    size_t Bazis =0;
    std::list<size_t>OutList;
    TakeNumbers(Exponent, Bazis, OutList);


    EXPECT_THAT(OutList, ::testing::ElementsAre(0, 0));
}

TEST(TakeNumbers, Test5){
    size_t Exponent = 0;
    size_t Bazis =0;
    std::list<size_t>OutList;
    TakeNumbers(Exponent, Bazis, OutList);


    EXPECT_THAT(OutList, ::testing::ElementsAre());
}




int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
