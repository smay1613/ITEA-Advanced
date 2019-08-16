#include "functions.h"
#include <set>
#include <map>
#include <algorithm>
#include <sstream>


std::vector<std::string> getUniqueWords (const std::string& text){

    std::set<std::string>textCheck;

    std::stringstream textStream;
    std::string tmp;

    textStream << text;
    while(!textStream.eof())
    {
        textStream >> tmp;
        std :: transform( tmp.begin(), tmp.end(), tmp.begin(), ::tolower );
        textCheck.insert(tmp);
    }

    std::vector<std::string>result{textCheck.begin(), textCheck.end()};

    return result;

}


std::vector<std::pair<std::string, size_t>> wordCounter (const std::string& text){

    std::map<std::string, size_t>result;
    std::vector<std::pair<std::string, size_t>> resultReturn{};
    std::string tmp{};
    if(text == tmp){
        result.emplace("",0);
        resultReturn.push_back(*result.begin());
        return resultReturn;
    }
    std::stringstream textStream;
    textStream << text;
    while(!textStream.eof())
    {
        textStream >> tmp;
        std :: transform( tmp.begin(), tmp.end(), tmp.begin(), ::tolower );

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
    for(const auto &value: result){
        resultReturn.push_back(value);
    }
    return resultReturn;
}
