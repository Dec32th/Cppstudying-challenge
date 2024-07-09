#pragma once
#include<iostream>

using namespace std;

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
	bool EnQue(const ItemType& input);
	bool DeQue(ItemType& output);
	CircularQue(const CircularQue& org);
	CircularQue<ItemType>& operator=(const CircularQue& org);
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
	if (this->isFull())
	{
		return false;
	}
	else
	{
		m_items[rear] = input;
		rear = (rear + 1) % max;
		return true;
	}
}

template <typename ItemType>
bool CircularQue<ItemType>::DeQue(ItemType& output)
{
	if (this->isEmpty())
	{
		front = 0;
		rear = 0;
		return false;
	}
	else
	{
		output = m_items[front];
		front = (front + 1) % max;
		return true;
	}
}

template <typename ItemType>
CircularQue<ItemType>::CircularQue(int max_item)
{
	front = 0;
	rear = 0;
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

//깊은 복사를 진행 - 개별적인 객체를 새로 만든다!
template <typename ItemType>
CircularQue<ItemType>& CircularQue<ItemType>::operator=(const CircularQue& org)
{
	if (m_items) //사실 체크 필요 없음
		delete[] m_items;

	front = org.front;
	rear = org.rear;
	max = org.max;
	m_items = new ItemType[max];
	for (int i = 0; i < max; i++)
		m_items[i] = org.m_items[i];
	return *this;
}