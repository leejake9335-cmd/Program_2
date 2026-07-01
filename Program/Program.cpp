#include <iostream>

using namespace std;

template <typename T>
class Tree
{
private:

	struct Node
	{
		T data=0;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	Node* root;

public:

	Tree()
	{
		root = nullptr;

		Node T data
	}

	void insert(T data)
	{
	
		if (root == nullptr)
		{
			root = new Node(data);
		}
		else
		{
			Node* currentNode = root;
		
			while (currentNode != nullptr)
			{
				
				if(data < currentNode->data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = new Node(data);
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else if (data > currentNode->data)
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = new Node(data);
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				else
				{
					break;
				}
			}

		}
	}



};

int main()
{
	Tree<int> tree;

	tree.insert(10);
	tree.insert(20);
	tree.insert(13);
	tree.insert(15);
	tree.insert(17);


	
	return 0;

};