#include <main.h>
#include <iostream>

int main()
{
    std::string line;
    getline(std::cin, line);
    std::vector<std::pair<std::string, size_t>> usedWords {wordCounter(line)};
    for (const auto & entry: usedWords) {
        std::cout << entry.first << ' ' << entry.second << std::endl;
    }
    return 0;
}
