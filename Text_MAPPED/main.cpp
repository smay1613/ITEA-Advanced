#include "functions.h"

int main()
{
    int F{1};
    std::string path{""};
    std::string welcome{"Please input file name with path to file"};
    std::string tokens;

    typedef std::pair<std::string, WordCounter> word_mapping;

    std::unordered_map<std::string, WordCounter> counter;
    std::cout << "To open file enter 1, to enter text please enter 2" << std::endl;
    std::cin >> F;
    if(F==1){
    std::cout << welcome << std::endl;
    std::cin >> path;
    std::ifstream input;
    input.open(path.c_str());

    if (!input)
    {
        std::cout << "Error in opening file" << std::endl;
        return 0;
    }
    while(true)
    {
        input >> tokens;

        tokens.resize(remove_if(tokens.begin(), tokens.end(), filter) - tokens.begin());

        if(input)
        {
            counter[tokens]++;
        }
        else break;
    }
}
    if(F==2){
        std::string m_text{""};
        std::cout << "before inputting text place type '... '" << std::endl;
        std::cin >> m_text;
        std::getline(std::cin,m_text);
        std::istringstream iss(m_text);
        std::string tokens;
        std::cout << std::endl;
        while(true)
        {
            iss >> tokens;

            tokens.resize(remove_if(tokens.begin(), tokens.end(), filter) - tokens.begin());

            if(iss)
            {
                counter[tokens]++;
            }
            else break;
        }
    }


    std::vector<word_mapping> result(counter.begin(),counter.end());

    std::sort(result.begin(),result.end(),less_second<word_mapping>());

    for(std::vector<word_mapping>::const_iterator m_iterator = result.begin(); m_iterator != result.end(); m_iterator++)
    {
        std::cout << std::setw(15) << (*m_iterator).first << "\t\t\t\t" << (*m_iterator).second.value << std::endl;
    }


    return 0;
}
