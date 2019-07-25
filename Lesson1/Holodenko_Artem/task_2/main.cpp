#include <iostream>
#include <list>


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
        int z = 1;
        for (int i=0; i<X; i++)
        {
            z = z * N;

            int a=z;
            while (a>9) {
                a = a/10;
            }
            number_l.push_back(a);

            number_l.push_back(z%10);
        }
    }

    print_list(number_l);

    return 0;
}
