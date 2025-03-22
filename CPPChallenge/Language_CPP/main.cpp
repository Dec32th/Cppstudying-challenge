#include<iostream>
#include<array>
#include<stdexcept>
#include"Lang15_22.h"
#include "temperature_staticlib.hpp"
using namespace std;

int main()
{
	// # 15, 16 문제 검증
	IPv4 ip1(192, 33, 2, 1);
	IPv4 ip2(100, 03, 0, 171);

	try
	{
		ip1 + ip2;
		
	}
	catch (const out_of_range& e)
	{
		cout << "This is unavailable number. Please enter the right ip." << endl;
	}

	// # 17번 테스트.

	Array2d<int, 3, 4> arr;
	arr.fill2dArr(5);

	cout << "\nSwap 전, arr2 내용 : " << endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			cout << arr.at(i, j) << " ";
		}
		cout << endl;
	}

	Array2d<int, 3, 4> arr2;
	arr2.fill2dArr(10);

	cout << "\nSwap 전, arr 내용 : " << endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			cout << arr2.at(i, j) << " ";
		}
		cout << endl;
	}
	arr.Swap2D(arr2);

	cout << "\nSwap 후, arr 내용 : " << endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			cout << arr.at(i, j) << " ";
		}
		cout << endl;
	}

	cout << "\nSwap 후, arr2 내용 : " << endl;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			cout << arr2.at(i, j) << " ";
		}
		cout << endl;
	}
	Array2d<int, 3, 4> arr3 = std::move(arr2);
	cout << "\n이동 후, arr3 내용 (iterator 사용):" << endl;
	for (auto it = arr3.begin(); it != arr3.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;


	// #18테스트
	cout << MinNum(1.2, 2, 4, 5, 16, 9, 8) << endl;
	cout << MinNum(1, 2, 1.6, 9, 0) << endl;

	// #19 컨테이너에 여러 값 삽입하기 
	// push_back(T&& value) 메소드를 갖는 임의의 컨테이너 끝 부분에 여러개의 원소를 삽입하는 범용 함수
	// 위에서 써본 cstdarg 를 쓰면 컨테이너의 끝 부분에 여러개의 원소를 삽입하는 method를 만들 수 있다.
	cout << "=== std::vector ===" << endl;
	MyContainer<vector<int>> vec;
	vec.push_back(1);
	vec.push_back(2, 3, 4, 5, 6);
	vec.print();  // 출력: 1 2 3 4 5 6

	cout << "=== std::deque ===" << endl;
	MyContainer<deque<int>> deq;
	deq.push_back(10);
	deq.push_back(20, 30, 40);
	deq.print();  // 출력: 10 20 30 40

	cout << "=== std::list ===" << endl;
	MyContainer<list<int>> lst;
	lst.push_back(100);
	lst.push_back(200, 300, 400);
	lst.print();  // 출력: 100 200 300 400

	// #20 문제 해결 테스트
	MyContainer<vector<int>> vec1;
	vec1.push_back(1, 2, 3, 4, 5);

	//  테스트 케이스 (assert 사용)
	assert(vec1.contain_any(3, 7) == true);  // 3이 존재하므로 true여야 함
	assert(vec1.contain_any(10, 20) == false); // 10, 20이 없으므로 false여야 함

	assert(vec1.contain_all(1, 2, 3) == true);  // 1, 2, 3이 모두 존재하므로 true
	assert(vec1.contain_all(1, 6) == false);   // 6이 없으므로 false

	assert(vec1.contain_none(10, 20) == true);  // 10, 20이 없으므로 true
	assert(vec1.contain_none(3, 4) == false);   // 3, 4가 존재하므로 false

	cout << "모든 테스트 통과!" << endl;

	//#21 테스트 -> 20번은 구현 생략.

	// #22 테스트
	Temperature<long double> t1 = 100.0_C;
	Temperature<long double> t2 = 212.0_F;
	Temperature<long double> t3 = 373.15_K;

	cout << "t1 (C): " << t1.get_amount() << "°C\n";
	cout << "t2 (F to C): " << t2.to_Celcius().get_amount() << "°C\n";
	cout << "t3 (K to C): " << t3.to_Celcius().get_amount() << "°C\n";

	if (t1 == t2.to_Celcius())
	{
		cout << "100°C == 212°F (Converted to Celsius)\n";
	}

	if (t1 == t3.to_Celcius())
	{
		cout << "100°C == 373.15K (Converted to Celsius)\n";
	}

	try
	{
		Temperature<long double> t4 = t1 + t2;
		cout << "Addition Result: " << t4.get_amount() << "°C\n";
	}
	catch (const std::exception& e)
	{
		cout << "Error: " << e.what() << '\n';
	}

	return 0;

}