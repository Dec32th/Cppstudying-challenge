#pragma once
#include<string>
using namespace std;

//한 명의 학생에 대한 정보를 관리
class Student
{
public:
	Student(int sNo);
	void Input();
	void Show() const;

	//accessor
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;

protected:
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};