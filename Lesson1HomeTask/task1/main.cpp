#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
void print_vector (std::string&& vec_name, const std::vector<T>& vec)
{
    std::cout << vec_name << ": ";
    for (const auto& el : vec)
        std::cout << el << ", ";
    std::cout << std::endl;
}


template <typename T>
std::vector<T> my_merge (const std::vector<T>& v1, const std::vector<T>& v2)
{
//    //------------------------------------------------------------------------------
//    // Way1
//    std::vector<T> result {v1};
//    const auto  result_size = v1.size() + v2.size();
//    result.resize(result_size);

//    auto it = std::next (result.begin(), v1.size());

//    std::copy (v2.begin(), v2.end(), it);

    //------------------------------------------------------------------------------
    // Way 2
    std::vector<T> result {v1};
    for (const auto& el : v2)
        result.push_back (el);

//    //------------------------------------------------------------------------------
//    // Way 3
//    std::vector<T> v1_copy = v1;
//    std::vector<T> v2_copy = v2;

//    std::sort (v1_copy.begin(), v1_copy.end());
//    std::sort (v2_copy.begin(), v2_copy.end());

//    std::vector<T> result;

//    result.resize (v1.size() + v2.size());

//    std::merge (v1_copy.begin(), v1_copy.end(),
//                v2_copy.begin(), v2_copy.end(),
//                result.begin());

    return result;
}


int main()
{
    using my_vec_t = std::vector<int>;

    std::cout << "---------------------------" << std::endl;
    std::cout << "Test1" << std::endl;
    {
        my_vec_t vec1 {0, 1, 2, 3, 4},
                 vec2 {5, 6, 7, 8, 9};

        my_vec_t result = my_merge (vec1, vec2);

        print_vector ("vec1", vec1);
        print_vector ("vec2", vec2);
        print_vector ("resutl", result);
    }

    std::cout << "---------------------------" << std::endl;
    std::cout << "Test2" << std::endl;
    {
        my_vec_t vec1 {},
                 vec2 {5, 6, 7, 8, 9};

        my_vec_t result = my_merge (vec1, vec2);

        print_vector ("vec1", vec1);
        print_vector ("vec2", vec2);
        print_vector ("resutl", result);
    }

    std::cout << "---------------------------" << std::endl;
    std::cout << "Test3" << std::endl;
    {
        my_vec_t vec1 {0, 1, 2, 3, 4},
                 vec2 {};

        my_vec_t result = my_merge (vec1, vec2);

        print_vector ("vec1", vec1);
        print_vector ("vec2", vec2);
        print_vector ("resutl", result);
    }

    std::cout << "---------------------------" << std::endl;
    std::cout << "Test4" << std::endl;
    {
        my_vec_t vec1 { 550,  231, 1232, 45233, 12344},
                 vec2 {7565, 6234, 7756};

        my_vec_t result = my_merge (vec1, vec2);

        print_vector ("vec1", vec1);
        print_vector ("vec2", vec2);
        print_vector ("resutl", result);
    }
    return 0;
}
