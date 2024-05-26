#include<iostream>
#include"TreeType.h"
using namespace std;

int main()
{
	TreeType tree;
    tree.InsertItem(10);
    tree.InsertItem(5);
    tree.InsertItem(15);
    tree.InsertItem(3);
    tree.InsertItem(4);
    tree.InsertItem(20);

	cout << tree.SingleParentCount() << endl;
}