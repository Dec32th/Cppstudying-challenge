#include<iostream>
#include"Rect.h"
using namespace std;

int main()
{
	//Rect 객체 생성
	Rect rcl;

	//내용 출력
	rcl.Print();

	//값을 바꿔본다
	rcl.SetRect(10, 20, 30, 40);

	//내용 출력
	rcl.Print();

	//값을 바꾼다
	rcl.SetTopLeft(Point(20, 20));

	//내용 출력
	rcl.Print();

	//넓이, 높이 출력
	cout << "rcl.Getwidth() = " << rcl.GetWidth() << endl;
	cout << "rcl.GetHeight() = " << rcl.GetHeight() << endl;

}