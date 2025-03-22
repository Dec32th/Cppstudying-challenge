#include<iostream>
#include"SortedList.hpp"
using namespace std;

int main()
{
	SortedList<int> sl;

	sl.InsertItem(1);
	sl.InsertItem(5);
	sl.InsertItem(2);
	sl.InsertItem(9);
	sl.InsertItem(1);
	sl.InsertItem(3);

	sl.Print();
}