#include <main.h>
#include <iostream>

int main()
{
    std::string line;
    getline(std::cin, line);
    std::vector<std::string> usedWords {getUniqueWords(line)};
    for (const auto & entry: usedWords) {
        std::cout << entry << ' ';
    }
    std::cout << std::endl;

    return 0;
}
