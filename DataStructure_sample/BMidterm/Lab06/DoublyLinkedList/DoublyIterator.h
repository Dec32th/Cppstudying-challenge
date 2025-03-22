#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	연결리스트에서 쓰이는 Iterator의 클래스.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	디폴트 생성자.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList와 친구 클래스.


	bool NotNull();
	bool NextNotNull();
	T First();
	T Next();
	DoublyNodeType<T> GetCurrentNode();
private:
	const DoublySortedLinkedList<T>& m_List;
	DoublyNodeType<T>* m_pCurPointer;
};

bool DoublyIterator<ItemType>::NotNull()
{
	return m_pCurPointer != NULL;
}

bool DoublyIterator<ItemType>::NextNotNull()
{
	return m_pCurPointer->next != NULL;
}

ItemType DoublyIterator<ItemType>::First()
{
	return m_List.m_pFirst->data.GetId();
}

ItemType DoublyIterator<ItemType>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data.GetId();
}

DoublyNodeType<ItemType> DoublyIterator<ItemType>::GetCurrentNode()
{
	return *m_pCurPointer;
}


#endif _DOUBLYITERATOR_H