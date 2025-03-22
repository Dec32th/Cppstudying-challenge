#pragma once
#include<iostream>
using namespace std;
const int MAXIMUM = 8;

class iStackType
{
public:
	iStackType();
	~iStackType() {};
	void push(int item);
	void pop();
	int Top();
	bool isEmpty();
	bool isFull();
	void Print();
private:
	int top;
	int items[MAXIMUM];
};

iStackType::iStackType()
{
	top = -1;
}

bool iStackType::isEmpty()
{
	return (top == -1);
}

bool iStackType::isFull()
{
	return (top == MAXIMUM - 1);
}

void iStackType::push(int item)
{
	if (!isFull())
	{
		top++;
		items[top] = item;
	}
	else
		cout << "Invalid";
}

void iStackType::pop()
{
	if (!isEmpty())
		top--;
	else
		cout << "Invalid";
}

int iStackType::Top()
{
	return items[top];
}

void iStackType::Print()
{
	for (int i = top; i >= 0; i--)
	{
		cout << items[i] << endl;
	}
}