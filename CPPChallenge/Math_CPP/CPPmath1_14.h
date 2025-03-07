#pragma once
#include<iostream>
#include<cmath>
#include<numeric>
#include<vector>
#include<string>
#include<utility>
#include<cstdlib>
#include<ctime>
using namespace std;

// #1 3이나 5로 나누어 떨어지는 자연수의 합을 계산하는 프로그램
int mul_35(int iNum)
{
	int iTotal = 0;
	for (int i = iNum; i >= 2; i--)
	{
		if (i % 15 == 0)
		{
			iTotal -= i;
		}
		if (i % 3 == 0 || i % 5 == 0)
		{
			iTotal += i;
		}
	}
	return iTotal;
}

// #2 최대 공약수 프로그램 구현하기 - 두 수의 최대 공약수 구현
int gcd_number(int iNum1, int iNum2)
{
	int gcdNum = 0;
	while (iNum1 % iNum2 != 0)
	{
		iNum1 = iNum1 > iNum2 ? iNum2 : iNum1;
		iNum2 = iNum1 % iNum2;
		gcdNum = iNum1;
	}
	return gcdNum;
}

// #3 최소공배수 프로그램 구현 - 입력을 벡터로 받기???여러개 받아야함.
template<class T>
int lcm_number(T first, T last)
{
	return accumulate(first, last, 1, lcm_number);
}


// 소수인지를 체크하는 함수 
bool is_PrimeN(int iNum)
{
	if (iNum <= 1)
		return false;
	if (iNum <= 3)
		return true;
	if (iNum % 2 == 0 || iNum % 3 == 0)
		return false;
	for (int i = 5; i * i < iNum; i += 6)
	{
		if (iNum % i == 0 || iNum % (i + 2) == 0)
			return false;
		return true;

	}
}
// #4 주어진 수보다 작지만 가장 큰 소수를 계산하는 프로그램 구현
int Large_Prime(int iNum1)
{
	for (int i = iNum1 - 1; i > 0; i--)
	{
		if (is_PrimeN(i))
			return i;
		else
			continue;
	}
}

// #5 섹시소수 짝을 출력하는 프로그램 - 서로 6차이나는 소수의 쌍을 섹시소수라고 한다.
void sexy_prime(int iNum)
{
	for (int i = 5; i < iNum; i++)
	{
		if (is_PrimeN(i) && is_PrimeN(i + 6))
		{
			cout << "( " << i << ", " << " )" << endl;
		}
	}
}

// #6 과잉수 출력 프로그램 구현하기
// 과잉수 출력 프로그램
void ab_Number(unsigned int iNum)
{
	unsigned int sum1 = 1;
	for (int i = iNum; i >= 12; i--)
	{
		for (int j = 2; j < i; j++)
		{
			sum1 = (i % j == 0) ? sum1 + j : sum1;
		}
		if (sum1 > i)
			cout << "The number is " << i << " sum1 = " << sum1 << ", abundance = " << sum1 - i << endl;
		sum1 = 1;

	}

}

// 진약수를 계산해주는 프로그램
// 합을 계산해서 return 해줌. 
int mul_Num(int iNum)
{
	unsigned int sum1 = 1;
	for (int i = iNum; i >= 12; i--)
	{
		for (int j = 2; j < i; j++)
		{
			sum1 = (i % j == 0) ? sum1 + j : sum1;
		}

	}
	return sum1;
}

// #7 친화수 짝을 출력하는 프로그램 구현하기 

//#6에서 구했던 과잉수 프로그램을 이용해서 진약수의 합을 구하고 구한 그 진약수의 합의 약수들의 합을 구해서 비교. 
void Friend_Number()
{
	//원래 수를 저장 
	int iNum_1 = 0;

	//진약수의 합을 저장함. 
	int sum2 = 0;

	for (int i = 220; i <= 1000000; i++)
	{
		if (mul_Num(i) > i)
		{
			iNum_1 = i;
			sum2 = mul_Num(i);

			if (iNum_1 == mul_Num(sum2))
				cout << "( 과잉수 : " << i << ", 부족수 : " << sum2 << " )" << endl;
		}

	}

}

