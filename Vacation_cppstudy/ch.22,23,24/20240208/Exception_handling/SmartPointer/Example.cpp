#include<iostream>
#include"DynamicArray.h"
#include"MyException.h"
#include<memory>
using namespace std;


void A();
void B();

int main()
{
	try
	{
		//DynamicArray의 생성자에서 예외 발생
		DynamicArray arr(100);
	}
	catch (MyException& ex)
	{
		cout << "예외 설명 : " << ex.description << endl;
	}
}

void A()
{

	auto_ptr<char> ptr(new char[100]);

	cout << "예외가 발생하기 전" << endl;

	//예외를 던지는 함수 호출
	B();

}

void B()
{
	throw "Exception!!";
}