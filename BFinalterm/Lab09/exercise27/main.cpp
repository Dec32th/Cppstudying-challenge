#include<iostream>
#include"TreeType.h"
using namespace std;

int main()
{
    TreeType tree;

    // 트리 구성 (문자형 노드)
    tree.InsertItem('F');
    tree.InsertItem('B');
    tree.InsertItem('G');
    tree.InsertItem('A');
    tree.InsertItem('D');
    tree.InsertItem('C');
    tree.InsertItem('E');
    tree.InsertItem('I');
    tree.InsertItem('H');

    // Ancestors 함수 테스트
    ItemType value = 'E';
    cout << "Ancestors of " << value << ": ";
    tree.Ancestors_re(value);
}