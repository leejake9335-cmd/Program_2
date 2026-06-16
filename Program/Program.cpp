#include <iostream>

using namespace std;

template <typename T>

class List
{
private:
	struct Node
	{
		T data;
		Node* next;
	
	};

	int size;

	Node* head;

public:
	List()
	{
		size = 0;
		head = nullptr;
	}
	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head ->next = newNode;
			
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "Linked list is empty." << endl;
		}
		else
		{
			Node* deleteNode = head->next;
			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;
		    size--;
		}
	}
	void push_back(T data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			newNode->next = head;
		}
		else
		{
			Node* currentNode = head;
			while (currentNode->next != head)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
			newNode->next = head;
		}
		size++;
	}
};

	int main()
	{
		List<int> list;
		
		list.push_front(10);
		list.push_front(5);

		list.pop_front();
		list.pop_front();
		list.pop_front();	

		return 0;

	}