#include<iostream>

#include"DynamicArray.h"
using namespace std;

void UseArray(DynamicArray& arr);

int main()
{
	//크기가 10인 배열 객체를 만든다
	DynamicArray arr(10);

	UseArray(arr);
	
}

void UseArray(DynamicArray& arr)
{
	try 
	{
		arr.SetAt(5, 100);
		arr.SetAt(8, 100);
		arr.SetAt(10, 100);
	}
	catch(const char* ex)
	{
		cout << "예외 종류 : " << ex << endl;
	}
}