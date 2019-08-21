
#include "secondHomeAdvanced.hpp"

/* 
1. bool isExpressionValid (const std::string& expression)
2. void linkLevelNodes(node* (или std::shared_ptr<node> - *КРАЙНЕ ПРЕДПОЧТИТЕЛЬНЕЕ ЕГО ИСПОЛЬЗОВАНИЕ!*)
что такое node - см. задание

1. std::vector<std::string> getUniqueWords (const std::string& text);
Немного поучитесь перекидывать с одного контейнера данные в другой:
2. std::vector<std::pair<std::string>,
                       size_t> wordCounter (const std::string& text);
*/

bool isExpressionValid (const std::string& expression)   
{
    std::stack<char> stack;

    for (auto ch : expression) {
        switch (ch) {
        case '(': 
        case '<': 
        case '[': 
        case '{': 
            stack.push(ch);
            break;
        case ')': 
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
            break;
        case '>': 
            if (stack.empty() || stack.top() != '<') return false;
            stack.pop();
            break;
        case ']': 
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
            break;
        case '}': 
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
            break;
        }
    }
    return stack.empty(); // no unmatched braces left?
}


void linkLevelNodes(Node* root)
{
    if (root == nullptr)
        return;

    std::list<Node*> queue;
    queue.push_back(root);

    std::queue<int> fifoQueue;

    Node* curr = nullptr;

    while (queue.size())
    {
        curr = queue.front();
        queue.pop_front(); 

        fifoQueue.push(curr->key);

        if (curr->right)
           queue.push_back(curr->right);  

        if (curr->left)
           queue.push_back(curr->left);  
        
    }

    while (!fifoQueue.empty())
    {
        std::cout << fifoQueue.front() << " ";
        fifoQueue.pop();
    }
}

/* 
//checks that vector v is {5, 10, 15}
ASSERT_THAT(v, ElementsAre(5, 10, 15));

//checks that map m only have elements 1 => 10, 2 => 20
ASSERT_THAT(m, ElementsAre(Pair(1, 10), Pair(2, 20)));

//checks that in vector v all the elements are greater than 10 and less than 20
ASSERT_THAT(v, Each(AllOf(Gt(10), Lt(20))));

//checks that vector v consist of 
//   5, number greater than 10, anything.
ASSERT_THAT(v, ElementsAre(5, Gt(10), _));
*/

