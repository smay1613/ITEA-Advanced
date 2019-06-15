#include "functions.h"

int main()
{
    int times{0};
    std::cout << "Please enter how many times to check:";
    std::cin >> times;

    for(int i = 0; i < times; i++)
    {

        check_brackets();
    }

    return 0 ;
}


