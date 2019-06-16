#include "functions.h"


void show_tree(node* head)
{
    std::queue<node*> list_tree;
    list_tree.push(head);
    while(true){
    size_t sub_value = list_tree.size();
    if(sub_value == 0){
        break;
    }
    size_t tabs = 0;
    while(tabs<sub_value){
        node* num = list_tree.front();
        std::cout << num->value << " ";
        if(num->left != 0){
            list_tree.push((num->left));
        }
        if(num->right != 0){
            list_tree.push(num->right);
        }
        list_tree.pop();
        tabs++;
    }
    std::cout << std::endl;
}
}

node::node(int m_value, node *m_left, node *m_right)
{
    value = m_value;
    left = m_left;
    right = m_right;

}
