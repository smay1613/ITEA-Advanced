#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

#include "HT6_2head.hpp"

template <typename T>
void AddElements(T& MyUnorderedMultimap){
    MyUnorderedMultimap.insert(std::make_pair(1, "Human1"));
    MyUnorderedMultimap.insert(std::make_pair(2, "Human2"));
    MyUnorderedMultimap.insert(std::make_pair(3, "Human3"));
    MyUnorderedMultimap.insert(std::make_pair(4, "Human4"));
    MyUnorderedMultimap.insert(std::make_pair(5, "Human5"));
    MyUnorderedMultimap.insert(std::make_pair(6, "Human6"));
    MyUnorderedMultimap.insert(std::make_pair(7, "Human7"));
    MyUnorderedMultimap.insert(std::make_pair(8, "Human8"));
    MyUnorderedMultimap.insert(std::make_pair(9, "Human9"));
    MyUnorderedMultimap.insert(std::make_pair(10, "Human10"));

    // for (auto element : MyUnorderedMultimap){
    //     std::cout << element.first << " - " << element.second << std::endl;
    // }
}

template <typename T>
void SeachElements(T const& MyUnorderedMultimap){
    size_t id;
    for(auto element : MyUnorderedMultimap){
        id++;
        MyUnorderedMultimap.find(id);
    }
}

template <typename T>
void RemoveElements(T& MyUnorderedMultimap){
     size_t id;
    for(auto element : MyUnorderedMultimap){
        id++;
        MyUnorderedMultimap.erase(id);
    }
}




int main(){
    std::multimap <int, std::string> MyMultimap;
    std::unordered_multimap <int, std::string> MyUnorderedMultimap;

    /* BLOCK OF COMPARATING FOR ADDING ELEMENTS*/

    auto AddMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Added elements in multimap:" << std::endl;
    AddElements(MyMultimap);
    std::cout << "===============================================================" << std::endl;
    auto AddMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  AddMultimapTimeResult = AddMultimapEndTime - AddMultimapStartTime;
    std::cout << "Time of runing function \"AddElements\" with MULTIMAP: " << AddMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    auto AddUnorderedMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Added elements in unordered multimap:" << std::endl;
    AddElements(MyUnorderedMultimap);
    std::cout << "===============================================================" << std::endl;
    auto AddUnorderedMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  AddUnorderedMultimapTimeResult = AddUnorderedMultimapEndTime - AddUnorderedMultimapStartTime;
    std::cout << "Time of runing function \"AddElements\" with UNORDEREDMULTIMAP: " << AddUnorderedMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    if(AddMultimapTimeResult.count() < AddUnorderedMultimapTimeResult.count()){
        std::cout << "Adding in MULTIMAP is faster." << std::endl;
    }
    if(AddMultimapTimeResult.count() > AddUnorderedMultimapTimeResult.count()){
        std::cout << "Adding in UNORDEREDMULTIMAP is faster." << std::endl;
    }
    if(AddMultimapTimeResult.count() == AddUnorderedMultimapTimeResult.count()){
        std::cout << "MULTIMAP and UNORDEREDMULTIMAP are equal." << std::endl;
    }
    std::cout << "===============================================================" << std::endl;
    std::cout << "###############################################################" << std::endl;


    /* BLOCK OF COMPARATING FOR SEACH ELEMENTS*/

    auto SeachMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Seach elements in multimap:" << std::endl;
    SeachElements(MyMultimap);
    std::cout << "===============================================================" << std::endl;
    auto SeachMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  SeachMultimapTimeResult = SeachMultimapEndTime - SeachMultimapStartTime;
    std::cout << "Time of runing function \"SeachElements\" with MULTIMAP: " << SeachMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    auto SeachUnorderedMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Seach elements in unordered multimap:" << std::endl;
    SeachElements(MyUnorderedMultimap);
    std::cout << "===============================================================" << std::endl;
    auto SeachUnorderedMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  SeachUnorderedMultimapTimeResult = SeachUnorderedMultimapEndTime - SeachUnorderedMultimapStartTime;
    std::cout << "Time of runing function \"SeachElements\" with UNORDEREDMULTIMAP: " << SeachUnorderedMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    if(SeachMultimapTimeResult.count() < SeachUnorderedMultimapTimeResult.count()){
        std::cout << "Seach in MULTIMAP is faster." << std::endl;
    }
    if(SeachMultimapTimeResult.count() > SeachUnorderedMultimapTimeResult.count()){
        std::cout << "Seach in UNORDEREDMULTIMAP is faster." << std::endl;
    }
    if(SeachMultimapTimeResult.count() == SeachUnorderedMultimapTimeResult.count()){
        std::cout << "MULTIMAP and UNORDEREDMULTIMAP are equal." << std::endl;
    }
    std::cout << "===============================================================" << std::endl;
    std::cout << "###############################################################" << std::endl;


    /* BLOCK OF COMPARATING FOR REMOVING ELEMENTS*/

    auto RemoveMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Removed elements in multimap:" << std::endl;
    RemoveElements(MyMultimap);
    std::cout << "===============================================================" << std::endl;
    auto RemoveMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  RemoveMultimapTimeResult = RemoveMultimapEndTime - RemoveMultimapStartTime;
    std::cout << "Time of runing function \"RemoveElements\" with MULTIMAP: " << SeachMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    auto RemoveUnorderedMultimapStartTime = std::chrono::high_resolution_clock::now();
    // std::cout << "Removed elements in unordered multimap:" << std::endl;
    RemoveElements(MyUnorderedMultimap);
    std::cout << "===============================================================" << std::endl;
    auto RemoveUnorderedMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  RemoveUnorderedMultimapTimeResult = RemoveUnorderedMultimapEndTime - RemoveUnorderedMultimapStartTime;
    std::cout << "Time of runing function \"RemoveElements\" with UNORDEREDMULTIMAP: " << RemoveUnorderedMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "===============================================================" << std::endl;

    if(RemoveMultimapTimeResult.count() < RemoveUnorderedMultimapTimeResult.count()){
        std::cout << "Remove in MULTIMAP is faster." << std::endl;
    }
    if(RemoveMultimapTimeResult.count() > RemoveUnorderedMultimapTimeResult.count()){
        std::cout << "Remove in UNORDEREDMULTIMAP is faster." << std::endl;
    }
    if(RemoveMultimapTimeResult.count() == RemoveUnorderedMultimapTimeResult.count()){
        std::cout << "MULTIMAP and UNORDEREDMULTIMAP are equal." << std::endl;
    }
    std::cout << "===============================================================" << std::endl;



    return 0;
}
