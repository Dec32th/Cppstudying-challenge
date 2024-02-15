#pragma once
#include<exception>
using namespace std;

//이 프로젝트 사용할 예외
class MyException : public exception
{
public:
	//생성자
	//msg : 예외를 설명하는 문자열
	MyException(const string& msg)
		:_Str(msg)
	{
	}

	//destructor
	virtual ~MyException()
	{
	}

	//예외 설명 문자열을 반환
	//반환 값 : 문자열
	virtual const char *what() const
	{
		return _Str.c_str();
	}

protected:
	string _Str;
};