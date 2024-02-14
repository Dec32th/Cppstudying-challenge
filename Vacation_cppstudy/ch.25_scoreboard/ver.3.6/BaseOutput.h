#pragma once
#include<string>
using namespace std;

// 소스 코드를 간결하게 하기 위해서 타입 새로 정의
typedef const string& STR;

// console 출력을 도와주는 클래스
class BaseOutput
{
public:
	virtual void BeginTable(STR title) = 0;
	virtual void PutHeader(string headers[], int number) = 0;
	virtual void PutRecord(string record[]) = 0;
	virtual void EndTable() = 0;
	virtual void Wrtie(STR text) = 0;

	virtual ~BaseOutput() {};
};