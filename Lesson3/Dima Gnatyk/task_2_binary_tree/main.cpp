#include <iostream>
#include <queue>

struct Node {
 	int n;
	Node *left;
	Node *right;
 	Node *level;
};

void linkLevelNodes(Node* root) 
{
	if(!root){
		return;
	}  

	std::queue<Node*> binary_tree;
	binary_tree.push(root);
	binary_tree.push(nullptr);
	while(!binary_tree.empty())
	{
		Node* tmp = binary_tree.front();
		binary_tree.pop();
		tmp->level = binary_tree.front();

		if(tmp->left)
		{
			binary_tree.push(tmp->left);
		} 

		if(tmp->right)
		{
			binary_tree.push(tmp->right);
		}  

		if(!binary_tree.front())
		{
			binary_tree.pop();

			if(!binary_tree.empty())
			{
				binary_tree.push(nullptr);
			}  
		}

		std::cout << tmp->n <<" -> " << tmp->level << " -> "<< std::endl;
	}
}

Node* Insert(Node *root, int data) {
	if (root == nullptr) 
	{
		root = new Node();
		root->n = data;
		root->left = nullptr;
		root->right = nullptr;
		root->level = nullptr;
	}
	else 
	{
		Node* current;
		if(data <= root->n)
		{
			current = Insert(root->left, data);
			root->left = current;
		}
		else
		{
			current = Insert(root->right, data);
			root->right = current;
		}
	}
	return root;
}

int main()
{
	Node* root = nullptr;
	root = Insert(root, 3);
	root = Insert(root, 2);
	root = Insert(root, 5);
	root = Insert(root, 1);
	root = Insert(root, 4);
	root = Insert(root, 7);

	linkLevelNodes(root);
  return 0;
}