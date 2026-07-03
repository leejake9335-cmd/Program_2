#include <iostream>

using namespace std;

template <typename T>
class Tree
{
private:

	struct Node
	{
		T data = 0;
		Node* left;
		Node* right;

		Node(T data)
		{
			this->data = data;

			left = nullptr;
			right = nullptr;
		}

	};

	Node* root;

public:

	Tree()
	{
		root = nullptr;
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

				if (data < currentNode->data)
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = new Node(data);
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

	void inorder(Node* root)
	{
		if (root != nullptr)
		{
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}

	}

	void render()
	{
		inorder(root);
	}

	void erase(T data)
	{
		Node* currentNode = root;
		Node* parentNode = nullptr;

		while (currentNode != nullptr && currentNode->data != data)
		{
			parentNode = currentNode;

			if (data < currentNode->data)
			{
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->right;
			}

		}
		if (currentNode == nullptr)
		{
			cout << "The data does not exist" << endl;

			return;
		}
		else if (currentNode->right == nullptr && currentNode->left == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}

				else
				{
					parentNode->right = nullptr;
				}
			}
			else
			{
				root == nullptr;
			}
			delete currentNode;
		}

		else
		{
			Node* childNode = currentNode->right;
			Node* traceNode = currentNode;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->left;
			}

			currentNode->data = childNode->data;
			if (traceNode == currentNode)
			{
				traceNode->right = childNode->right;
			}
			else
			{
				traceNode->left = childNode->right;
			}
			delete childNode;
		}

	}

	void relese(Node* root)
	{
		if (root != nullptr)
		{
			release(root.left);
		}
	}
	~Tree()
	{
		release(root);
	}

};

int main()
{
	Tree<int> tree;

	tree.insert(10);
	tree.insert(6);
	tree.insert(15);
	tree.insert(2);
	tree.insert(13);
	tree.insert(22);
	tree.insert(18);
	tree.insert(29);
	tree.insert(20);

	tree.erase(29);

	tree.render();

	return 0;

};