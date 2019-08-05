#include <QCoreApplication>
#include "main.h"

int main()
{
    std::cout << "Enter sequence of brackets" << std::endl;
    std::string sequence;
    std::cin >> sequence;

    try {
        std::cout << isExpressionValid(sequence) << std::endl;
    } catch (const std::invalid_argument & thrownException) {
        std::cout << thrownException.what();
    }

    return 0;
}
