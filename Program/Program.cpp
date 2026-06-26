#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>
class HashTable
{
private :
	struct Node
	{
		KEY key;
		VALUE value;

		Node * next;
	};
	struct Bucket
	{
		int count;
		Node * head;
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
		if (sum == NULL)
		{
			
		}
	}
};


int main()
{
	HashTable<char, int> hashtable;

	cout << hashtable.hash_function(100) << endl;
	cout << hashtable.hash_function('a') << endl;


	return 0;

}