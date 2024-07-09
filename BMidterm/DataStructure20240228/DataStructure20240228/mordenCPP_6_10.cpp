//modern C++ challenge - #6~10

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<bitset>

using namespace std;

//자기 자신을 제외한 약수의 합을 구하는 함수, #6, 7에서 사용된다.
int iCalSum(unsigned int iNum1)
{
	unsigned int iSum = 1;
	for (int j = 2; j < iNum1; j++)
	{
		if (iNum1 % j == 0)
		{
			iSum += j;
		}
	}
	return iSum;
}


//#6. 과잉수 구하기 : 과잉수란 자신을 제외한 약수들의 합이 자신보다 큰 수를 이야기한다.
//과잉수를 벡터1에 넣고, 과잉수의 과잉을 벡터2에 넣어서 저장한다. 출력시 이 둘을 출력하도록 한다.
// 
//20240322 기준 수정 완료
void vAbundance(int const iNum)
{
	//vector<int> vec1;	//과잉수 저장
	//vector<int> vec2;	//과잉수의 과잉 저장.

	//if (iNum < 12)
	//{
	//	cout << "There are no abundance in this range.";
	//}
	//else
	//{
	//	for (int i = 12; i <= iNum; i++)
	//	{
	//		int iTotal = 1;
	//		for (int j = 2; j < i; j++)	//약수인지 check.
	//		{
	//			if (i % j == 0)
	//			{
	//				iTotal += j;
	//			}
	//		}

	//		if (iTotal > i)
	//		{
	//			vec1.push_back(i);
	//			vec2.push_back(iTotal);
	//		}
	//	}
	//	for (int k = 0; k < vec1.size(); k++)
	//	{
	//		cout << "Abundance number(" << vec1[k] << ") : " << "abundance(" << vec2[k] <<")" << endl;
	//	}
	//}

	if (iNum < 12)
		cout << "There are no abundance in that range.";
	else
	{
		for (int i = 12; i < iNum; i++)
		{
			if (iCalSum(i) > i)
			{
				cout << "Abundance number (" << i << ", " << iCalSum(i) << ")" << endl;
			}
		}
	}
}

//#7 100만보다 작은 친화수를 구하기 : 친화수는 a의 자기 자신을 제외한 약수의 합이 b가 되고 b의 경우에는 그 반대가 되는 수들의 순서쌍
//위와 동일하게 순서쌍을 벡터에 넣어두고 그 벡터를 이용해서 출력. 오로지 출력을 하기 위해서 void형으로 만듦

//20240321 기준 값을 처리되지 않는 예외가 발생. 수정 필요
void vAmicableNumber(int iNum)
{
	//100만이 상한이지만, 입력받은 수로 구하자.
	if (iNum < 284)
		cout << "There are no amicable numbers in that range";
	else
	{
		//여기에는 자기 자신을 제외한 약수의 합을 구하는 함수를 사용한다. 
		for (int i = 220; i <= iNum; i++)
		{
			int iTemp = iCalSum(i);

			if (i == iCalSum(iTemp) && i!=iTemp)
			{
				cout << "(" << i << ", " << iTemp << ")" << endl;
			}
		}
	}
}


//#8 암스트롱 수 구하기 : 세 자리 수 중에서 각 자리의 수를 세제곱한 수들의 합이 기존의 수와 똑같은 수를 암스트롱 수라고 한다.
//출력할 수 있도록 구하기. 그리고 그 수는 100-999까지의 범위를 가진다.
void vAmstrongNumber()
{
	for (int i = 100; i < 1000; i++)
	{
		//100의 자리부터 10의 자리까지 구하기
		int iHund = i / 100;
		int iTen = (i / 10) % 10;
		int iOne = i % 10;

		if (pow(iHund, 3) + pow(iTen, 3) + pow(iOne, 3) == i)
		{
			cout << "The number " << i << " is Amstrong Number." << endl;
		}
	}
}

//#8 소인수분해 프로그램 제작하기
void vprime_factor(int iNum)
{
	//소인수분해도 결국 약수를 구하는 것(1과 자기 자신을 제외한 약수를 구한다는 차이만 존재.)
	//그러므로 약수를 구한다. 
	for (int i = 2; i * i <= iNum; i++)
	{
		while (iNum % i == 0)
		{
			cout << i << endl;
			iNum /= i;
		}
	}

	//연산들을 진행했는데 나눠지지 않은 경우. 소인수 분해가 안된다는 뜻이므로 이 수가 소수.
	if (iNum > 1)
	{
		cout << iNum;
	}
	
}

//#10 그레이 코드 변환하기
//책 내용 참고 
unsigned int gray_encode(unsigned int const num)
{
	return num ^ (num >> 1);
}

unsigned int gray_decode(unsigned int gray)
{
	for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1)
	{
		if (gray & bit) gray ^= bit >> 1;
	}
	return gray;
}


std::string to_binary(unsigned int value, int const digits)
{
	return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main()
{
	/*vAbundance(20);*/

	//친화수 구하는 프로그램은 무거우므로 자주 실행하지 말자. - 제대로 동작하는 것을 확인.
	/*vAmicableNumber(100000000);*/

	/*vAmstrongNumber();*/

	/*vprime_factor(36);
	vprime_factor(16);
	vprime_factor(17);*/
	

	//#10 그레이코드 변환
	cout << "Number\tbinary\tGray\tDecoded" << endl;
	cout << "------\t-----\t----\t------\n";
	
	for (unsigned int n = 0; n < 32; ++n)
	{
		auto encg = gray_encode(n);
		auto decg = gray_decode(encg);

		cout << n << "\t" << to_binary(n, 5) << "\t"
			<< to_binary(encg, 5) << "\t" << decg << endl;
	}
}