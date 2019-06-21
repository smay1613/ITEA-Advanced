#include "functions.h"

int main()
{
    std::string welcome{"Do you like to read from file(enter 1) or text(enter 2)? \n Enter 0 to exit."};
    std::string file_name;
    std::string text;
    int choice{0};
    std::cout << welcome << std::endl;
    std::cin >> choice;
    while(choice){
        switch(choice){
        case 1:
            std::cout << " enter the name of the file" << std::endl;
            std::cin >> file_name;
            read_file(file_name);
            break;
        case 2:
            std::cout << "enter the text:" << std::endl;
            std::cin >> text;
            read_text(text);
            break;
        default:
            break;
        }
        std::cout << welcome << std::endl;
        std::cin >> choice;
        if(choice == 0){
            return 0;
        }

    }
}
