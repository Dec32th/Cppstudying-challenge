//Dynamic cast example
//동적 할당 동작 과정 연습

#include<iostream>
#include<string>

using namespace std;

class B
{
public:
	int b;
	B(): b(10) {}
	virtual ~B() {} //Dynamic cast를 사용하기 위해 필요한 가상함수
};

class D :public B
{
public:
	int d;
	D():d(20) {}
	~D() override {} //override
};

int main()
{
	B* p1 = new B;
	D* p2 = dynamic_cast<D*>(p1) ; 
	
	//Dynamic cast를 이용해서 B p1이 D를 가리키도록 하지만,d가 없기 때문에 실패하여 nullptr저장. 
	if (p2)
	{
		cout << "1: " << p2->d << endl;
	}
	//출력 결과 없음.

	D* p3 = new D;
	B* p4 = dynamic_cast<B*>(p3);

	//Dynamic cast를 이용해서 D p3가 B p4를 가리키도록. D는 B의 값이 있기 때문에 가능. 
	if (p4)
	{
		cout << "2: " << p4->b << endl;
	}
	//2: 10 출력

	B* p5 = new D;
	D* p6 = dynamic_cast<D*>(p5);

	//B p5에 D 할당. p5는 B type의 pointer(이름은 B type pointer이지만 실제로 가리키는 대상이 D) p5를 dynamic cast시 성공.
	if (p6)
	{
		cout << "3: " << p6->d << endl;
	}
	//3: 20 출력
}