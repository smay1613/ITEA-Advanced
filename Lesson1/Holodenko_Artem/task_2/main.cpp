#include <iostream>
#include <list>
#include <math.h>

template <typename type> void print_list(std::list<type> &value)
{
    for (const auto& element : value)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::list<int> number_l;
    int N, X;

    std::cout << "Enter N: ";
    std::cin >> N;
    std::cout << "Enter X: ";
    std::cin >> X;

    {
        int numeric;
        for (int i=1; i<=X; i++)
        {
            numeric = pow(N, i);

            int a = numeric;
            while (a>9) {
                a = a/10;
            }
            number_l.push_back(a);
            if (numeric>9)
            {
                number_l.push_back(numeric%10);
            }

        }
    }

    print_list(number_l);

    return 0;
}
