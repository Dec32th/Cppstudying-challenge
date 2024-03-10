/*             Object-Oriented Programming, Midterm exam (2023-1, CSE103-02)                       */
// Write your answers in Korean or English(답안은 한국어 또는 영어로 작성하시오).

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 학과:글로벌커뮤니케이션학부, 학번:2023103381	, 성명: 원혜경        
/////////// 답안 시작
double Fn1(double a1, double a2)
{
	double result;
	result = a1 > a2 ? a1 : a2;
	return result;
}

void Fn2(const double &a1, const double &a2, double &result)
{
	result = a1 * a2;
}

int Fn3(const int& a1, const int& a2)
{
	int result = 0;
	if (a1 <= 0)
	{
		for (int i = 0; i <= a2; ++i)
		{
			result += i;
		}
	}
	else
	{
		for (int i = a1; i <= a2; ++i)
		{
			result += i;
		}
	}

	return result;
}

int Fn4(int a)
{
	int count = 0;
	if (a <= 0)
		return count;
	else
	{
		for (int i = 1; i <= a; ++i)
		{
			if (a % i == 0)
				count++;
			else
				continue;
		}
	}

	return count;
}
void Fn5(std::vector<int>& v1)
{
	
	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] = v1[i] * v1[i];
	}
	
}

void Print(std::vector<int> v0)
{
	for (auto x : v0)
	{
		cout << x <<", ";
	}
}

vector<int> Fn6(const int n)
{
	vector<int> v1;
	int count = 0;
	bool bChecker = true;
	if (n > 10)
	{
		return v1;
	}
	else
	{
		do {
			int temp = rand() % 10;
			v1.push_back(temp);

			for (int i = 0; i <= count; i++)
			{
				if (temp == v1[i])
					break;
				else
				{
					
				}
			}
		} while (count !=n);
	}
	return v1;
}
/////////// 답안 끝



int main() {
	// 전역 변수 사용 금지(Do not use global variables.)
	srand(static_cast<unsigned>(time(0)));

	std::cout << "\n### 1 ###" << std::endl;
	// 1(2). 아래 코드에서 두 인수의 큰 값을 출력하도록 Fn1 함수를 정의하라.(표준함수 사용 금지)
	// (Define the Fn1 function to print the larger value of two arguments in the following codes. - Do not use standard functions.)
	double x1 = 1, x2 = 2, y = 0;
	std::cout << Fn1(x1, x2) << std::endl;		// 출력: 2
	std::cout << Fn1(5.2, 2.1) << std::endl;	// 출력: 5.2

	std::cout << "\n### 2 ###" << std::endl;
	// 2(2). 아래 코드에서 두 인수의 곱을 출력하도록 Fn2 함수를 정의하라.
	// (Define the Fn2 function to print the product of two arguments in the following codes.)
	double product = 0;
	Fn2(2.5, 3.5, product);
	std::cout << product << std::endl;	// 출력: 8.75 

	std::cout << "\n### 3 ###" << std::endl;
	// 3(3). 아래 코드에서 n1에서 n2까지의 자연수의 합을 반환하는 Fn3 함수를 정의하라.
	// (Define the Fn3 function that returns the sum of the natural numbers from n1 to n2 in the following codes.)
	int n1 = 2, n2 = 5, sum = 0;
	sum = Fn3(n1, n2);				// sum = 2+3+4+5, sum = Fn3(2, 5)도 가능해야 함
	std::cout << sum << std::endl;	// 출력: 14

	std::cout << "\n### 4 ###" << std::endl;
	// 4(3). 아래의 코드에서 인수의 약수 개수를 반환하는 Fn4 함수를 정의하라.
	// (Define the Fn4 function that returns the number of divisors of the argument.)
	std::cout << Fn4(10) << ", ";			// 출력: 4
	std::cout << Fn4(36) << ", ";			// 출력: 9	
	std::cout << Fn4(1) << ", ";			// 출력: 1
	std::cout << Fn4(-10) << std::endl;		// 출력: 0

	std::cout << "\n### 5 ###" << std::endl;
	// 5(3). 아래 코드에서 v1의 요소가 제곱의 값으로 할당되는 Fn5 함수를 정의하라.
	// (Define the Fn5 function, where elements of the argument vecotr (v1) are assigned their squares in the following codes.) 
	std::vector<int> v1{ 1, 2, 7 };
	Fn5(v1);
	Print(v1);	// 출력: 1, 4, 49,

	std::cout << "\n### 6 ###" << std::endl;
	// 6(4). 아래의 코드에서 std::vector<int> Fn6(const int n) 함수를 정의하라. Fn6는 중복되지 않는 [0, 9]의 임의의 정수를 요소로 가지는 크기가 n인 벡터를 반환한다. 
	// (Define std::vector<int> Fn6(const int n) in the following codes. Fn6 returns a vector of n size with elements of non-duplicate random integers ranging [0,9].)
	//std::vector<int> s;
	//s = Fn6(5);			// 1, 2, 3, 4, 1, (이와 같은 출력은 불가능, 1이 중복됨)
	//Print(s);			// 예) 6, 7, 2, 5, 0,
	//s = Fn6(3);
	//Print(s);			// 예) 6, 2, 7, 
	//s = Fn6(11);
	//Print(s);			// 요소 출력 없음

	std::cout << "\n### 7 ###" << std::endl;
	// 7(3). 아래 코드에서 1부터 인수까지의 자연수의 합을 반환하는 Fn7 함수를 recursive call을 이용하여 정의하라.(가능한 효율적이고 간단하게 작성)
	// (Define the Fn7 function that returns the sum of the natural numbers from 1 to the argument using recursive call. - The function should be written as efficiently and simply as possible.)
	//std::cout << Fn7(10) << ", ";			// 출력: 55
	//std::cout << Fn7(7) << ", ";			// 출력: 28
	//std::cout << Fn7(-10) << std::endl;		// 출력: 0
}