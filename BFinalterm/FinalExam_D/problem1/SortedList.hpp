#pragma once
#include<iostream>
using namespace std;

const int max_items = 100;

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template<class ItemType>
class SortedList {
private:
    ItemType arr[max_items];
    int size;
    int capacity = max_items;

public:
    SortedList();
    ~SortedList() {};
    void InsertItem(ItemType items);
    bool FindItem(ItemType items);
    void Print();
};

template<class ItemType>
SortedList<ItemType>::SortedList()
{
    size = 0;
}

template<class ItemType>
bool SortedList<ItemType>::FindItem(ItemType items)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == items)
        {
            return true;
        }
    }
    return false;

}


template<class ItemType>
void SortedList<ItemType>::InsertItem(ItemType items)
{
    
    if (size == 0)
    {
        arr[size] = items;
        size++;
    }
    else if (size == capacity)
    {
        cout << "This set is full." << endl;
    }
    else if (FindItem(items))
    {
        cout << "This value is already in this set" << endl;
    }
    else if (!FindItem(items) && size < capacity && arr[size-1] < items)//맨 뒤에 들어가는 경우
    {
        arr[size] = items;
        size++;
    }
    else if (size < capacity && !FindItem(items))   //중간에 들어가는 경우
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (arr[i] > items)
            {
                
                for (int j = size; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }
                break;
            }
        }
        arr[i] = items;
        size++;
    }


}

template<class ItemType>
void SortedList<ItemType>::Print()
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;

}