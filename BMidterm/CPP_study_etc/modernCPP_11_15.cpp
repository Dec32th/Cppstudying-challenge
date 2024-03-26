#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
#include<random>

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
//1부터 100만까지 다 해야하므로 함수가 무거움.
// 
//void vCollatz(unsigned int iLimit)
//{
//	vector<pair<int, long long>> vec1;
//	int iCount = 0;
//	for (int i = 1; i <= iLimit; i++)
//	{
//		if (i == 1)
//			vec1.push_back((make_pair(i, iCount)));
//		while (i != 1)
//		{
//			if (i % 2 == 0)
//			{
//				i /= 2;
//				iCount++;
//			}
//			else
//			{
//				i = i * 3 + 1;
//				iCount++;
//			}
//		}
//		
//	}
//	int iResult1 = vec1[0].first;
//	long long iResult2 = vec1[0].second;
//	for (auto elem : vec1)
//	{
//		if (iResult2 < elem.second)
//		{
//			iResult2 = elem.second;
//			iResult1 = elem.first;
//		}
//			
//	}
//	
//	int iNumber1 = iResult1;
//	while (iNumber1 != 0)
//	{
//			if (iNumber1 % 2 == 0)
//			{
//				cout << iNumber1 <<endl;
//				iNumber1 /= 2;
//				
//			}
//			else
//			{
//				cout << iNumber1 << endl;
//				iNumber1 = iNumber1 * 3 + 1;
//			}
//	}
//	cout << iResult2;
//}

pair<unsigned long long, long>longest_collatz(unsigned long long const limit)
{
	long length = 0;
	unsigned long long number = 0;
	vector<int> cache(limit + 1, 0);
	for (unsigned long long i = 2; i <= limit; i++)
	{
		auto n = i;
		long steps = 0;
		while (n != 1 && n >= i)
		{
			if ((n % 2) == 0)
				n = n / 2;
			else
				n = n * 3 + 1;
			steps++;
		}
		cache[i] = steps + cache[n];

		if (cache[i] > length)
		{
			length = cache[i];
			number += i;
		}
	}
	return make_pair(number, length);
}

//#13 파이 값 계산하기 
//책에서의 방법과 조금 다르게 써본다. 
// 여기서는 그레고리 라이프니츠 급수를 사용 - 20240326기준, 제대로 동작은 하나, 
//while문을 너무 오랫동안 돌아서 거의 무한루프급으로 시간이 오래 걸리는 듯 하다.
double dcompute_pi()
{
	double result = 4.;
	int iCount = 1;

	do
	{
		if (iCount % 2 != 0)
		{
			result -= 4. / ((2 * iCount) + 1);
			cout << result << endl;
			iCount++;
			cout << iCount << endl;
		}
		else
		{
			result += 4. / ((2 * iCount) + 1);
			cout << result << endl;
			iCount++;
			cout << iCount << endl;
		}

	} while (result != 3.1415926535);
	return result;
}


//#13 책에 적혀있는 방법 사용
template<typename E = std::mt19937,
	typename D = std::uniform_real_distribution<>>
	double compute_pi(E& engine, D& dist, int const samples = 1000000)
{
	auto hit = 0;
	
}

int main()
{
	/*cout << sToRomain(53) << endl;
	cout << sToRomain(83) << endl;
	cout << sToRomain(901) << endl;*/
	
	cout << dcompute_pi();
}