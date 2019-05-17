#include <iostream>
#include <cstdint>
#include <list>
#include <cmath>
#include <cstdlib>

uint64_t make_specific_number (uint32_t base, uint32_t power)
{
    std::list<uint64_t> values;

    for (uint32_t i = 1; i <= power; i++ )
    {
        values.push_back (std::pow(base, i));
    }

    if (values.empty())
    {
        return 0;
    }

    uint64_t result {0};

    for (auto& el : values)
    {
        uint8_t last_num = el % 10;
        uint64_t first_num = el;

        while (first_num >= 10)
        {
            first_num /= 10;
        }

        if (0 != result)
        {
            result *= 100;
        }
        result += first_num*10 + last_num;
    }

    return result;
}

uint64_t make_specific_number_2 (uint32_t base, uint32_t power)
{
    std::list<std::string> values;

    for (uint32_t i = 1; i <= power; i++ )
    {
        values.push_back (std::to_string (static_cast<uint64_t> (std::pow (base, i))));
    }

    if (values.empty())
    {
        return 0;
    }

    std::string result_str {};

    for (auto& el : values)
    {
        result_str += el[0];
        result_str += el[el.size()-1];
    }

    return static_cast<uint64_t>( std::atoi (result_str.c_str()) );
}


void run_test (uint32_t n, uint32_t x, uint64_t answ, uint64_t (*calculation_func)(uint32_t base, uint32_t power))
{
    auto calc_answ = calculation_func (n, x);
    std::cout << "Test: "
              << "N = " << n << "  "
              << "X = " << x << "  "
              << "Answer = " << calc_answ
              << ((answ == calc_answ) ? " - is correct" : " - IS NOT CORRECT!")
              << std::endl;
}

int main()
{
    std::cout << "Tests with `make_specific_number` function" << std::endl;
    run_test (10, 5, 1010101010, make_specific_number); // have to be correct
    run_test (10, 5,     101010, make_specific_number); // have to be not correct
    run_test (19, 4,   19316911, make_specific_number); // have to be correct
    run_test (19, 4,     316911, make_specific_number); // have to be not correct

    std::cout << std::endl;
    std::cout << "Tests with `make_specific_number_2` function" << std::endl;
    run_test (10, 5, 1010101010, make_specific_number_2); // have to be correct
    run_test (10, 5,     101010, make_specific_number_2); // have to be not correct
    run_test (19, 4,   19316911, make_specific_number_2); // have to be correct
    run_test (19, 4,     316911, make_specific_number_2); // have to be not correct

    return 0;
}
