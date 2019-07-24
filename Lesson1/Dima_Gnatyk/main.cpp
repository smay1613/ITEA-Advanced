#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>

template <class T>
void print(const std::vector<T> &data){
    for(auto value:data){
        std::cout <<value<<" ";
    }
    std::cout<<std::endl;
}

template <class T>
std::vector<T> concat(const std::vector<T> &data_vector_1, const std::vector<T> &data_vector_2){
    if(data_vector_1.empty()) return data_vector_2;
    if(data_vector_2.empty()) return data_vector_1;

    std::vector<T> union_vector {};
    union_vector.reserve(data_vector_1.size()+data_vector_2.size());
    union_vector.insert(union_vector.cend(), data_vector_1.cbegin(), data_vector_1.cend());
    union_vector.insert(union_vector.cend(), data_vector_2.begin(), data_vector_2.end());

    return union_vector;
}

template <class T>
std::list<T> new_number(const T &number, const T &pow){
    std::list<T> result {};
   // if(number > 0) return result.push_back(0);
    //if(pow == 0) return result.push_back(1);
    unsigned int number_result {1};
    unsigned int first_number {0};
    unsigned int last_number {0};
    for(size_t i = 0; i < pow; ++i){
        number_result *= number;
        first_number = number;
        last_number = number % 10;
        while(first_number > 9){
            first_number /= 10;
        }
        result.push_back(first_number *10 + last_number);
    }
    for(const auto &value: result){
        std::cout << value;
    }
    return result;
}

template<class T>
std::forward_list<T> reverse_forvard_list(const std::forward_list<T> &data){
    if(data.empty()){
        std::cout << "Forward list empty!";
        return data;
    }
    std::forward_list<T> result {};
    for(const auto &value: data){
        result.push_front(value);
    }
    for(const auto & value: result){
        std::cout << value;
    }
    return result;
}


