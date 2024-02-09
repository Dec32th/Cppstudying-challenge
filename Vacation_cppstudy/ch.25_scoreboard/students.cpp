#include"students.h"
#include"student.h"
#include<iostream>
using namespace std;

//constructor
//+call list constructor
Students::Students()
	:students(&Students::DeleteData)
{
	//initialize
	TotalAve = 0.0f;
	NumberOfStudent = 0;
}

//destructor
Students::~Students()
{

}

//학생 한 명 추가
//더 이상 입력 불가능일 경우 false 반환
bool Student::AddStudent()
{
	//링크드 리스트에 넣기 위해 Student 변수 하나를 동적으로 할당한다.
	Student* std = new Student(NumberOfStudent + 1);

	//개인 정보를 입력 받는다.
	std = > Input();
}