//#8 암스트롱 수 구하기 - 세자릿수의 각 자리 수의 세제곱의 합이 그 수와 같음. 
void Amstrong_num()
{
	for (int i = 100; i < 1000; i++)
	{
		//순서대로 1의자리 10의자리 100의 자리
		int iNum1 = i % 10;
		int iNum10 = (i % 100) / 10;
		int iNum100 = i / 100;
		int iCount = 1;

		if (pow(iNum1, 3) + pow(iNum10, 3) + pow(iNum100, 3) == i)
		{
			cout << "Amstrong number " << iCount << " is " << i << endl;
			iCount++;
		}

	}
}

// #9 소인수분해 프로그램 구현
void prime_factcal(int iNum)
{
	// 소인수는 소수의 곱셈으로 표현이 되어야함.  
	// 일단 소수로 곱셈을 나타내야함.

	vector<int> v1;

	if (is_PrimeN(iNum))
	{
		cout << iNum << " is prime number." << endl;
	}
	else
	{
		for (int i = 2; i < iNum; i++)
		{
			if (is_PrimeN(i))
			{
				while (iNum % i == 0)
				{
					v1.push_back(i);
					iNum /= i;
				}
				
			}
		}
		
	}
	// 소인수를 출력
	cout << "Prime factors : ";
	for (int factor : v1)
	{
		cout << factor << " ";
	}
	cout << endl;

}

// #10 그레이 코드 출력 프로그램

//Xor gate + shift연산을 이용하여 gray code 구현가능

int gray_code(int iNum)
{
	return iNum ^ (iNum >> 1);
}

// #11 로마 숫자 표기법 변환 프로그램 - 3999까지만 표기 가능하므로 그 범위 이내의 숫자를 입력

string Rome_numbeer(int iNum)
{
	vector<pair<int, string>> roman;
	if (iNum > 3999)
		return "This is too big.";

	roman = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
		{50, "L"}, {40, "XL"}, {10 , "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1 , "I"}
		};

	string result = "";
	for (auto& [value, symbol] : roman)
	{
		while (iNum >= value)
		{
			result += symbol;
			iNum -= value;
		}
	}
	return result;
}

// #12 가장 긴 콜라츠 수열 출력 프로그램 - 백만 이하의 양의 정수에 대해 콜라츠 수열을 구하고 가장 긴 길이 / 첫째항을 산출 

// #12-1 콜라즈 수열의 길이를 측정하는 함수 
int collaz_seq(int iNum)
{
	int iLength = 1;
	while (iNum != 1)
	{
		if (iNum % 2 == 0)
		{
			iNum = iNum / 2;
		}
		else
			iNum = 3 * iNum + 1;
		iLength++;
	}
	return iLength;
}

// #12-2 콜라즈 수열이 가장 긴지 체크하여 pair로 return하는 함수
pair<int, int> large_collaz(int iNum)
{
	int iLen = collaz_seq(iNum);
	int iResult = iNum;

	for (int i = iNum-1; i >1 ; i--)
	{
		if (iLen < collaz_seq(i))
		{
			iLen = collaz_seq(i);
			iResult = i;
		}
	}
	return { iResult, iLen };
}

// #13 파이 값 계산 프로그램

// #13-1 - 몬테카를로 방법
double cal_pi(int num_points)
{
	int inside_circle = 0;

	for (int i = 0; i < num_points; ++i)
	{
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;
	
		if (x * x + y * y <= 1)
		{
			inside_circle++;
		}
	}
	return 4 * inside_circle / num_points;
}

// #13-2 리만합 방법

double cal_Pi_ri(int iNum)
{
	double pi = 0.0;
	for (int i = 0; i < iNum; i++)
	{
		pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
	}
	return 4.0 * pi;
}
// #14 ISBN 검증 프로그램 구현 - 10자리의 isbn값, 마지막 값은 10자리 수 모두에 10부터 1까지의 가중치를 곱해서 11의 배수가 되도록 10번째 숫자 check
// 이때, 입력값은 string -> int로 변환하고 제대로 되었는지 검증

bool chek_isbn(string str1)
{
	vector<string> cNum;
	int iChecker = 0;
	for (int i = 0; i < 10; i++)
	{
		cNum.push_back(str1.substr(i, 1));
	}

	for(int j = 0; j < 10; j++)
	{
		iChecker += stoi(cNum[j]) * (10 - j);
	}

	if (iChecker % 11 == 0)
		return true;
	return false;
}
