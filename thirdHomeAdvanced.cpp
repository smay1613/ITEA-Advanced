
#include "thirdHomeAdvanced.hpp"


std::vector<std::string> getUniqueWords(char filename[])   //(const std::string& text);
{ 
    // Open a file stream 
    std::fstream fs(filename); 
  
    // Create a map to store count of all words 
    std::map<std::string, int> mp; 
  
    // Keep reading words while there are words to read 
    std::string word; 
    while (fs >> word) 
    { 
        // If this is first occurrence of word 
        if (!mp.count(word)) 
            mp.insert(make_pair(word, 1)); 
        else
            mp[word]++; 
    } 
  
    fs.close(); 
  
    // Traverse map and print all words whose count 
    //is 1 
    for (std::map<std::string, int> :: iterator p = mp.begin(); 
         p != mp.end(); p++) 
    { 
        if (p->second == 1) 
            std::cout << p->first << std::endl; 
    } 
} 

/*	
1. std::vector<std::string> getUniqueWords (const std::string& text);
Немного поучитесь перекидывать с одного контейнера данные в другой:
2. std::vector<std::pair<std::string>,
                       size_t> wordCounter (const std::string& text);


//checks that vector v is {5, 10, 15}
ASSERT_THAT(v, ElementsAre(5, 10, 15));

//checks that map m only have elements 1 => 10, 2 => 20
ASSERT_THAT(m, ElementsAre(Pair(1, 10), Pair(2, 20)));

//checks that in vector v all the elements are greater than 10 and less than 20
ASSERT_THAT(v, Each(AllOf(Gt(10), Lt(20))));

//checks that vector v consist of 
//   5, number greater than 10, anything.
ASSERT_THAT(v, ElementsAre(5, Gt(10), _));
*/



