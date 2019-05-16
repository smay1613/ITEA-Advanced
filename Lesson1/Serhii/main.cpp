#include <vector>
#include <iostream>
#include <string> 
#include <cmath>
#include <forward_list>

void print(const std::vector<int>& value) {
    for (const int& val : value) {
        std::cout << val << std::endl;
    }
}

void print(const std::forward_list<int>& value) {
    for (const int& val : value) {
        std::cout << val << std::endl;
    }
}

std::vector<int> concatination(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> value(v1);
    if (v2.empty()) {
        return value;
    }
    value.insert(value.end(), v2.begin(), v2.end());
    return value;
}


std::string functionNX(const int & N, const int & X) {
    std::string value = "";
    for (int i = 1; i <= X; i++) {
        std::string data = std::to_string((int)pow(N, i));
        if (data.size() < 2) {
            continue;
        }
        value.push_back(data[0]);
        value.push_back(data[data.size() - 1]);
    }
    return value;
}

std::forward_list<int> reverse(const std::forward_list<int> & list) {
    std::forward_list<int> value;
    for (const int& val : list) {
         value.push_front(val);
    }
    return value;
}

int main () {
    // *** task 1 ***
    std::vector<int> v1 { 1, 2, 3 };
    std::vector<int> v2 { 4, 5, 6 };
    std::vector<int> v3 = concatination(v1, v2);
    print(v3);
    
    // *** task 2 ***
    std::cout << functionNX(10, 5) << std::endl;
    std::cout << functionNX(19, 4) << std::endl;
    
    // *** task 3 ***
    std::forward_list<int> list { 10, 11, 12, 13, 14, 15 };
    std::forward_list<int> listR = reverse(list);
    print(listR);
    
    std::cout << "*** END ***" << std::endl;
    return 0;
}