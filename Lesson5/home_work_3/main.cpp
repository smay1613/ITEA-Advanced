#include <iostream>
#include <header.h>
#include <set>


int main()
{
    //Task _ 1
    std::cout << "TASK - 1---------------------------------------------------------" << std::endl;
    std::vector<std::string> resultTask_1 = getUniqueWords("some text here ! some");
    std::cout << "Found " << resultTask_1.size() << " unique words : ";
    print(resultTask_1);
    std::cout << std::endl;

    //Task _ 2
    std::cout << "TASK - 2---------------------------------------------------------" << std::endl;
    std::vector<std::pair<std::string, size_t>> resultTask_2 = wordCounter("some text here ! some some");
    std::cout << "Found " << resultTask_2.size() << " unique words : " << std::endl;
    print(resultTask_2);
    std::cout << "-----------------------------------------------------------------" << std::endl;


    return 0;
}
