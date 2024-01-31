#include<iostream>
#include<cmath>

using namespace std;


class Point
{
public:
	//멤버 변수
	int x, y;
	//멤버 함수
	void Print();

	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
};

//생성자 외부에 생성
Point::Point()
{
	x = 0;
	y = 0;
}


Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

Point::Point(const Point& pt)
{
	cout << "복사 생성자 호출" << endl;
	x = pt.x;
	y = pt.y;
}

void Point::Print()
{
	cout << "( " << x << ",  " << y << " )" << endl;
}


int main()
{
	//객체를 생성한다.
	Point pt1(100, 100), pt2(200,200);


	//객체를 초기화 할 때만 복사생성자가 호출된다. (그 외 생성자는 호출되지 않는다.)
	Point pt3 = pt1;

	//pt의 내용을 출력
	pt3.Print();

	//새로 대입할 때는 출력되지 않는다.
	pt3 = pt2;
	
	pt3.Print();


}