//생성자를 사용해서 임시객체 만들기

#include<iostream>

using namespace std;

class Point
{
public:
	//memeber variable
	int x, y;

	//member function
	void Print()
	{
		cout << "( " << x << ", " << " )" << endl;
	}

	//constructors
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int initialX, int initialY)
	{
		x = initialX;
		y = initialY;
	}
	Point(const Point& pt)
	{
		x = pt.x;
		y = pt.y;
	}
};


//Point 객체를 인자로 요구하는 함수
void Area(const Point& pt)
{
	//(0,0)과 pt가 이루는 사각형의 면적을 구한다.
	int area = pt.x * pt.y;

	//결과 출력
	cout << "(0, 0)과 이루늰 사각형의 면적 = " << area << endl;
}



int main()
{
	//현재, x와 y의 정수값을 가지고 있다고 가정
	int x = 5;
	int y = 5;


	//함수 호출 -  새로 instance를 만들지 않고 생성자를 이용해서 임시 Point instance를 만들고 그것을 parameter로
	Area(Point(x,y));
	//실행 후, 임시 instance 소멸.

}