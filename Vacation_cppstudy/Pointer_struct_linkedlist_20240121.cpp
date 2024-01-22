// 구조체를 가리키는 포인터


#include<iostream>
using namespace std;

struct Point
{
	int x, y;
};

int main() 
{
	Point pt[3] = { {100,100}, {30,50} {80,20}};
	Point* p[5] = { &pt[0], &pt[1], &pt[2], &pt[0], &pt[0], &pt[1]};

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << " and " << *p[i] << endl;
	}
}