#pragma once

class MyException
{
public:
	const void* sender;				//예외를 던진 객체 주소
	const char* description;		//예외에 대한 설명
	int info;						//부가 정보

	MyException(const void* sender, const char* description, int info)
	{
		this->sender = sender;
		this->description = description;
		this->info = info;
	}
};

//index와 관련된 예외
class OutOfRangeException :public MyException
{
public:
	OutOfRangeException(const void* sender, int index)
		:MyException(sender, "Out of Range!!!", index)
	{
	}
};

//메모리와 관련된 에러
class MemoryException :public MyException
{
public:
	MemoryException(const void* sender, int bytes)
		:MyException(sender, "Out of Memory!!!", bytes)
	{
	}
};