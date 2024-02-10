#pragma once
#include<string>
using namespace std;

//한 명의 학생에 대한 정보를 관리
class Student
{
public:
	Student(int sNo);
	virtual~Student();
	virtual void Input();
	virtual void Show() const;

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

//고급 영어를 듣는 학생에 대한 클래스
//정보를 관리할 클래스
class EngStudent : public Student
{
public:
	EngStudent(int sNo);
	virtual void Input();
	virtual void Show() const;

protected:
	int hi_eng;
};