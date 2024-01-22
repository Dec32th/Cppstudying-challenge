// 구조체를 가리키는 포인터


#include<iostream>
using namespace std;

struct Dizzy
{
	int id; //구조체 변수의 고유값
	Dizzy* p; //Dizzy 구조체를 가리키는 포인터
};

int main()
{
	//Dizzy 객체를 3개 만들고, 서로를 가리키도록 함
	Dizzy a, b, c;
	a.id = 1;
	a.p = &b;
	b.id = 2;
	b.p = &c;
	c.id = 3;
	c.p = &a;

	//a만을 이용해서 a,b,c의 모든 값에 접근한다.
	//링크드 리스트 형태 (ch.19)
	cout << "a.id = " << a.id << endl;
	cout << "b.id = " << a.p->id << endl;
	cout << "c.id = " << a.p->p->id << endl;
	cout << "a.id = " << a.p->p->id << endl;
}