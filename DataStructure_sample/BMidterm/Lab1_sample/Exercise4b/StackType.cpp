// File: StackType.cpp

#include "StackType.h"
#include <iostream>
StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

void StackType::ReplaceItem(int oldItem, int newItem)
{
    StackType tStack;
    if (this->IsEmpty())
        throw EmptyStack();
    else
    {
        while (!this->IsEmpty())
        {
            if (this->Top() == oldItem)
            {
                tStack.Push(newItem);
                this->Pop();
            }
            else
            {
                tStack.Push(this->Top());
                this->Pop();
            }
        }
    }

    while (!tStack.IsEmpty())
    {
        this->Push(tStack.Top());
        tStack.Pop();
    }

}

