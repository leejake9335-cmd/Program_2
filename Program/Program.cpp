#include <iostream>

using namespace std;

template <typename T>
class ParorityQueue
{
private:
	int index;

	int capacity;

	T* container;

public:

	ParorityQueue()
	{
		index = 0;
	
		capacity = 0;

		container = nullptr;
	}
	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];
		
		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}
		
		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}
		
		delete[] container;
		
		container = temporary;
	}



};


int main()
{
	ParorityQueue<int> parorityqueue;

	parorityqueue.resize(1);
	
	parorityqueue.resize(2);
	
	parorityqueue.resize(4);
	
	return 0;

}