#include <forward_list>
#include <vector>
#include "gmock/gmock.h"

template <typename T>
void ReverseElements (std::forward_list <T> & MyForwardList) {
    std::forward_list <T> MyForwardList_copy = MyForwardList;
    MyForwardList.clear();
    for (auto element : MyForwardList_copy){
        MyForwardList.push_front(element);
    }
}

TEST(ReverseElements, Test1){
    std::forward_list <int> MyForwardList {1, 2, 3, 4, 5};

    ReverseElements (MyForwardList);


    EXPECT_THAT(MyForwardList, ::testing::ElementsAre(5, 4, 3, 2, 1));
}

TEST(ReverseElements, Test2){
    std::forward_list <char> MyForwardList {'H', 'e', 'l', 'l', 'o'};

    ReverseElements (MyForwardList);


    EXPECT_THAT(MyForwardList, ::testing::ElementsAre('o', 'l', 'l', 'e', 'H'));
}

TEST(ReverseElements, Test3){
    std::forward_list <bool> MyForwardList {true, false};

    ReverseElements (MyForwardList);


    EXPECT_THAT(MyForwardList, ::testing::ElementsAre(false, true));
}

TEST(ReverseElements, Test4){
    std::forward_list <float> MyForwardList {1.1, 2.2, 3.3, 4.4, 5.5};

    ReverseElements (MyForwardList);


    EXPECT_THAT(MyForwardList, ::testing::ElementsAre(5.5, 4.4, 3.3, 2.2, 1.1));
}

TEST(ReverseElements, Test5){
    std::forward_list <size_t> MyForwardList {4, 7, 3, 9, 0};
    ReverseElements (MyForwardList);


    EXPECT_THAT(MyForwardList, ::testing::ElementsAre(0, 9, 3, 7, 4));
}




int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

