#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

struct node
{
    int n = 0;
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *level = nullptr;
};


std::vector<node> get_data()
{
    int number_levels, number_nodes=0;
    std::cout << "Enter number of levels: ";
    std::cin >> number_levels;

    //кількість вузлів
    for (int i=0; i<number_levels; i++) number_nodes+=pow(2, i);

    //std::cout << number_nodes << std::endl;
    std::vector<node> data_vector (number_nodes);

    //заповнення дерева, 0 пустий вузол
    for (int i=0; i<number_nodes; i++)
    {
        std::cout << "Enter node " << i+1 << ": ";
        std::cin >> data_vector[i].n;
    }

    //створення зв'язків
    {
        int m, n;
        int level;
        for (int i=0; i<number_nodes; i++)
        {
            level = 0;
            m=i+1;
            while (m>pow(2, level))
            {
                m-=pow(2, level);
                level++;
            }
            level++;

            //std::cout << "level " << level << std::endl;
            //std::cout << "m " << m << std::endl;

            n = 0;
            for (int j=0; j<level; j++) n+=pow(2, j);
            n+=(m-1)*2;

            //std::cout << "n1 " << n << std::endl;

            if (n<number_nodes and data_vector[n].n!=0)
            {
                if (data_vector[i].n==0)
                {
                    data_vector[n].n=0;
                }
                else
                {
                    data_vector[i].left=&data_vector[n];
                }
            }

            n = 0;
            for (int j=0; j<level; j++) n+=pow(2, j);
            n+=(m-1)*2+1;

            //std::cout << "n2 " << n << std::endl;

            if (n<number_nodes and data_vector[n].n!=0)
            {
                if (data_vector[i].n==0)
                {
                    data_vector[n].n=0;
                }
                else
                {
                    data_vector[i].right=&data_vector[n];
                }
            }
        }
    }

    return  data_vector;
}





void print_node(std::vector<node> &data_vector)
{
    for (int i=0; i<data_vector.size(); i++)
    {
        if (data_vector[i].n == 0) continue;
        std::cout << "node " << data_vector[i].n << ":" <<std::endl;
        if (data_vector[i].left!=nullptr)
        {
            std::cout << "- " << data_vector[i].left->n << std::endl;
        }
        if (data_vector[i].right!=nullptr)
        {
            std::cout << "- " << data_vector[i].right->n << std::endl;
        }
        if (data_vector[i].level!=nullptr)
        {
            std::cout << "- " << data_vector[i].level->n << std::endl;
        }
    }
}


void func(std::queue<node*> data_queue)
{
    int n=0;
    int level=0;
    node *y = nullptr;
    while(!data_queue.empty())
    {
        n++;

        if (data_queue.front()->n!=0)
        {
            if (y==nullptr)
            {
                y = data_queue.front();
            }
            else
            {
                y->level=data_queue.front();
                y = data_queue.front();

            }
        }

        if (n==pow(2, level))
        {
            y = nullptr;
            level++;
            n=0;
        }

        data_queue.pop();
    }
}


int main()
{
    std::vector<node> data_vector;
    std::queue<node*> data_queue;

    data_vector = std::move(get_data());

    std::cout << std::endl;
    print_node(data_vector);

    for (int i=0; i<data_vector.size(); i++)
    {
        data_queue.push(&data_vector[i]);
    }

    func(data_queue);

    std::cout << std::endl;
    print_node(data_vector);

    return 0;
}
