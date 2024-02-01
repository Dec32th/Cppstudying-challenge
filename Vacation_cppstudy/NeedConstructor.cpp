#include<iostream>

using namespace std;

class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);
};

NeedConstructor::NeedConstructor(int count, int& number)
	:maxCount(count), ref(number) // const값과 reference가 있는 경우에는 멤버 초기화 리스트가 필요하다. 
{
	sample = 200;
}

NeedConstructor::NeedConstructor()
	:maxCount(100), ref(sample) //이런 형태로 구현할 수 있고, parameter를 이용해서 구현할 수도 있다.
{
	sample = 200;
}

int main()
{
	//참조할 변수 생성
	int number = 400;

	//객체를 생성
	NeedConstructor cr(300, number);

	//내용을 출력
	cout << "cr.maxCount = " << cr.maxCount << endl;
	cout << "cr.ref = " << cr.ref << endl;

}