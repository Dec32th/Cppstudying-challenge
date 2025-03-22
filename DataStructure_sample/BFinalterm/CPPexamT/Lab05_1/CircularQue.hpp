#include<iostream>
using namespace std;

template<class ItemType>
class CircularQue
{
public:
	CircularQue(int max_item = 10);
	~CircularQue();
	bool isEmpty() const;
	bool isFull() const;
	bool EnQue(const ItemType& input);
	bool DeQue(ItemType& output);
	CircularQue(const CircularQue& org);
	CircularQue<ItemType>& operator=(const CircularQue& org);

private:
	ItemType* m_items;
	int front;
	int rear;
	int max;
};

template<class ItemType>
CircularQue<ItemType>::CircularQue(int max_item)
{
	max = max_item + 1;
	m_items = new ItemType [max];

}

template<class ItemType>
CircularQue<ItemType>::~CircularQue()
{
	delete [] m_items;
}

template<class ItemType>
bool CircularQue<ItemType>::isEmpty() const
{
	return front == rear;
}

template<class ItemType>
bool CircularQue<ItemType>::isFull() const
{
	return front == (rear+1)%max;
}

template<class ItemType>
bool CircularQue<ItemType>::EnQue(const ItemType& input)
{
	if (!isFull())
	{
		m_items[rear] = input;
		rear = (rear + 1) % max;
		return true;
	}
	else
		return false;
}

template<class ItemType>
bool CircularQue<ItemType>::DeQue(ItemType& output)
{
	if (!isEmpty())
	{
		output = m_items[front];
		front = (front + 1) % max;
		return true;
	}
	else
		return false;
}
template<class ItemType>
CircularQue<ItemType>::CircularQue(const CircularQue& org)
{
	max = org.max;
	front = org.front;
	rear = org.rear;
	m_items = new ItemType[max];
}

template<class ItemType>
CircularQue<ItemType>& CircularQue<ItemType>::operator=(const CircularQue& org)
{
	if (this != &org)
	{
		delete[] m_items;
		max = org.max;
		front = org.front;
		rear = org.rear;
		m_items = new ItemType[];
	}

	for (int i = 0; i < max; i++)
	{
		m_items[i] = org.m_items[i];
	}
	return *this;
}