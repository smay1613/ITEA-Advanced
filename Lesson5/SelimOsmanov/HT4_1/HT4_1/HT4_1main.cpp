#include <iostream>
#include <sstream>
#include <string>
#include <set>

#include "HT4_1head.hpp"

void OutTextNotSameWords(std::string& EnterText, std::set<std::string>& OutText){
    std::stringstream str;
    str << EnterText;
    std::string streamStr;
    while (str >> streamStr){
        OutText.insert(streamStr);
    }
}


int main(){


    std::string EnterText {"hello world, hello cpp !"};
    std::set<std::string> OutText;

    OutTextNotSameWords(EnterText, OutText);

    for (auto element : OutText){
        std::cout << element << std::endl;
    }

    return 0;
}
