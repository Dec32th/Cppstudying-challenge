#include <cmath>
#include<iostream>
using namespace std;

//main 함수 작성.  메인에서 함수들을 호출. 
//(SqrRoot를 클래스로 만들어서 사용하셔도 됩니다.)

//재귀 버전. 문제에 적힌 내용을 적으시면 됩니다.
float SqrRoot_recursion(float number, float approx, float tol)
{
	if (fabs(approx * approx - number) <= tol)
		return approx;
	else
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
}


//비재귀 버전. 재귀 버전에서 반복적으로 계산하는 부분을 조건에 맞춰 돌리면 됩니다.
float SqrRoot_non_recursion(float number, float approx, float tol)
{
	while (fabs(approx * approx - number) > tol)
	{
		approx = (approx * approx + number) / (2 * approx);
	}
	return approx;
}

int main()
{
	cout << "재귀 함수 이용 : " << SqrRoot_recursion(2, 1, 0.1);
	cout << "비재귀 함수 이용 : " << SqrRoot_non_recursion(2, 1, 0.1);
}
