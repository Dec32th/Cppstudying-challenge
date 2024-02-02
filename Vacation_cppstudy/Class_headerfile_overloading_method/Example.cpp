#include"Point.h"

//void XX()형태의 함수에 대한 포인터
typedef void (*FP1)(int);

//void Point::XX() 형태의 함수에 대한 포인터
typedef void (Point::* FP2)(int);
int main()
{
	//객체를 생성한다.
	Point pt(50, 50);
	Point delta(100, 100);

	//점을 x축으로 10, y축으로 -10만큼 이동시킨다.
	pt.Offset(10, -10);

	//현재 점의 뮈치 출력 (60,40)
	pt.Print();

	//점을 범위 밖으로 이동시킨다 (100.100) -> 접근자를 이용해서 범위를 조절하기 때문이다.
	pt.Offset(delta);

	//pt의 내용을 출력한다.
	pt.Print();

}