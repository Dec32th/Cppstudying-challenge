#pragma once
#include<iostream>
#include<array>
#include<vector>
#include<utility>
#include<cstdarg>
#include<cstddef>
#include<list>
#include<deque>
#include<stdexcept>
#include<cassert>
using namespace std;


//# 15, 16을 위한 IPv4 class -> 15와 16은 이거 하나를 이용해서 하기
class IPv4 
{
	array<unsigned char, 4> ipv4_arr;
	int IPv4_32bit = 0;
	
public : 
	// 참조를 통해서 원본에 직접관여할 수 있도록 함
	// friend를 통해서 입출력 받는 operator를 오버로딩하고 그것이 class내부의 array에 접근 가능하도록함
	
	// 생성자  - 배열 초기화.
	IPv4()
	{
		for (int i = 0; i < 4; i++)
		{
			ipv4_arr[i] = 0;
		}
	}
	
	IPv4(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
	{
		ipv4_arr[0] = a;
		ipv4_arr[1] = b;
		ipv4_arr[2] = c;
		ipv4_arr[3] = d;

		IPv4_32bit = (a << 24) + (b << 16) + (c << 8) + d;
			
	}

	void bitToIPv4()
	{
		ipv4_arr[0] = (IPv4_32bit >> 24) & 0xFF;
		ipv4_arr[1] = (IPv4_32bit >> 16) & 0xFF;
		ipv4_arr[2] = (IPv4_32bit >> 8) & 0xFF;
		ipv4_arr[3] = IPv4_32bit & 0xFF;
	}

	void PrintAddress()
	{
		cout << ipv4_arr[0] << "."
			<< ipv4_arr[1] << "."
			<< ipv4_arr[2] << "."
			<< ipv4_arr[3];
	}

	friend istream& operator>>(istream& is, IPv4& address)
	{
		char dot;
		return is >> address.ipv4_arr[0] >> dot
			>> address.ipv4_arr[1] >> dot
			>> address.ipv4_arr[2] >> dot
			>> address.ipv4_arr[3] >> dot;
	}
	
	friend ostream& operator<<(ostream& os, IPv4& address)
	{
		char dot = '.';
		return os << address.ipv4_arr[0] << dot
			<< address.ipv4_arr[1] << dot
			<< address.ipv4_arr[2] << dot
			<< address.ipv4_arr[3] << dot;
			
	}

	//기존에 짠 변환 없이 하는 코드. 
	//비효율적이라 폐기
	/*bool operator>(const IPv4 other) const 
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.ipv4_arr[i] > other.ipv4_arr[i])
				return true;
			if (other.ipv4_arr[i] < other.ipv4_arr[i])
				return false;
		}
	}
	
	bool operator<(const IPv4 other) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (other.ipv4_arr[i] < other.ipv4_arr[i])
				return true;
			if (other.ipv4_arr[i] > other.ipv4_arr[i])
				return false;
		}
	}

	bool operator==(const IPv4 other) const
	{
		return other.ipv4_arr == ipv4_arr;
	}


	IPv4 operator+(IPv4 other)
	{
		IPv4 result;
		
		
		for (int i = 3; i >=0 ; i--)
		{	
			if (i > 0 && static_cast<int>(other.ipv4_arr[i]) + static_cast<int>(ipv4_arr[i]) > 255)
			{
				result.ipv4_arr[i - 1] = result.ipv4_arr[i-1] + 1;
				result.ipv4_arr[i] = ipv4_arr[i] + other.ipv4_arr[i];
			}
			if (static_cast<int>(other.ipv4_arr[0]) + static_cast<int>(ipv4_arr[0]) > 255)
			{
				cout << "Number error! This address is out of range." << endl;
				return result;
			}
		}
		return result;
	}*/


	// 신규 계산법 -> 32비트 변환 이용
	//비교, 덧셈, 뺄셈은 전부 이걸로 처리
	bool operator==(IPv4 other)
	{
		return IPv4_32bit == other.IPv4_32bit;
	}

	bool operator<(IPv4 other)
	{
		IPv4_32bit < other.IPv4_32bit ? true : false;
	}

	bool operator>(IPv4 other)
	{
		IPv4_32bit > other.IPv4_32bit ? true : false;
	}

	IPv4 operator+(IPv4 other)
	{
		IPv4 result;
		if (IPv4_32bit + other.IPv4_32bit > 4294967295)
		{
			throw out_of_range("This is unavailable number");
		}
		result.IPv4_32bit = IPv4_32bit + other.IPv4_32bit;
		result.bitToIPv4();
		return result;
	}
	
	IPv4 operator-(IPv4 other)
	{
		IPv4 result;
		if (IPv4_32bit == other.IPv4_32bit)
			return result;
		
		if (IPv4_32bit > other.IPv4_32bit)
		{
			result.IPv4_32bit = IPv4_32bit - other.IPv4_32bit;
			result.bitToIPv4();
			return result;
		}

		if (IPv4_32bit < other.IPv4_32bit)
		{
			result.IPv4_32bit = other.IPv4_32bit-IPv4_32bit;
			result.bitToIPv4();
			return result;
		}
	}
	
	void PrintAdToAd(IPv4 other)
	{
		IPv4 result;
		for (int i = 1; i < IPv4_32bit - other.IPv4_32bit; i++)
		{
			result.IPv4_32bit = IPv4_32bit > other.IPv4_32bit ? other.IPv4_32bit + i : IPv4_32bit + i;
			result.bitToIPv4();
			result.PrintAddress();
		}
	}
};

// #17 기본적인 연산을 지원하는 2차원 배열 구현하기 - class template를 만들기 
// 1. 원소에 접근하는 메소드 at()과 data() 
// at method는 범위를 넘어가면 볌위를 넘어서 검색이 불가능.  + out of range에러를 통해 범위를 넘어가는 경우에 대한 메시지 제공.
// 2. 각 차원의 크기를 반환하는 메소드 
// 4. iterator를 제공해야함
// 5. 배열을 하나의 값으로 체우는 메소드 fill
// 6. 동일한 차원의 다른 객체와 내용물을 교환하는 메소드
// 7. 이 타입의 객체는 이동을 지원해야함. -> move?? 이게 뭐지

template<class T, size_t d1, size_t d2>
class Array2d
{
	T* arr2D;
public:
	//iterator 생성하기
	class myIter
	{
		private:
		T* ptr;
		public:
			myIter(): ptr(nullptr) {}
			myIter(T* p) : ptr(p) {}
			T& operator*() { return *ptr; }
			myIter operator++() { ++ptr; return *this; }
			bool operator!=(const myIter& other) { return ptr != other.ptr; }
	};

