#include"student.h"
#include"list.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//학생의 정보를 보관할 구조체
struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

//배열 대신에 linked - list를 이용
List* students = NULL;

//전체 평균과 현재 입력된 학생 수
float TotalAve = 0.0f;
int NumberOfStudent = 0;

//학생을 한 명 추가한다.
bool AddStudent()
{
	//linkedlist에 넣기 위해서 변수를 동적으로 하나 할당.
	Student* std = new Student;
	//해당 학생의 학생번호를 자동으로 입력한다.
	std->sNo = NumberOfStudent + 1;

	//해당 학생의 이름, 국영수 점수를 입력받는다.
	cout << "이름(공백없이) 국어, 영어, 수학 점수를 입력하세요 : \n";
	cin >> std->name >> std->kor >> std->eng >> std->math;

	//개인 평균을 계산한다.
	std->ave = float(std->kor + std->eng + std->math) / 3.0f;

	//기존 값을 사용해서 새로운 전체 평균을 계산한다.
	const int current = NumberOfStudent + 1; //현재까지 입력받은 학생 수
	const int prev = NumberOfStudent; //조금 전까지 입력받은 학생 수 

	TotalAve = (TotalAve * prev / current) + (std->ave / current);

	//입력받은 학생 수를 증가시킨다.
	NumberOfStudent++;

	//students리스트에 새 노드를 추가
	InsertNodeAfter(GetTail(students), std);
	return true;
}

//전체 성적을 보여주는 함수
void ShowAll()
{
	//실수 출력 시에 소수점 이하 2자리까지 표시
	cout.precision(2);
	cout << fixed;

	//타이틀 출력
	cout << "\n               <전체 성적 보기>";
	cout << "\n   학번    이름    국어    영어    수학    평균\n";

	//리스트에 있는 모든 학생들의 정보를 출력한다.
	Node* current = students->head->next;
	while (current != students->head)
	{
		//현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)GetData(current);

		//해당 학생의 정보를 출력한다.
		cout << setw(7) << std->sNo << setw(7) << std->name;
		cout << setw(5) << std->kor << setw(5) << std->eng;
		cout << setw(5) << std->math << setw(7) << std->ave << endl;
		
		//다음 노드를 가리킨다.
		current = GetNext(current);
	}
	

	//전체 평균을 출력
	cout << "\n전체 평균 = " << TotalAve << endl;
}

//초기화
void Setup()
{
	//리스트를 생성한다
	students = CreateList();
}

//사용한 리소스를 정리
void Teardown()
{
	//리스트를 정리
	RemoveList(stuents, true)
}