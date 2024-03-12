#include<iostream>
using namespace std;

//morden C++ challenge source code coding - function fowm 
// 2024/03/12 - #1-5

//#1
//입력받은 수까지의 숫자까지 3과 5의 약수를 모두 더하는 함수
int Sum3and5(int iNum)
{
	int iSum = 0;
	int iCount = 0;

	if (iNum <= 0)
	{
		cout << "There is wrong input. please enter the right number.";
	}

	else
	{
		while (iCount <= iNum)
		{
			if (iCount % 3 == 0 || iCount % 5 == 0)
			{
				iSum += iCount;
				iCount++;
			}
		}
		return iSum;
	}
}


//#2
//최대공약수 구하는 함수
int iGcd(int iNum1, int iNum2)
{
	
}

int main()
{

}