#include<iostream>
using namespace std;

int DivZero(int a, int b, int c)
{
	int testing = 0;
	if (a < 0 &&b<0 &&c<0)
	{
		testing = 1;
		throw testing;
	}
	else if (a == 0 && b == 0 && c == 00)
	{
		testing = 2;
		throw testing;
	}
	
	return a + b * c + b / c;
}


int main()
{
	try
	{
		cout << DivZero(-4, -1, -1) << endl;
	}
	catch(int ex) //여기의 변수 명은 마음대로 해도 상관없다. 어차피 throw로 가지고 온 것을 받아서 처리하기 때문.
	{
		if (ex == 1)
			cout << "모든 수는 0보다 작을 수 없습니다." << endl;

		else if (ex == 2)
			cout << "모든 수는 0이 될 수 없습니다." << endl;

		else
			cout << "ERROR!";
	}

}