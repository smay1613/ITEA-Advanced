#include <iostream>
#include <vector>


template <typename type> void print_vector(std::vector<type> &values)
{
    for (const auto& element : values)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


template <typename type> std::vector<int> sum_vectors(std::vector<type> &data_1, std::vector<type> &data_2)
{
    std::vector<int> data_3;
    data_3.reserve(data_1.size() + data_2.size());

    for (const auto& element : data_1)
    {
        data_3.push_back(element);
    }
    for (const auto& element : data_2)
    {
        data_3.push_back(element);
    }

    return data_3;
}


int main()
{
    std::vector<int> data_1 { 1, 2, 3, 4, 5 };
    std::vector<int> data_2 { 5, 4, 3, 2, 1 };
    std::vector<int> data_3;

    data_3 = sum_vectors(data_1, data_2);
    print_vector(data_3);

    return 0;
}

