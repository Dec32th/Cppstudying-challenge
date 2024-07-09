#pragma once
#include<iostream>
#include<string>
using namespace std;

const int MAX_STUDENTS = 1000;
struct StudentInfo
{
	int id;
	string name;
	double gpa;
};

class Student
{
public:
	Student();
	~Student() {};
	void InitValue(int index, int id, const string name, double gpa);
	void GetStudentInfo(int index) const;
	int GetStudentNum() const;
	StudentInfo* GetStudents();
	friend void BubbleSort(Student& stu);
	
private:
	StudentInfo students[MAX_STUDENTS];
	int studentNum; //현재 학생 수 
};


