#include "task.h"

int main(){
    int S{0};
    bool Work = true;
    while(Work){
        std::cout << "Please choose your task: " << std::endl;
        std::cout << " possible task - 0-2" << std::endl;
        std::cin >> S;
        switch(S){
        case 0:
            MySpace::task1();
            break;
        case 1:
            MySpace::task2();
            break;
        case 2:
            MySpace::task3();
            break;
        default:
            break;
        }
        std::cout << "Do You wish to continue?: " << std::endl;
        std::cout << "1 - yes, 0 - no." << std::endl;
        std::cin >> Work;

    }
    return 0;
}

