#include <iostream>
#include <list>


int main()
{
    int X;
    int N;
    std::cout <<"Enter N: ";
    std::cin >> N;
    std::cout <<"Enter X: ";
    std::cin >> X;
    std::list<int>result;
    int numberDegree = 1;
    for (int i = 1; i<=X; i++){
        numberDegree *= N;
        int tmpFirstNumber = numberDegree;
        int tmpSecondNubmer = numberDegree % 10;
        while (tmpFirstNumber > 9) {
            tmpFirstNumber /= 10;
        }
        result.push_back(tmpFirstNumber *10 + tmpSecondNubmer);
    }
    for(const auto &value: result){
        std::cout << value;
    }
    return 0;
}
