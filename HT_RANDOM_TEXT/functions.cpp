#include "functions.h"



void count_word(std::string word)
{
    int count{0};
    while(word == word){
        std:: cout << "the number of: " << word << " is " << count++ << std::endl;
    }
}

void unique_word(std::string word_u)
{
    while(word_u != word_u){
        std::cout << word_u << "only one case" << std::endl;
    }
}

void read_file(std::string filename)
{
    std::string word_f;
    std::ifstream file;
    file.open(filename);
    if(file.is_open()){
        while(!file.eof()){
            while(file >> word_f){
            if(word_f.size() > 0){
                std::cout << word_f << " | ";
            }
            count_word(word_f);
            unique_word(word_f);
            }
        }
        std::cout << std::endl;
        file.close();
    }
}

void read_text(std::string m_text)
{
    std::string word_t;
    while(!m_text.back()){
        if(word_t.size() > 0){
            std::cout << word_t << " / ";
        }
        count_word(word_t);
        unique_word(word_t);
    }
    std::cout << std::endl;
}
