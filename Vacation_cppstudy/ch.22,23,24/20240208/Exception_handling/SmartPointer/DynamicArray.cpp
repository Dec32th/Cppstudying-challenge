#include"DynamicArray.h"
#include"MyException.h"
#include<iostream>
using namespace std;

DynamicArray::DynamicArray(int arraySize)
{
	try
	{
		//동적으로 메모리를 할당
		arr = new int[arraySize];

		//배열의 길이 보관
		size = arraySize;

		//여기서 고의로 예외를 발생시킨다.
		throw MemoryException(this, 0);
	}
	catch (...)
	{
		cout << "여기는 실행된다." << endl;

		delete[] arr;

		throw;
	}
}

DynamicArray::~DynamicArray()
{
	try
	{
		//메모리를 해제
		delete[] arr;
		arr = 0;
	}
	catch (...)
	{
	}

}

//원소의 값을 바꾼다
void DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize())
		throw OutOfRangeException(this, index);
	arr[index] = value;
}

//원소의 값을 반환
int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
		throw OutOfRangeException(this, index);

	return arr[index];
}

//배열의 길이 반환
int DynamicArray::GetSize() const
{
	return size;
}