	myIter begin() { return myIter(arr2D); }
	myIter end() { return myIter(arr2D + (d1 * d2)); }
	
	Array2d()
	{
		arr2D = new T[ d1 * d2 ];
	}

	Array2d(Array2d&& other) noexcept : arr2D(other.arr2D)
	{
		other.arr2D = nullptr;
	}

	~Array2d()
	{
		delete[] arr2D;
		
	}

	const T& at(size_t a, size_t b) const
	{
		if (a >= d1 || b >= d2)
		{
			throw out_of_range("This index is out of range.");
		}
		return arr2D[a*d2 + b];
	}

	T& at(size_t a, size_t b)
	{
		if (a >= d1 || b >= d2)
		{
			throw out_of_range("this index is out of range.");
		}
		return arr2D[a*d2 +b];
	}

	T* data() 
	{ 
		return arr2D;
	}

	void move_2D(Array2d& other) noexcept
	{
		if (this != &other)
		{
			delete[] arr2D;
			arr2D = other.arr2D;
			other.arr2D = nullptr;
		}
	}

	Array2d& operator=(Array2d&& other) noexcept
	{
		if (this != &other)
		{
			delete[] arr2D;
			arr2D = other.arr2D;
			other.arr2D = nullptr;
		}
		return *this;
	}

	void Swap2D(Array2d& other) 
	{
		if (this == &other)
			return;
		for (size_t i = 0; i < d1; i++)
		{
			T temp = arr2D[i];
			arr2D[i] = other.arr2D[i];
			other.arr2D[i] = temp;
		}
	}

	pair<size_t, size_t> SizeOf2D() const
	{
		return { d1, d2 };
	}

	void fill2dArr(T value)
	{
		for(myIter iter = begin(); iter!=end(); ++iter )
		{
			*iter = value;
		}
	}

	

};


// #18 여러 수를 인자로 받는 최소함수 작성하기
// 여러 개의 수를 인자로  < 를 이용해서 인자들을 비교한 뒤, 가장 작은 값을 반환하는 함수 템플릿. 
// #18-1 두 개의 수를 비교하는 함수를 매개변수로 하는 형태

//기본 함수 만들기(2개 비교)
template<typename t1, typename t2>
auto MinNum(t1 a, t2 b)
{
	return (a > b) ? b : a;
}

//기본 함수를 이용해서 여러개의 값 중에서 최소를 찾을 수 있도록 하기
template<typename first, typename ...Rest>
auto MinNum(first t1, Rest...tn)
{
	return MinNum(t1, MinNum(tn...));
}

//#19 pushback이 있는 곳에 여러 개의 값을 입력 받을 수 있도록 pushback을 구현하기
// vector와 list에서 수정할 수 없으므로 새로운 container를 만들어야함!

// #20 컨테이너 안의 원소를 조건별로 확인
// any(컨테이너 내부에 어떤 원소가 존재하는지 확인) -> 입력 받은 여러개 중에서 하나라도 있으면 true를 return하는 듯
// all(주어진 모든 원소가 존재하는지 확인) 
// none(컨테이너 내부에 주어진 원소가 존재하지 않는지를 확인하는 함수)
template<typename T>
class MyContainer
{
	T data;
public:

	MyContainer() = default;
	void push_back(const typename T::value_type& value)
	{
		data.push_back(value);
	}

	template<typename ...Args>
	void push_back(Args&&... arg)
	{
		(data.push_back(forward<Args>(arg)), ...);
	}

	void print() const {
		for (const auto& elem : data)
		{
			cout << elem << " ";
		}
		cout << endl;
	}

	// 여기서부터 20번 구현
	// find 함수
	bool contains(const typename T::value_type& value) const
	{
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			if (*it == value) return true;
		}
		return false;
	}

	template<typename ...Args>
	bool contain_any(const Args& ...args) const
	{
		return (contains(args) || ...);
	}

	template<typename ...Args>
	bool contain_all(const Args&...args) const
	{
		return (contains(args)&& ...);
	}

	template<typename ...Args>
	bool contain_none(const Args&...args) const
	{
		return (!contains(args)&& ...);
	}
};

// #21 문제
// 시스템 핸들 래퍼를 작성
// 핸들을 획득하거나 해제할 수 있어야하고, 유효성을 확인할 수 있어야한다.
// 핸들의 소유권을 한 객체에서 다른 객체로 이동할 수 있어야한다.

// -> 2025.03.20 이후에 구현하기로 변경

// #22 온도 단위 리터럴을 제공하는 라이브러리 작성하기
// -> 외부 구현. temperature lib


