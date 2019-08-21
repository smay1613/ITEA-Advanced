//after structurized project close VSCode, OpenAgain,  Shift+Ctrl+P command pallete
//it will ask use cmake build - Yes, tab to OUTPUT, select ExampleTests.cpp and press molotok build -> will begin cmake build process
// https://www.youtube.com/watch?v=Lp1ifh9TuFI&list=PLzjmU_6e7Lj2DtwOh_pcwr9sNAPjPtLnX&index=652&t=0s

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../thirdHomeAdvanced.hpp"

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

TEST(ExampleTests, getUniqueWords){ 
    

	char filename[] = "test.txt"; 
    std::ofstream fs(filename, std::ios::trunc); 
    fs << "geeks for geeks quiz code geeks practice for qa"; 
    fs.close(); 
  
	std::vector<std::string> testStringWithResult;
    testStringWithResult = getUniqueWords(filename);
	//std::cout << testStringWithResult << std::endl;
    //EXPECT_THAT(resultVector, ::testing::UnorderedElementsAreArray(testVector)); 
    //ASSERT_THAT(resultVector, ::testing::ElementsAre(5, 6, 7, 8, 9, 12, 13, 14, 15, 16));
}

TEST(ExampleTests, wordCounter){ 
    

	typedef std::multiset<std::string> mySet;
    typedef std::multiset<std::string>::iterator mySetItr;

    mySet mWords;

    mWords.insert("Apple");
    mWords.insert("Apple");
    mWords.insert("Bubble");
	mWords.insert("Orange");
	mWords.insert("Orange");

    mySetItr it = std::begin(mWords), itend = std::end(mWords);
    std::for_each<mySetItr&>(it, itend, [&mWords, &it] (const std::string& word)
    {
        auto p = mWords.equal_range(word);
        int count = static_cast<int>(std::distance(p.first, p.second));
        std::cout << word << " " << count << std::endl;
        std::advance(it, count - 1);
    });

    //EXPECT_THAT(resultVector, ::testing::UnorderedElementsAreArray(testVector)); 
    //ASSERT_THAT(resultVector, ::testing::ElementsAre(5, 6, 7, 8, 9, 12, 13, 14, 15, 16));
}


//---------------------- end usual two tests -----------------
