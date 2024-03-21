//modern C++ challenge - #6~10

#include<iostream>
#include<vector>
#include<array>

using namespace std;

//#6. 과잉수 구하기 : 과잉수란 자신을 제외한 약수들의 합이 자신보다 작은 수를 이야기한다.
//과잉수를 벡터1에 넣고, 과잉수의 과잉을 벡터2에 넣어서 저장한다. 출력시 이 둘을 출력하도록 한다.
void vAbundance(int const iNum)
{
	vector<int> vec1;	//과잉수 저장
	vector<int> vec2;	//과잉수의 과잉 저장.

	if (iNum < 12)
	{
		cout << "There are no abundance in this range.";
	}
	else
	{
		for (int i = 12; i <= iNum; i++)
		{
			int iTotal = 1;
			for (int j = 2; j < i; j++)	//약수인지 check.
			{
				if (i % j == 0)
				{
					iTotal += j;
				}
			}

			if (iTotal > i)
			{
				vec1.push_back(i);
				vec2.push_back(iTotal);
			}
		}
		for (int k = 0; k < vec1.size(); k++)
		{
			cout << "Abundance number(" << vec1[k] << ") : " << "abundance(" << vec2[k] <<")" << endl;
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
		//여기에는 자기 자신을 제외한 약수의 합을 구하는 함수를 사용한다. - 20240321 기준, 이 함수를 이용해 과잉수 함수를 수정.
		for (int i = 220; i <= iNum; i++)
		{

		}
	}
}

//자기 자신을 제외한 약수의 합을 구하는 함수, #6, 7에서 사용된다.
int iCalSum(unsigned int iNum)
{
	unsigned int iSum = 1;
	for (int j = 2; j < iNum; j++)
	{
		if (iNum % j == 0)
		{
			iSum += j;
		}
	}
	return iSum;
}

int main()
{
	/*vAbundance(20);*/
	/*vAmicableNumber();*/
}