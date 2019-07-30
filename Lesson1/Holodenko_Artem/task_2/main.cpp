#include <iostream>
#include <list>
#include <math.h>

void print_list(std::list<int> &values)
{
    for (const auto& element : values)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


std::list<int> magic_number(const size_t number, const size_t degree)
{
    std::list<int> number_l;
    int numeric;
    for (int i=1; i<=degree; i++)
    {
        numeric = pow(number, i);

        int a = numeric;
        while (a>9) {
            a = a/10;
        }
        number_l.push_back(a);

        if (numeric > 9)
        {
            number_l.push_back(numeric%10);
        }
    }
    return number_l;
}


int main()
{

    size_t number, degree;

    std::cout << "Enter number: ";
    std::cin >> number;
    std::cout << "Enter degree: ";
    std::cin >> degree;

    std::list<int> number_l = magic_number(number, degree);
    print_list(number_l);

    return 0;
}

