#include "tst_hw_2_tests.h"

#include <gtest/gtest.h>
#include <stack>

bool isExpressionValid (const std::string& expression)
{
    std::stack<char> receivedMessage;

    for(const auto& element : expression)
    {
        if(element == '(' || element == '[' || element == '{')
        {
            receivedMessage.push(element);
        }
        else
        {
            if ( !receivedMessage.empty() &&
                ((element == ')' && receivedMessage.top() == '(') ||
                (element == ']' && receivedMessage.top() == '[') ||
                (element == '}' && receivedMessage.top() == '{')))
            {
                receivedMessage.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return receivedMessage.empty();
}

//void linkLevelNodes(node* (или std::shared_ptr<node> - *КРАЙНЕ ПРЕДПОЧТИТЕЛЬНЕЕ ЕГО ИСПОЛЬЗОВАНИЕ!*)

int main(int argc, char *argv[])
{
    //std::string input {"{{}[[()]()]{}}"};
    //bool answer = isExpressionValid(input);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
