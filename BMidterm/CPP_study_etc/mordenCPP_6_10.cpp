//modern C++ challenge - #6~10

#include<iostream>
#include<vector>

using namespace std;

//#1. 과잉수 구하기 : 과잉수란 자신을 제외한 약수들의 합이 자신보다 작은 수를 이야기한다.
//과잉수를 벡터1에 넣고, 과잉수의 과잉을 벡터2에 넣어서 저장한다. 출력시 이 둘을 출력하도록 한다.
void iAbundance(int const iNum)
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

int main()
{
	/*iAbundance(20);*/
}