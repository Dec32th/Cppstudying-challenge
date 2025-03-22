#include"DoublySortedLinkedList.h"

template<typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	m_pFirst = NULL;
	m_pLast = NULL;
	m_nLength = 0;
}

template<typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
	MakeEmpty();
}

template<typename T>
bool DoublySortedLinkedList<T>::IsEmpty()
{
	return m_nLength == 0;
}

template<typename T>
bool DoublySortedLinkedList<T>::IsFull()
{
	TempPtr = new DoublyNodeType<ItemType>;
	return (TempPtr == NULL);
}

template<typename T>
void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* pItem;
	DoublyIterator<T>* itor(*this);	//자기자신의 값을 받는거?

	while (itor.NotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next();
	}
	m_pFirst = m_pLast = NULL;
}

template<typename T>
int DoublySortedLinkedList<T>::GetLength() const
{
	return m_nLength;
}

template<typename T>
int DoublySortedLinkedList<T>::Add(T item)
{
	DoublyNodeType<T>* newNode;
	DoublyIterator<ItemType> itor;
	bool found = false;

	newNode = new DoublyNodeType<T>;
	newNode->data = item;
	
	loc = tempPtr = m_pFirst;


	if (m_pFirst != NULL && !found)
	{
		if (itor.NotNull() && item > itor.GetCurrentNode().data)
		{
			newNode->prev = loc->prev;
			newNode->next = loc;
			loc->prev->next = newNode;
			loc->prev = newNode;
			return 1;
		}
		else
		{
			tempPtr = loc;
			loc = loc->next;
		}
		m_nLength++;
	}

	return 0;
}

template<typename T>
void DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<ItemType> itor;
	
}