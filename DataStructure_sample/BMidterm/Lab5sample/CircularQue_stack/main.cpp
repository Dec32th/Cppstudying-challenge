#include "CircularQue.h"
#include <iostream>

using namespace std;

int main()
{
	CircularQue<int> cq;
	for (int i = 0; i < 10; i++)
		cq.EnQue(i);

	int tmp = INT_MAX;

	CircularQue<int> cq2 = cq, cq3;

	cout << "que1 " << endl;
	while (cq.DeQue(tmp))
		cout << tmp << " ";
	cout << endl;

	//for (int i = 10; i < 12; i++) //문제 2  test code
	//	cq2.EnQue(i);

	//cq3 = cq2;
	cout << "que2 " << endl;
	while (cq2.DeQue(tmp))
		cout << tmp << " ";
	cout << endl;

	cq.EnQue(5);
	cq3 = cq;
	
	//cq3.DeQue(tmp);	//문제 2 test code
	//cout << tmp << " ";
	//cq3.DeQue(tmp);
	//cout << tmp << " ";
	//cq3.DeQue(tmp);
	//cout << tmp << endl;

	//cq3.EnQue(20);
	//cq3.EnQue(21);
	cout << "que3 " << endl;
	while (cq3.DeQue(tmp))
		cout << tmp << " ";
	cout << endl;

	return 0;
}