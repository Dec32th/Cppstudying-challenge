#include<iostream>
using namespace std;

//morden C++ challenge source code coding - function fowm 
// 2024/03/12 - #1-5

//#1
//입력받은 수까지의 숫자까지 3과 5의 약수를 모두 더하는 함수
//Moden C++ challenge 책 문제들 코딩

//Using namespace std; 와 메인 함수의 내용은 모두 생략.
//1 - 5까지 함수로 만들고 그 함수의 내용을 코딩함.

//#1	3이나 5로 나누어 떨어지는 수 구하기
int Sum3or5(int iNum)
{
	int iSum = 0;
	for (int i = 1; i <= iNum; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			iSum += i;
		}
	}
	return iSum;
}


//#2	최대공약수 구하기 - recursive function 이용
int iGcd(int iNum1, int iNum2)
{
	int iMax = iNum1 > iNum2 ? iNum1:iNum2;
	int iMin = iNum1 > iNum2 ? iNum2:iNum1;


	if (iNum1 <= 0 || iNum2 <= 0)
	{
		cout << "there is wrong number.Please enter the right number.";
	}
	else
	{
		iMax = iNum1 > iNum2 ? iNum1 : iNum2;
		iMin = iNum1 > iNum2 ? iNum2 : iNum2;

		if (iMax % iMin == 0)
		{
			return iMin;
		}

		else
		{
			iGcd(iMin, iMax % iMin);
		}
	}
}

//#3 최소공배수 구하기
int iLcm(int iNum)
{
	int iCount;
	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{

	}
}

int main()
{

}