#include "homework.h"
#include "functions.h"
#include "gtest/gtest.h"




bool comparator ( std::vector<std::string> lhs, std::set<std::string> rhs )
{
    if(lhs.size() != rhs.size())
        return false;
    for (auto & value_lhs: lhs){
        std::string tmp_lhs{value_lhs};
        bool stringQqual{false};
        std :: transform( tmp_lhs.begin(), tmp_lhs.end(),
                          tmp_lhs.begin(), ::tolower );
        // std::cout<< tmp_lhs << std::endl;

        for(auto & value_rhs: rhs){
            std::string tmp_rhs{value_rhs};
            std :: transform( tmp_rhs.begin(), tmp_rhs.end(),
                              tmp_rhs.begin(), ::tolower );
            if(tmp_lhs == tmp_rhs){
                stringQqual = true;
                break;
            }
        }
        if(stringQqual == false)
            return false;
    }
    return true;
}

bool comparatorForMap(std::vector<std::pair<std::string, size_t>>lhs, std::vector<std::pair<std::string, size_t>>rhs ){
    std::string sd{};
    std::cout <<lhs[0].first<<  lhs[0].second << "              "<< rhs[0].second<< std:: endl << std:: endl;
    if(lhs[0].first == sd && rhs[0].first == sd && lhs[0].second == rhs[0].second){
        return true;
    }
    if(lhs.size() != rhs.size())
        return false;
    for (auto & value_lhs: lhs){
        std::string tmp_lhs{value_lhs.first};
        bool stringQqual{false};
        std :: transform( tmp_lhs.begin(), tmp_lhs.end(),
                          tmp_lhs.begin(), ::tolower );
        for(auto & value_rhs: rhs){
            std::string tmp_rhs{value_rhs.first};
            std :: transform( tmp_rhs.begin(), tmp_rhs.end(),
                              tmp_rhs.begin(), ::tolower );
            if(tmp_lhs == tmp_rhs){
                if(value_lhs.second == value_rhs.second){
                    stringQqual = true;
                    break;
                }
                else
                    return false;
            }

        }
        if(stringQqual == false)
            return false;
    }
    return true;
}



INSTANTIATE_TEST_CASE_P(getUniqueWords,
                        getUniqueWordsData,
                        ::testing::Values( "Container adapters are a special type of container class.",
                                           "AAA aaa AaA aAa",
                                           "AAA sss WWW xxx aaa SSS",
                                           "",
                                           "123, 321, A, a,"
                                           ));

int i {0};

TEST_P(getUniqueWordsData, needTrue)
{
    std::vector<std::string> result_vector = getUniqueWords(GetParam());

    EXPECT_EQ(true, comparator(result_vector, correctResult[i++]));
}


INSTANTIATE_TEST_CASE_P(wordCounter,
                        wordCounterData,
                        ::testing::Values( "Container adapters are a special type of container class.",
                                           "AAA aaa AaA aAa",
                                           "AAA sss WWW xxx aaa SSS",
                                           "",
                                           "123, 321, A, a,"
                                             ));

int n {0};
TEST_P(wordCounterData, needTrue)
{
    std::vector<std::pair<std::string, size_t>>result_vector = wordCounter(GetParam());
    EXPECT_EQ(true, comparatorForMap(result_vector, correctResult[n++]));
}





