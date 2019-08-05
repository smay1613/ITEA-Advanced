#include <../include/functions.h>

namespace functions
{
//TASK _ 1
std::vector<int> concat(const std::vector<int>::iterator vec_1_begin, const std::vector<int>::iterator vec_1_end,
                        const std::vector<int>::iterator vec_2_begin, const std::vector<int>::iterator vec_2_end)
{
//    std::vector<int> tmp_vec{vec_1_begin, vec_1_end};
//    tmp_vec.insert(tmp_vec.end(), vec_2_begin, vec_2_end);
    std::vector<int> tmp_vec{};
    tmp_vec.insert(tmp_vec.end(), vec_1_begin, vec_1_end);
    tmp_vec.insert(tmp_vec.end(), vec_2_begin, vec_2_end);

    return tmp_vec;
}
}//namespace functions
