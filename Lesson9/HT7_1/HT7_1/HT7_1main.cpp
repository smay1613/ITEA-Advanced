#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <chrono>

#include "HT7_1head.hpp"

template <typename T>
void OutTextFile(T& OutTextUnorderedMultimap){
    std::ifstream fileIn;
    fileIn.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
        fileIn.open("text.txt");
        std::string streamStr;
        size_t count = 0;
        while(!fileIn.eof()){
            streamStr = "";
            fileIn >> streamStr;
            OutTextUnorderedMultimap.insert(std::make_pair(streamStr, count));
        };
        std::string Rewritable;
        for(auto element : OutTextUnorderedMultimap){
            if (element.first == Rewritable){
                continue;
            }
            Rewritable = element.first;
            std::cout << element.first << " - " << OutTextUnorderedMultimap.count(element.first) << std::endl;
        }
        fileIn.close();
    }
    catch(const std::ifstream::failure & ex)
    {
        std::cout << ex.what() << std::endl;
        std::cout << ex.code() << std::endl;
        std::cout << "File isn't opened!" << std::endl;
    }

}


int main(){

    std::unordered_multimap <std::string, size_t> OutTextUnorderedMultimap;
    std::multimap <std::string, size_t> OutTextMultimap;

    auto MultimapStartTime = std::chrono::high_resolution_clock::now();
    std::cout << "Elements by unorderedmultimap:" << std::endl;
    OutTextFile(OutTextUnorderedMultimap);
    std::cout << "==========================================" << std::endl;
    auto MultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  MultimapTimeResult = MultimapEndTime - MultimapStartTime;
    std::cout << "Time of runing function \"OutTextFile\" with UNORDEREDMULTIMAP: " << MultimapTimeResult.count() << "s" << std::endl;
    std::cout << "==========================================" << std::endl;

    auto UnorderedMultimapStartTime = std::chrono::high_resolution_clock::now();
    std::cout << "Elements by unordered multimap:" << std::endl;
    OutTextFile(OutTextMultimap);
    std::cout << "==========================================" << std::endl;
    auto UnorderedMultimapEndTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  UnorderedMultimapTimeResult = UnorderedMultimapEndTime - UnorderedMultimapStartTime;
    std::cout << "Time of runing function \"OutTextFile\" with MULTIMAP: " << UnorderedMultimapTimeResult.count() << "s" << std::endl;
    std::cout << "==========================================" << std::endl;

    if(MultimapTimeResult.count() > UnorderedMultimapTimeResult.count())
        std::cout << "MULTIMAP is faster." << std::endl;
    else if(MultimapTimeResult.count() < UnorderedMultimapTimeResult.count())
        std::cout << "UNORDEREDMULTIMAP is faster." << std::endl;
    else
        std::cout << "MULTIMAP and UNORDEREDMULTIMAP are equal." << std::endl;

    return 0;
}
