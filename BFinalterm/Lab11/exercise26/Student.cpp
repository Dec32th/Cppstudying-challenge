#include"Student.h"
#include<iostream>
using namespace std;

Student::Student()
{
	studentNum = 0;
}

void Student::InitValue(int index, int id, const string name, double gpa)
{
	if (index >= 0 && index < MAX_STUDENTS)
	{
		students[index].id = id;
		students[index].name = name;
		students[index].gpa = gpa;

		if (index >= studentNum)
			studentNum = index + 1;
	}
	else
		cout << "Invalid index" << endl;
}

void Student::GetStudentInfo(int index) const
{
	if (index >= 0 && index < studentNum)
	{
		cout << "ID : " << students[index].id
			<< ", Name : " << students[index].name
			<< ", GPA : " << students[index].gpa << endl;
	}
	else
		cout << "Invalid index" << endl;
}

int Student::GetStudentNum() const
{
	return studentNum;
}

StudentInfo* Student::GetStudents()
{
	return students;
}