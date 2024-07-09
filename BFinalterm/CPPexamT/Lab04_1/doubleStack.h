#pragma once
#include<iostream>

const int MAX_ITEMS2 = 200;
using namespace std;

class DoubleStackType
{
public:
	DoubleStackType();
	~DoubleStackType() {};
	void push(int item);
	bool IsEmpty();
	bool IsFull();
	void Print();
	
private:
	int items[MAX_ITEMS2];
	int top1;
	int top2;
};

DoubleStackType::DoubleStackType()
{
	top1 = -1;
	top2 = MAX_ITEMS2;
}

void DoubleStackType::push(int item)
{
	if (item <= 1000)
	{
		top1++;
		items[top1] = item;
	}
	else
	{
		top2--;
		items[top2] = item;
	}
}

bool DoubleStackType::IsEmpty()
{
	return (top1 == -1 && top2 ==(MAX_ITEMS2-1));
}

bool DoubleStackType::IsFull()
{
	return (top2-top1 == 1);
}

void DoubleStackType::Print()
{
	cout << "Under 1000" << endl;
	for(int i  = top1; top1 >=0; top1--)
		cout << items[top1] << endl;

	cout << "over 1000" << endl;

	for (int j = top2; top2 < 200;top2++)
		cout << items[top2] << endl;
	
}