#include<iostream>
#include<cmath>
using namespace std;

// #1
//입력 받은 수를 상한으로 하는 수 중에서 3,5로 나누어 떨어지는 수의 합을 구하는 계산기 작성하기
unsigned int cal35total(int maximum_number)
{
	unsigned int result = 0;
	for (int i = 1; i <= maximum_number; i++)
	{
		if (i % 3 == 0 && i % 15 != 0)
		{
			result += i;
		}
		else if (i % 5 == 0 && i % 15 != 0)
		{
			result += i;
		}
	}
	return result;
}

// #2-1
// 최대 공약수 프로그램 구현하기(내부에서 큰 수 작은 수 판단하기 + 같은 수는 들어오지 않는다고 가정)
// 재귀없는 버젼
unsigned int cal_gcd(unsigned int iNum1, unsigned int iNum2)
{
	unsigned int result = 0;
	unsigned int a = 0;
	unsigned int b = 0;
	if (iNum1 > iNum2)
	{
		unsigned int a = iNum1;
		unsigned int b = iNum2;
	}
	else
	{
		unsigned int a = iNum2;
		unsigned int b = iNum1;
	}
	
	while (a % b != 0)
	{
		result = a % b;
		a = b;
		b = result;
		
	}
	
	return result;
}
// #2-2 재귀로 쓴 버젼

unsigned int cal_gcd_r(unsigned int iNum1, unsigned int iNum2)
{
	return iNum2 == 0 ? iNum1 : cal_gcd_r(iNum2, iNum1 % iNum2);
}

// #3 최소 공배수 구하는 프로그램
unsigned int cal_lcm(int iCalnum)
{

}

// #4 
// 주어진 수보다 작은 가장 큰 소수를 계산하는 프로그램

//#4-1 먼저 bool로 소수인지 아닌지 판단하는 함수
bool is_Prime(unsigned int iNum)
{
	if (iNum <= 1)
		return false;
	if (iNum <= 3)
		return true;
	if (iNum % 2 == 0 || iNum%3 ==0)
		return false;
	for (unsigned int i = 5; i * i <= iNum; i += 6)
	{
				if (iNum % i == 0)
					return false;
	}
	return true;
}

//#4-2. 위의 함수를 이용해서 계산.
unsigned int prime_cal(unsigned int iNum)
{
	//2보다 작은 소수는 존재하지 않음
	if (iNum <= 2)
		return 0;
	for (int i = iNum - 1; i >= 2; i--)
		{
			if (is_Prime(i))
				return i;
		}
	
}

// #5 섹시소수 출력 프로그램 - 두 수의 차가 6인 소수를 출력
// #4에서 사용한 소수 체크 프로그램 사용
void sexy_Prime(unsigned iNum)
{
	//소수인지 판단하고 6차이 나는 소수들을 출력.
	// 4-1 에서 만든 함수들 사용
	for (int i = 2; i <= iNum; i++)
	{
		if (is_Prime(i)&& is_Prime(i+6))
		{
			cout << "( " << i << ", " << i+6 << " )";
		}
	}
}

//#6 과잉수 출력 프로그램 - 자기 자신을 뺀 약수들의 합이 자신보다 큰 수, 과잉은 그 더한값-그 수
