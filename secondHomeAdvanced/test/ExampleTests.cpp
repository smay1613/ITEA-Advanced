//after structurized project close VSCode, OpenAgain,  Shift+Ctrl+P command pallete
//it will ask use cmake build - Yes, tab to OUTPUT, select ExampleTests.cpp and press molotok build -> will begin cmake build process
// https://www.youtube.com/watch?v=Lp1ifh9TuFI&list=PLzjmU_6e7Lj2DtwOh_pcwr9sNAPjPtLnX&index=652&t=0s

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../secondHomeAdvanced.hpp"

//using ::testing::Test; 
//------------------ usual two tests -----------------------
// !!!! to run rest -> shift+ctrl+P -> Cmake Run tests
/*

   
TEST(ExampleTests, DemonstrateGTestMacros){
    
    //EXPECT_TRUE(false);

    //ASSERT_TRUE(true); //ASSERT is more strict version of EXPECT (bolee zhostakaya esli test ASSERT ne proshli dalshe ne idem) 
                        // posle ASSERT_TRUE - EXPECT_TRUE uzhe vipolnyatsa ne budet, srazu break i logtest v terminal
    //EXPECT_TRUE(false);
    EXPECT_EQ(true, true);  // compare two condition, here true is equal to true :)
    
    const bool result = f();
    EXPECT_EQ(true, result) << "Side Effect " << sideEffect << std::endl;

    for (int i = 0; i < 16; ++i)
     EXPECT_EQ(true, result) << "i = " << i << std::endl;
    */



// regex has search, match and verifying methods for strings
TEST(ExampleTests, isExpressionValid){ 
   
   std::string expressionInString = {"()()))"};
   std::string & linkToStr = expressionInString;
   bool expresionIsValid;

   expresionIsValid = isExpressionValid(linkToStr);

   EXPECT_EQ(false, expresionIsValid)  << std::endl;

   expressionInString = {"{}{}{}"};
   expresionIsValid = isExpressionValid(linkToStr);

   EXPECT_EQ(true, expresionIsValid)  << std::endl;

}

TEST(ExampleTests, linkLevelNodes){ 
   
    Node* binaryTree = nullptr;
    
    binaryTree = new Node(15);
    binaryTree->left = new Node(10);
    binaryTree->right = new Node(20);
    binaryTree->left->left = new Node(8);
    binaryTree->left->right = new Node(12);
    binaryTree->right->left = new Node(16);
    binaryTree->right->right = new Node(25);

    linkLevelNodes(binaryTree);

    //EXPECT_EQ(false, expresionIsValid)  << std::endl;
    //ASSERT_THAT(*binaryTree, ::testing::ElementsAre("15", "20", "10", "25", "16", "12", "8"));

}

//---------------------- end usual two tests -----------------
