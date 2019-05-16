#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using my_vec_t = std::vector<int>;

my_vec_t my_merge1 (const my_vec_t& v1, const my_vec_t& v2)
{
    my_vec_t result {v1};
    const auto  result_size = v1.size() + v2.size();
    result.resize(result_size);

    auto it = std::next (result.begin(), v1.size());

    std::copy (v2.begin(), v2.end(), it);
    return result;
}

my_vec_t my_merge2 (const my_vec_t& v1, const my_vec_t& v2)
{
    my_vec_t result {v1};
    for (const auto& el : v2)
        result.push_back (el);
    return result;
}

my_vec_t my_merge3 (const my_vec_t& v1, const my_vec_t& v2)
{
    my_vec_t v1_copy = v1;
    my_vec_t v2_copy = v2;

    std::sort (v1_copy.begin(), v1_copy.end());
    std::sort (v2_copy.begin(), v2_copy.end());

    my_vec_t result;

    result.resize (v1.size() + v2.size());

    std::merge (v1_copy.begin(), v1_copy.end(),
                v2_copy.begin(), v2_copy.end(),
                result.begin());

    return result;
}


void print_vector (const my_vec_t& vec)
{
    for (const auto& el : vec)
        std::cout << el << "  ";
}

void run_test (const my_vec_t& v1, const my_vec_t& v2, my_vec_t (*merge_func)(const my_vec_t& v1, const my_vec_t& v2))
{
        std::cout << "Running test: " ;
        std::cout << std::endl;

        std::cout << "First vector: ";
        print_vector(v1);
        std::cout << std::endl;

        std::cout << "Second vector: ";
        print_vector(v2);
        std::cout << std::endl;

        auto result_v = merge_func(v1, v2);

        std::cout << "Result vector: ";
        print_vector(result_v);
        std::cout << std::endl;

        std::cout << std::endl;
}


int main()
{
    my_vec_t v1 {0, 1, 2, 3, 4};
    my_vec_t v2 {5, 6, 7, 8, 9};
    my_vec_t v3 {550, 231, 1232, 45233, 12344};
    my_vec_t v4 {7565, 6234, 7756};


    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Tests with 'my_merge1' function" << std::endl;
    auto merge_f = my_merge1;
    run_test (v1, v2, merge_f);
    run_test ({}, v2, merge_f);
    run_test (v1, {}, merge_f);
    run_test (v3, v4, merge_f);


    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Tests with 'my_merge2' function" << std::endl;
    merge_f = my_merge2;
    run_test (v1, v2, merge_f);
    run_test ({}, v2, merge_f);
    run_test (v1, {}, merge_f);
    run_test (v3, v4, merge_f);


    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Tests with 'my_merge3' function" << std::endl;
    merge_f = my_merge3;
    run_test (v1, v2, merge_f);
    run_test ({}, v2, merge_f);
    run_test (v1, {}, merge_f);
    run_test (v3, v4, merge_f);

    return 0;
}
