#include<iostream>
#include<string>
#include<sstream>
#include<numeric>
#include<vector>
#include<array>
#include<utility>
#include<random>
#include<cmath>
#include<cstdlib>
#include<assert.h>

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
template<typename E = mt19937,
	typename D = uniform_real_distribution<>>
	double compute_pi(E& engine, D& dist, int const samples = 1000000)
{
	auto hit = 0;
	for (auto i = 0; i < samples; i++)
	{
		auto x = dist(engine);
		auto y = dist(engine);
		if (y <= sqrt(1 - pow(x, 2))) 
			hit += 1;
	}
	return 4.0 * hit / samples;
}

//#14. ISBN 검증 프로그램 구하기
//총 10자리로 이루어지며, 처음부터 마지막 까지 10-1의 숫자를 곱하고 그 곱한 수들을 다 더해서 11의 배수가 되도록 마지막 숫자를 정한다.
//bool형의 함수로 구현하고, 입력받는 수는 문자열이다. 문자열이 모두 숫자이고, 유효한 isbn일 때, true를 반환한다.
//20240328 기준 새로 구현하는 게 필요하다!
bool is_isbn(string sStr)
{
	//값을 정수로 바꾸기 위해서 필요함.
	stringstream sString;

	//임시로 받은 값을 저장하는 int형 변수. 받은 값을 게속 벡터에 넣는다.
	int iNum = 0;

	//받은 문자열을 숫자로 변환하기 위한 vector변수, 뒤부터 한 글자씩 잘라서 넣어준다. 
	vector<int> vec1;
	
	for (int i = 0; i < 10; i++)
	{
		//초기화를 해야 다른 목적으로 재사용이 가능하다.
		sString.str("");
		int iNum = 0;

		sString << sStr[i];
		cout << "sStr[i] : " << sStr[i] << endl;

		sString >> iNum;
		cout << "iNum : " <<iNum <<endl;

		vec1.push_back(iNum);
	}

	//isbn의 값이 제대로 된 값인지 체크하기 위한 int형 변수 가중치를 통해서 그 값이 제데로 된 값인지 판별한다. 
	int iSum = 0;
	for (int j = 10; j > 0; j--)
	{
		for (int k = 0; k < 10; k++)
		{
			iSum += vec1[k] * j;
			cout << "This is iSum : "<<iSum << endl;
		}
	}

	cout << iSum << endl;
	//11의 배수인 경우, true 리턴
	if (iSum % 11 == 0)
		return true;

	//그렇지 않은 경우, false return
	else
		return false;

}

//#14. 책의 코드
//위의 14번 코드는 sstream의 값이 초기화가 되지 않아서 제대로 값을 전달할 수 없다! 왜이러는지 모르겠다.
bool validate_isbn_10(string_view isbn)
{
	auto valid = false;
	if (isbn.size() == 10 &&
		count_if(begin(isbn), end(isbn), isdigit) == 10)
	{
		auto w = 10;
		auto sum = accumulate(
			begin(isbn), end(isbn), 0,
			[&w](int const total, char const c)
			{
				return total + w-- * (c - '0');
			});
		valid = !(sum % 11);
	}
	return valid;
}

//#15. IPv4 데이터 형식 표현하는 함수 작성하기
// 콘솔 기능을 통해 주소를 읽고 써야함. 점으로 구분된거 입력
// 출력도 같은 형식으로
//?근데 얘는 뭘 어떻게 나타내라는 것인지 잘 이해가 안가는데 - 일단 책의 코드는 아래와 같다.

class ipv4
{
	array<unsigned char, 4> data;
public:
	constexpr ipv4() : data{ {0} } {}
	constexpr ipv4(unsigned char const a, unsigned char const b,
		unsigned char const c, unsigned char const d) : 
		data{{a,b,c,d}} {}
	explicit constexpr ipv4(unsigned long a) : 
		data{{static_cast<unsigned char>((a>>24)&0xFF),
			static_cast<unsigned char>((a>>16)&0xFF),
			static_cast<unsigned char>((a>>8)&0xFF),
			static_cast<unsigned char>(a&0xFF),
			}} {}
	ipv4(ipv4 const &other) noexcept : data(other.data) {}
	ipv4& operator=(ipv4 const& other) noexcept
	{
		data = other.data;
		return *this;
	}

	string to_string() const
	{
		stringstream sstr;
		sstr << *this;
		return sstr.str();
	}
	
	constexpr unsigned long to_ulong() const noexcept
	{
		return (static_cast<unsigned long>(data[0]) << 24) |
			(static_cast<unsigned long>(data[1]) << 16) |
			(static_cast<unsigned long>(data[2]) << 8) |
			static_cast<unsigned long>(data[3]);
	}

	friend ostream& operator<<(ostream& os, const ipv4& a)
	{
		os << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);

		return os;
	}

	friend istream& operator>>(istream& is, ipv4& const a)
	{
		char d1, d2, d3;
		int b1, b2, b3, b4;
		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
		if (d1 == '.' && d2 == '.' && d3 == '.')
			a = ipv4(b1, b2, b3, b4);
		else
			is.setstate(ios_base::failbit);
		return is;

	}
};


int main()
{
	/*cout << sToRomain(53) << endl;
	cout << sToRomain(83) << endl;
	cout << sToRomain(901) << endl;*/
	
	/*random_device rd;
	auto seed_data = array<int, mt19937::state_size> {};
	generate(begin(seed_data), end(seed_data), ref(rd));
	seed_seq seq(begin(seed_data), end(seed_data));
	auto eng = mt19937{ seq };
	auto dist = uniform_real_distribution<>{ 0,1 };

	for (auto j = 0; j < 10; j++)
		cout << compute_pi(eng, dist) << endl;
	*/

	cout <<is_isbn("8995432101");
	
	
}