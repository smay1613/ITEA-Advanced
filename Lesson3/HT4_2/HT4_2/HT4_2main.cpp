#include <iostream>
#include <sstream>
#include <string>
#include <set>

#include "HT4_2head.hpp"

void CountsOffSameWords(std::string& EnterText, std::multiset<std::string>& OutText){
    std::stringstream str;
    str << EnterText;
    std::string streamStr;
    while (str >> streamStr){
        OutText.insert(streamStr);
    }
    std::string Rewritable;
    for(auto element : OutText){
        if (element == Rewritable){
            continue;
        }
        Rewritable = element;
        std::cout << element << "\t:\t" << OutText.count(element) << std::endl;
    }
}


int main(){

    std::string EnterText {"hello world, hello cpp ! hello hello hello apple an orange an laptop"};
    std::multiset<std::string> OutText;
    CountsOffSameWords(EnterText, OutText);

}
