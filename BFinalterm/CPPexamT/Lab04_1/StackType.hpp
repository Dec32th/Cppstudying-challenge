#include<iostream>
using namespace std;

const int MAX_ITEMS = 6;

class EmptyStack 
{};

template<class ItemType>
class Stack
{
public:
	Stack();
	~Stack() {};
	bool IsEmpty();
	bool IsFull();
	void Push(ItemType item);
	void Pop();
	ItemType Top();
private:
	ItemType stack[MAX_ITEMS];
	int top;

};

template<class ItemType>
Stack<ItemType>::Stack()
{
	top = -1;
}



template<class ItemType>
bool Stack<ItemType>::IsEmpty()
{
	return (top == -1);
}

template<class ItemType>
bool Stack<ItemType>::IsFull()
{
	return (top == (MAX_ITEMS - 1));
}

template<class ItemType>
void Stack<ItemType>::Push(ItemType item)
{
	top++;
	stack[top] = item;
}

template<class ItemType>
void Stack<ItemType>::Pop()
{
	/*cout << stack[top] << endl;*/
	top--;
}

template<class ItemType>
ItemType Stack<ItemType>::Top()
{
	if (!IsEmpty())
		return stack[top];
	else
		return -1;
}
