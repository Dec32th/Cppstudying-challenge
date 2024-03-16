#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
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
	//합을 저장할 변수 설정
	int iSum = 0;

	//for문을 통해서 iNum보다 작거나 같아질 때까지 3의 배수 또는 5의 배수를 더함.
	for (int i = 1; i <= iNum; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			iSum += i;
		}
	}
	return iSum;
}


//#2	최대공약수 구하기 - recursive function 이용
int iGcd(int iNum1, int iNum2)
{
	//유클리드 호제법 이용. 
	//iNum의 값이 0미만일 경우, 구할 수 없으므로 예외처리
	if (iNum1 <= 0 || iNum2 <= 0)
	{
		cout << "there is wrong number.Please enter the right number.";
	}
	else
	{
		//parameter 중에서 더 큰 숫자 판별, max min에 대입
		int iMax = iNum1 > iNum2 ? iNum1 : iNum2;
		int iMin = iNum1 > iNum2 ? iNum2 : iNum1;

		//유클리드 호제법
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

//#2 +a 최대공약수 구하기 (단, 숫자가 n개 들어올 떄)


//#3 최소공배수 구하기
//책 내용 참고해서 구함
//근데 왜 안먹는지 모르겠다 제기랄!!!!!
int iLcm(int iNum1, int iNum2)
{
	//두 수의 최대공약수를 구한다. (음수나 0의 입력이 들어오면 0을 리턴하고, 그 경우에는 값이 잘못되었음을 알 수 있다.)
	int h = iGcd(iNum1, iNum2);
	return h ? iNum2 * (iNum1 / h) : 0;
}


//#4 주어진 수 이하인 가장 큰 소수를 구하는 함수
//책 내용 참고해서 구함
int iMaxPrime(int iNum)
{
	bool primeCheck = true;
	//1. 입력 받은 수의 범위 및 정당성 체크
	if (iNum <=1)
	{
		cout << "Please enter the right number. That's wrong number.";
		return 0;
	}
	else if (iNum <= 3)
	{
		return iNum > 1;
	}
	else
	{
		for(int i = iNum; i>=2; i--)	//돌면서 i를 통해서 나누어지는 수가 소수인지 체크한다. i는 나누어지는 수
		{
			for (int j = 2; j <= sqrt(iNum); j++)	//i를 나누는 수 j. j로 나누어지면 이제 for문이 break
			{
				if (i % j == 0)
				{
					primeCheck = false;
					break;
				}
			}
			if (primeCheck == true)
			{
				return i;
			}
		}
	}

	
}

//#5. 섹시소수 (두 소수간의 차가 6인 소수) 구하기
//#4에서 이용한 소수인지 검사하고, 그 다음에 6차이 나는지 검사? 또는 bool을 return하는 함수를 하나 만들고 그 함수를 통해서?
int SixPrime(int iNum)
{
	int iCount6Prime = 0;
	if (iNum <11 )
	{
		cout << "Please enter the right number. That's a wrong number.";
		return 0;
	}
	else
	{

	}
}

int main()
{
	/*3과 5의 배수를 더하는 함수를 이용하기 위한 예제 변수*/
	//int iNum1 = 0;
	//cout << "Please enter the maximum number to calculate multiple of 3 or 5." << endl;
	//cin >> iNum1;

	////함수를 이용해 출력
	//cout << "The answer is " << Sum3or5(iNum1) << endl;


	//GCD함수를 이용하기 위한 예제변수
	/*int iNum2, iNum3;
	cout << "Enter two numbers.";
	cin >> iNum2 >> iNum3;

	cout <<"The gcd is "<< iGcd(iNum2, iNum3);*/


	//lcm 함수를 이용하기 위한 예제 변수
	int iLcmNum1, iLcmNum2;
	cout << "Enter two numbers for calculation of LCM : ";
	cin >> iLcmNum1 >> iLcmNum2;
	cout << "The LCM is " <<iLcm(iLcmNum1,iLcmNum2);
}