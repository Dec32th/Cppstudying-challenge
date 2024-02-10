#pragma once

//linked list 사용
#include"List.h"

//성적 정보를 관리하는 클래스
class Students
{
public:
	Students();
	~Students();

	bool AddStudent();
	void ShowAll();

	//이 함수의 주소를 List 객체의 생성자에 넘겨주면 정적 멤버함수가 되어야만 가능
	static void DeleteData(void* data);
private:
	List students;				//링크드 리스트
	float TotalAve;				//전체 평균
	int NumberOfStudent;		//현재까지 입력한 학생 수
};