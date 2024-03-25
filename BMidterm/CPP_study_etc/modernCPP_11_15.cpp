#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>

using namespace std;


//#11. 로마숫자 표기법 - unsigned const int로 입력받고, 그 입력받은 값을 string형으로 바꿔서 반환한다.
//단, 가로줄 표기까지 하면 너무 복잡해지므로 4000의 경우 ivM으로 표기한다.
//20240325 책 참고
string sToRomain(int iNum)
{
	//두 쌍씩 묶어서 저장하는 vector. 첫 번째는 int, 두 번째는 문자열.
	vector < pair<int, string>> vec1 = { {1000,"M"} ,{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"}, {10,"Ⅹ"},{9,"Ⅸ"}, 
		{8,"Ⅷ"},{7,"Ⅶ"},{6,"Ⅵ"},{5,"Ⅴ"},{4,"Ⅳ"}, {3,"Ⅲ"}, {2,"Ⅱ"},{1,"Ⅰ"}};
	
	string sResult = "";
	int iNumber = iNum;

	//범위 판단 및 조합.
	for (auto elem : vec1)
	{
		while (iNumber >= elem.first)
		{
			sResult += elem.second;
			iNumber -= elem.first;
		}
	}

	return sResult;
}

//#12. 가장 긴 콜라츠 수열 추측하기 - 출력
//백만 이하의 숫자중, 변환을 통해서 가장 많이 연산을 해서 변환된 수를 찾고, 그 수의 연산과정을 출력하면 된다..
//1부터 100만까지 다 해야하므로 함수가 존나 무거움.
void vCollatz(unsigned int iLimit)
{
	vector<pair<int, long long>> vec1;
	int iCount = 0;
	for (int i = 1; i <= iLimit; i++)
	{
		if (i == 1)
			vec1.push_back((make_pair(i, iCount)));
		while (i != 1)
		{
			if (i % 2 == 0)
			{
				i /= 2;
				iCount++;
			}
			else
			{
				i = i * 3 + 1;
				iCount++;
			}
		}
		
	}
	int iResult1 = vec1[0].first;
	long long iResult2 = vec1[0].second;
	for (auto elem : vec1)
	{
		if (iResult2 < elem.second)
		{
			iResult2 = elem.second;
			iResult1 = elem.first;
		}
			
	}
	
	int iNumber1 = iResult1;
	while (iNumber1 != 0)
	{
			if (iNumber1 % 2 == 0)
			{
				cout << iNumber1 <<endl;
				iNumber1 /= 2;
				
			}
			else
			{
				cout << iNumber1 << endl;
				iNumber1 = iNumber1 * 3 + 1;
			}
	}
	cout << iResult2;
}

int main()
{
	/*cout << sToRomain(53) << endl;
	cout << sToRomain(83) << endl;
	cout << sToRomain(901) << endl;*/


}