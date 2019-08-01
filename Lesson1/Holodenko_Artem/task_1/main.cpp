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


std::vector<int> combineVectors(const std::vector<int>::iterator &vector_1_begin, const std::vector<int>::iterator &vector_1_end,
                                 const std::vector<int>::iterator &vector_2_begin, const std::vector<int>::iterator &vector_2_end)
{
    std::vector<int> vector;
    std::vector<int>::size_type size = vector_1_end.base() - vector_1_begin.base() + vector_2_end.base() - vector_2_begin.base();
    vector.reserve(size);

    for (std::vector<int>::iterator element = vector_1_begin; element.base() < vector_1_end.base(); element++)
    {
        vector.push_back(*element);
    }

    for (std::vector<int>::iterator element = vector_2_begin; element.base() < vector_2_end.base(); element++)
    {
        vector.push_back(*element);
    }

    return vector;
}


int main()
{
    std::vector<int> data_1 { 1, 2, 3, 4, 5 };
    std::vector<int> data_2 { 6, 5, 4, 3, 2, 1 };
    std::vector<int> data_3;

    std::vector<int>::iterator vector_1_begin = data_1.begin();
    vector_1_begin++;
    std::vector<int>::iterator vector_1_end = data_1.end();
    vector_1_end--;

    data_3 = combine_vectors(vector_1_begin, vector_1_end--, data_2.begin(), data_2.end());
    print_vector(data_3);

    return 0;
}


