#include<iostream>
#include<new>
using namespace std;

int main()
{
	try
	{
		//많은 양의 메모리를 할당
		char* p = new char[0xfffffff0];
	}
	catch (bad_alloc& ex)
	{
		//실제로 bad allocation이라는 값이 출력이 되지 않음. 왜지...... -> 아마도 메모리가 부족하지 않은듯!!! 
		//어떻게 해야 부족할지 모르겠다.
		cout << ex.what() << endl;
		cout << "여기 출력되나요?";
	}
}