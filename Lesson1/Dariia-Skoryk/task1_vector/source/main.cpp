#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> combineVectors(std::vector<int>::iterator begin1, std::vector<int>::iterator end1, std::vector<int>::iterator begin2, std::vector<int>::iterator end2) {
    std::vector<int> resultVector;
    for (std::vector<int>::iterator iterator = begin1; iterator != end1 ; iterator++) {
        resultVector.push_back(*iterator);
    }
    for (std::vector<int>::iterator iterator = begin2; iterator != end2 ; iterator++) {
        resultVector.push_back(*iterator);
    }
    return resultVector;
}

void fillVector(std::vector<int>& vectorToFill, int capathity) {
    srand(time(nullptr));
    vectorToFill.resize(0);
    vectorToFill.reserve(capathity);
    vectorToFill.shrink_to_fit();
    for (int i = 0; i < capathity; i++) {
        vectorToFill.push_back(rand() - RAND_MAX/2);
    }
}

template<class T>
void printVector(const std::vector<T>& vectorToPrint) {
    for (const auto& entry : vectorToPrint) {
        std::cout << entry << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vector1;
    std::vector<int> vector2;
    std::vector<int> resultVector;

    int capathity;
    std::cout << "Please, enter the capathity of first vector" << std::endl;
    std::cin >> capathity;
    fillVector(vector1, capathity);
    std::cout << "Please, enter the capathity of second vector" << std::endl;
    std::cin >> capathity;
    fillVector(vector2, capathity);

    std::cout << "Your first vector" << std::endl;
    printVector(vector1);
    std::cout << "Your second vector" << std::endl;
    printVector(vector2);

    resultVector = combineVectors(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
    std::cout << "Result" << std::endl;
    printVector(resultVector);

    return 0;
}
