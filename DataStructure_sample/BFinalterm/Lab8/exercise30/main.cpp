#include<iostream>
#include"TreeType.h"
using namespace std;

int main()
{
    TreeType tree;

    // 트리 초기화
    tree.InsertItem(10);
    tree.InsertItem(5);
    tree.InsertItem(15);
    tree.InsertItem(3);
    tree.InsertItem(7);
    tree.InsertItem(12);
    tree.InsertItem(17);
    tree.InsertItem(1);
    tree.InsertItem(4);

    cout << tree.LeafCount();
}