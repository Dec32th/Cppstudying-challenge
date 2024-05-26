#pragma once
#include<iostream>
#include"ItemType.h"
using namespace std;

template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

template<class ItemType>
class SortedType
{
public:
	SortedType();
	~SortedType();
	void MakeEmpty();
	void Add(ItemType item);
	int GetLength() const;
	int Get(ItemType& item);
	void ResetList();
	void GetNextItem(ItemType& item);
	bool operator>(ItemType& item) const;
	bool operator<(ItemType& item) const;
	bool operator!=(ItemType& item) const;
	bool operator==(ItemType& item) const;

private:
	NodeType<ItemType>* pFirst;	//첫 번째 노드를 가리킴
	NodeType<ItemType>* pCurrent;		//현재 가리키는 위치
	int s_Length;						//노드 수
};

