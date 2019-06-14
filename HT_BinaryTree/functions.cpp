#include "functions.h"


void show_tree(node* head)
{
    std::queue<node*> list;
    list.push(head);
    while(true){
    int vect = list.size();
    if(vect == 0){
        break;
    }
    int tabs = 0;
    while(tabs<vect){
        node* num = list.front();
        std::cout <<num->value << " ";
        if(num->left != nullptr){
            list.push((num->left));
        }
        if(num->right!=nullptr){
            list.push(num->right);
        }
        list.pop();
        tabs++;
    }
    std::cout<<std::endl;
}
}

node::node(int m_value, node *m_left, node *m_right)
{
    value = m_value;
    left = m_left;
    right = m_right;

}
