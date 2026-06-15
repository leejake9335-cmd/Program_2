#include <iostream>

using namespace std;

template<typename T>
class List
{
private :
	struct Node
	{
		T data = 0;
		Node* next = nullptr;
		Node* previous = nullptr;
	};

	int size;

	Node* head;

	Node* tail;

public:

	List()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	
	void push_fornt(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		
		newNode->next = nullptr;

		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;

			newNode->next = head;
			
			head = newNode;
		}

		size++;
	}
	
	void pop_fornt()
	{
		if (head == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail)
			{
				head = nullptr;

				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;

				head = head->next;
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

		newNode->previous = nullptr;

		if (tail == nullptr)
		{
			newNode = head;

			newNode = tail;
		}
		else
		{
			tail->next = newNode;

			newNode-> previous = tail;

			tail = newNode;
		}
		size++;
	}

	void pop_back()
	{
		if (tail == nullptr)
		{
			cout << "linked list is empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;

			if (head == tail)
			{
				head = nullptr;

				tail = nullptr;
			}
			else
			{
				tail->previous->next = nullptr;

				tail = tail->previous;
			}
			delete deleteNode;
			size--;
		}
	}
		const bool& empty()
		{
			return head == nullptr;
		}

		~List()
		{
			while (head != nullptr)
			{
				pop_back();
			}
		}

	

};

	int main()
	{

		List<int> list;
	
		list.push_fornt(10);
		list.push_fornt(15);

		list.push_back(20);
		list.push_back(30);

		list.pop_fornt();
		list.pop_fornt();
		list.pop_fornt();

		list.pop_back();
		list.pop_back();
		list.pop_back();

		return 0;

	}