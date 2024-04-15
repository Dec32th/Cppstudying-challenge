#include"DoubleStack.h"
#include<iostream>

using namespace std;

//flag1,2의 값은 Push일 때 증가시킨 후에 넣기
doubleStack::doubleStack()
{
	flag1 = -1;
	flag2 = 200;
}

bool doubleStack::IsEmpty()
{
	return(flag1 == -1 && flag2 == 200);
}

bool doubleStack::IsFull()
{
	return(flag2 - flag1 == 1);
}

void doubleStack::Push(int item)
{
	if (IsFull())
		throw EmptyStack();
	else
	{
		if (item > 1000)
		{
			--flag2;
			items[flag2] = item;
		}
		else
		{
			++flag1;
			items[flag1] = item;
		}
	}
}

void doubleStack::Print()
{

	if (IsEmpty())
		cout << "There is Empty stack.";
	else
	{
		while (flag1 > -1)
		{
			cout << items[flag1] << endl;
			flag1--;
		}
		while (flag2 < 200)
		{
			cout << items[flag2] << endl;
			flag2++;
		}
	}

}