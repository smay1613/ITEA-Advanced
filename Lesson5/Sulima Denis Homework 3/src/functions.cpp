#include "functions.h"
#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>

std::vector<std::string> getUniqueWords (const std::string& text){
    std::set<std::string>textCheck;
    std::vector<std::string>result;
    std::string tmp;
    for(const auto &value: text){
        if(value != ' ')
            tmp.push_back(tolower(value));
        else{
            textCheck.insert(tmp);
            tmp.clear();
        }
    }
    if(!tmp.empty()){
        textCheck.insert(tmp);
    }
    for(const auto &value: textCheck){
        result.push_back(value);
    }
    return result;
}

std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text){
    std::map<std::string, size_t>result;
    std::vector<std::pair<std::string, size_t>> resultReturn;
    std::string tmp;
    for(const auto &value: text){
        if(value != ' ')
            tmp.push_back(tolower(value));
        else{
            if(result.empty()){
                result.emplace(tmp, 1);
                tmp.clear();
            }
            else{
                if(result.find(tmp) != result.end()){
                    auto it = result.find(tmp);
                    it->second ++;
                    tmp.clear();
                }
                else {
                    result.emplace(tmp, 1);
                    tmp.clear();
                }
            }
        }
    }
    if(!tmp.empty()){
        if(result.find(tmp)!= result.end()) {
            auto it = result.find(tmp);
            it->second ++;
        }
        else {
            result.emplace(tmp, 1);
            tmp.clear();
        }
    }
    for(const auto &value: result){
        resultReturn.push_back(value);
    }
    return resultReturn;
}
