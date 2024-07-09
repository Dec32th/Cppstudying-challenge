#include<iostream>
//#include"StackType.hpp"
//#include"doubleStack.h"
#include"iStackType.h"
using namespace std;

//template<class ItemType>
//Stack<ItemType> CopyStack(Stack<ItemType>& stack1)
//{
//    Stack<ItemType> tempStack;
//    Stack<ItemType> resStack;
//
//    for (int i = 1; i <= MAX_ITEMS; i++)
//    {
//        tempStack.Push(stack1.Top());
//        stack1.Pop();
//    }
//
//    for (int i = 1; i <= MAX_ITEMS; i++)
//    {
//        resStack.Push(tempStack.Top());
//        tempStack.Pop();
//    }
//    return resStack;
//}

void ReplaceItem(iStackType& st, int oldItem, int newItem)
{
    iStackType temp;

    while (!st.isEmpty())
    {
        temp.push(st.Top());
        st.pop();
    }
    while (!temp.isEmpty())
    {
        if (temp.Top() == oldItem)
        {
            st.push(newItem);
            temp.pop();
        }
        else
        {
            st.push(temp.Top());
            temp.pop();
        }
    }
}

int main()
{
	/*Stack<int> stack;
	Stack<int> stack2;

    stack.Push(9);
    stack.Push(8);
    stack.Push(4);
    stack.Push(7);
    stack.Push(5);
    stack.Push(3);

    stack2 = CopyStack(stack);

    while (!stack2.IsEmpty())
    {
        cout << stack2.Top() << endl;
        stack2.Pop();
    }*/


   /* cout << "# double stack" << endl;
    DoubleStackType dStack;

    dStack.push(1);
    dStack.push(2);
    dStack.push(3);
    dStack.push(4);
    dStack.push(1000);
    dStack.push(1001);
    dStack.push(1002);
    dStack.push(1003);
    
    dStack.Print();*/
	
    cout << "#4 replaceItem" << endl;
    iStackType iStack1;

    iStack1.push(8);
    iStack1.push(3);
    iStack1.push(9);
    iStack1.push(8);
    iStack1.push(3);
    iStack1.push(7);
    iStack1.push(5);
    iStack1.push(3);

    ReplaceItem(iStack1, 3, 5);

    iStack1.Print();
}