#include "functions.h"


void read_file(std::string filename)
{
    int count{0};
    std::string word_f;
    std::ifstream file;
    file.open(filename);
    if(file.is_open()){
        while(!file.eof()){
            while(file >> word_f){
                if(word_f.size() > 0){
                    std::cout << word_f << std::endl;
                    count++;
                }
            }


        }
        std::cout << std::endl;
    }
    std::cout << "Word count in file is: " << count << std::endl;
    file.close();
}

void read_text(std::string m_text)
{   int count{0};
    std::getline(std::cin,m_text);
    std::istringstream iss(m_text);
    std::string word_out;
    std::cout << std::endl;
    while(iss >> word_out){
        std::cout << word_out << std::endl;
        count++;
    }std::cout << "Word count in text is: " << count << std::endl;
}
