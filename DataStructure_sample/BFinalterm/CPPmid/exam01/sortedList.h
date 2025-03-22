#pragma once

//동적할당한 아이템을 pointer가 가리키게? 
// 새로 노드를 만들어서 이 아이템을 그 node의 pointer가 가리키게 하라는거?



template<typename T>
class sortedList
{
public:
	sortedList(int pArrSize);
	~sortedList();
	void InsertItem(T Item);
	void deleteItem(T item);
	bool IsEmpty();
	bool IsFull();

private:
	T *pArr[];
	int arrSize;
	int maxArr;
};

template<typename T>
sortedList<T>::sortedList(int pArrSize)
{
	arrSize = 0;
	maxArr = pArrSize;
	pArr[] = new * T[pArrSize];
	pCurrnet = pArr[0];
}

template<typename T>
sortedList<T>::~sortedList()
{
	delete pArr[];
}

template<typename T>
void sortedList<T>::InsertItem(T item)
{
	int loc = 0;
	while (loc < maxArr)
	{
		if (item < *pArr[loc])
		{
			break;
		}
		else
		{
			loc++;
		}
	}
	for (int i = maxArr; i > loc; i--)
	{
		pArr[i] = pArr[i - 1];

	}
	pArr[loc] = &item;
	arrSize++;
}

template<typename T>
void sortedList<T>::deleteItem(T item)
{
	int loc = 0;
	while (*pArr[loc] != item)
	{
		loc++;
	}
	for (int i = loc + 1; i < maxArr; i++)
	{
		pArr[i - 1] = pArr[i];
	}
	arrSize--;
}

template<typename T>
bool sortedList<T>::IsFull()
{
	return arrSize == maxArr;
}

template<typename T>
bool sortedList<T>::IsEmpty()
{
	return arrSize == 0;
}