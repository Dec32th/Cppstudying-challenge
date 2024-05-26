#pragma once
#include<iostream>

template<typename T>
struct NodeType
{
	T info;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

template <typename T>
class UnsortedType
{
public:
	/**
	*	default constructor.
	*/
	UnsortedType();

	/**
	*	destructor.
	*/
	~UnsortedType();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);
	void UnsortedType<ItemType>::PrintSumSquares();

private:
	NodeType<T>* listPtr;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};

// Class constructor
template <typename T>
UnsortedType<T>::UnsortedType()
{
	m_nLength = 0;
	listPtr = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
UnsortedType<T>::~UnsortedType()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void UnsortedType<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (listPtr != NULL)
	{
		tempPtr = listPtr;
		listPtr = listPtr->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int UnsortedType<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int UnsortedType<T>::Add(T item)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		listPtr = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int UnsortedType<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = listPtr;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void UnsortedType<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void UnsortedType<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}


//재귀함수 작성 필요. 값을 제곱해서 더한다.
//리스트가 비어있지 않다고 가정한다.
//비어있는 리스트가 들어오더라도 문제가 없이 작동할 수 있어야한다.
template <class ItemType>
ItemType SumSquares(NodeType<ItemType>* list)
{
	ItemType iTotal;
	if (list == NULL)
		return 0;
	else if ((list->next) == NULL)
		return iTotal = (list->info) * (list->info);
	else
		return iTotal += SumSquares(list->next);
}



