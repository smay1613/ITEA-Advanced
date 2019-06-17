#include "functions.h"

int main()
{
    std::string file_name;
    std::string text;
    int choice{0};
    std::cout << "Do you like to read from file(enter 1) or text(enter 2)?" << std::endl;
    std::cin >> choice;
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
        return 0;
}
