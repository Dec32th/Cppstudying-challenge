#include"sorted.h"

SortedType<ItemType>::SortedType()
{
	pFirst = NULL;
	pCurrent = NULL;
	s_Length = 0;
}

SortedType<ItemType>::~SortedType()
{
	MakeEmpty();
}

template<>
void SortedType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;
	while (pFirst != NULL)
	{
		tempPtr = pFirst;
		pFirst = pFirst->next;
		delete tempPtr;
	}
	s_Length = 0;
}

int SortedType<ItemType>::GetLength() const
{
	return s_Length;
}

int SortedType<ItemType>::Get(ItemType& item)
{
	NodeType<ItemType>* loc;
	bool bChecker = false;
	loc = pFirst;
	while (bChecker !=true)
	{
		if (item == loc->data)
		{
			bChecker = true;
			item = loc->data;
		}
		else if (loc != NULL)
		{
			loc = loc->next;
		}
		else
			break;
	}
	if (bChecker)
		return 1;
	else
		return 0;
}

void SortedType<ItemType>::Add(ItemType item)
{
	NodeType<ItemType>* loc;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* tempPtr;
	tempPtr = new NodeType<ItemType>;
	tempPtr->data = item;

	//빈 linked list일 경우 값을 처음에 추가해주면 된다.
	if (pFirst ==NULL)
	{
		pFirst = tempPtr;
		tempPtr->next = NULL;
		s_Length++;
	}

	//비어있지 않은 경우 - 검사를 통해서 순서대로 값을 넣어야한다.
	else
	{
		loc = predLoc = pFirst;
		while (loc != NULL)
		{
			if (item < loc->data)
				break;
			else if (item > loc->data)
			{
				predLoc = loc;
				loc = loc->next;
			}
		}
		//노드가 비어있진 않으나, 제일 앞에 넣어야하는 경우
		if (predLoc == loc)
		{
			tempPtr->next = pFirst;
			pFirst = tempPtr;
		}
		//맨 마지막에 넣어야하는 경우
		else if (predLoc->next==NULL)
		{
			predLoc->next = tempPtr;
			tempPtr->next = NULL;
		}
		//그외 - 일반적으로 사이에 넣어야하는 경우
		else
		{
			predLoc->next = tempPtr;
			tempPtr->next = loc;
		}
		s_Length++;
	}
}

void SortedType<ItemType>::ResetList()
{
	pCurrent = NULL;
}

//여기의 item으로 받아서 출력하는 듯
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
	if (pCurrent == NULL)
	{
		pCurrent = pFirst;
	}
	else
	{
		pCurrent = pCurrent->next;
	}
	item = pCurrent->data;
}

bool SortedType<ItemType>::operator>(ItemType& item) const
{
	return this->pCurrent->data > item;
}

bool SortedType<ItemType>::operator<(ItemType& item) const
{
	return this->pCurrent->data < item;
}

bool SortedType<ItemType>::operator==(ItemType& item) const
{
	return this->pCurrent->data == item;
}

bool SortedType<ItemType>::operator!=(ItemType& item) const
{
	return this->pCurrent->data != item;
}