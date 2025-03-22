#pragma once

template <typename ItemType>
class CircularQue
{
	ItemType* m_items;
	int front;
	int rear;
	int max;
public:
	CircularQue(int max_item = 10);	
	~CircularQue();
	bool isEmpty() const;
	bool isFull() const;
	bool EnQue(const ItemType & input);
	bool DeQue(ItemType& output);
	CircularQue(const CircularQue& org);
	CircularQue<ItemType> & operator=(const CircularQue& org);
};

template <typename ItemType>
bool CircularQue<ItemType>::isEmpty() const
{
	return (front == rear);
}

template <typename ItemType>
bool CircularQue<ItemType>::isFull() const
{
	return ((rear + 1) % max == front);
}

template <typename ItemType>
bool CircularQue<ItemType>::EnQue(const ItemType& input)
{
	if (rear != (max - 1))
	{
		m_items[rear] = input;
	}
	else if (this->isFull())
	{
		m_items[front] = input;
		front = (front + 1) % max;
	}

	else if(front != 0 && !(this->isEmpty()))
	{
		m_items[front] = input;
		front = (front + 1) % max;
	}
	
	else if(front !=0 && !(this->isEmpty())
	{
		m_items[front] = input;
		front = (front + 1) % max;
	}

}

template <typename ItemType>
bool CircularQue<ItemType>::DeQue(ItemType& output)
{
	if (front != 0 && !(rear == max-1))
	{
		front = (front - 1) % max;
		output = m_items[front];
	}
	else if (front == 0 && rear == max - 1)
	{
		output = m_items[front];
		rear = (rear - 1) % max;
	}
	else if(front == 0 && rear>=0)
	{
		output = m_items[rear];
		rear = (rear - 1) % max;
	}
	else if (front == 0 && rear = -1)
	{
		output = m_items[0];
		rear = 0;
	}
	else
	{	
		front = (front - 1) % max;
		output = m_items[front];
	}
}

template <typename ItemType>
CircularQue<ItemType>::CircularQue(int max_item)
{
	front = max_item;
	rear = max_item;
	max = max_item + 1;
	m_items = new ItemType[max];
}

template <typename ItemType>
CircularQue<ItemType>::~CircularQue()
{
	delete[] m_items;
}

template <typename ItemType>
CircularQue<ItemType>::CircularQue(const CircularQue& org)
{
	front = org.front;
	rear = org.rear;
	max = org.max;
	m_items = new ItemType[max];
	for (int i = 0; i < max; i++)
		m_items[i] = org.m_items[i];
}

template <typename ItemType>
CircularQue<ItemType>& CircularQue<ItemType>::operator=(const CircularQue& org)
{
	if(m_items) //사실 체크 필요 없음
		delete[] m_items;

	front = org.front;
	rear = org.rear;
	max = org.max;
	m_items = new ItemType[max];
	for (int i = 0; i < max; i++)
		m_items[i] = org.m_items[i];
	return *this;
}