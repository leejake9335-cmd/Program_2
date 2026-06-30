#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;

		Node* next;
	};
	struct Bucket
	{
		int count;
		Node* head;
	};

	int size;
	int capacity;

	Bucket* bucket;

public:
	HashTable()
	{
		size = 0;
		capacity = 8;

		bucket = new Bucket[capacity];

		for (int i = 0; i < capacity; i++)
		{
			bucket[i].head = nullptr;
			bucket[i].count = 0;
		}
	}


	template<typename KEY>
	unsigned int hash_function(KEY key)
	{
		return (unsigned int)key % capacity;
	}

	template<>
	unsigned int hash_function(const char* key)
	{
		unsigned int sum = 0;

		while (*key == '\0')
		{
			sum += *key;
			key++;
		}
		return sum % capacity;
	}

	void insert(KEY key, VALUE value)
	{
		int hashindex = hash_function(key);

		Node* newNode = new Node;

		newNode->key = key;
		newNode->value = value;
		newNode->next = nullptr;

		if (bucket[hashindex].count == 0)
		{
			bucket[hashindex].head = newNode;
		}
		else
		{
			newNode->next = bucket[hashindex].head;
			bucket[hashindex].head = newNode;
		}
		bucket[hashindex].count++;
		size++;

	}


	void erase(KEY key)
	{
		int hashindex = hash_function(key);

		Node* currentNode = bucket[hashindex].head;

		Node* previousNode = nullptr;

		if (currentNode == nullptr)
		{
			cout << "not ket found..." << endl;

		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->key == key)
				{
					if (currentNode == bucket[hashindex].head)
					{
						bucket[hashindex].head = currentNode->next;
					}
					else
					{
						previousNode->next = currentNode->next;
					}
					size--;

					delete currentNode;

					return;

				}
				else
				{
					previousNode = currentNode;

					currentNode = currentNode->next;
				}
			}
		}

	}

	const int& bucket_count()
	{
		return capacity;
	}

	const float& load_factor()
	{
		return(float)size / capacity;
	}

	~HashTable()
	{

		for (int i = 0; i < capacity;i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = deleteNode;
			if (bucket[i].head == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}
		}
		delete[] bucket;
	}
};


int main()
{
	HashTable<const char*, int> hashtable;

	hashtable.insert("닌탑", 10);
	hashtable.insert("bami", 1);
	hashtable.insert("donkihotei", 156);

	hashtable.erase("닌탑");

	hashtable.erase("void staff");

	cout << "Load Factor : " << hashtable.load_factor() << endl;
	cout << "Bucket Count : " << hashtable.bucket_count() << endl;
	return 0;

};