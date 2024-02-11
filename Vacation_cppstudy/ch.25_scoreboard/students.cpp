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
bool Students::AddStudent(bool general)
{
	//링크드 리스트에 넣기 위해 Student 변수 하나를 동적으로 할당한다.
	Student* std = new Student(NumberOfStudent + 1);
	if (general)
		std = new Student(NumberOfStudent + 1);
	else
		std = new EngStudent(NumberOfStudent + 1);

	//개인 정보를 입력 받는다.
	std -> Input();

	//기존 값을 사용하여 새로운 전체 평균을 계산한다.
	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;
	
	TotalAve = (TotalAve * prev / current) + (std->GetAverage());

	//입력 받은 학생 수를 증가시킨다
	NumberOfStudent++;

	//Students 리스트에 새 노드를 증가시킨다
	students.InsertNodeAfter(students.GetTail(), std);

	return true;
}

//전체 성적을 보여준다
void Students::ShowAll()
{

	//실수 출력 시에 소수점 이하 두 자리만 표기
	cout.precision(2);
	cout << fixed;

	//타이틀 부분을 출력
	cout << "\n			< 전체 성적 보기 >";
	cout << "\n		학번	이름	국어 영어 수학	평균\n";

	//리스트에 있는 모든 학생의 정보를 출력한다
	Node* current = students.GetHead()->GetNext();
	while (current != students.GetHead())
	{
		//현재 노드의 데이터를 꺼내온다
		const Student* std = (Student*)current->GetData();

		//개인 성적표를 출력한다
		std->Show();

		//다음 노드를 가리킴
		current = current->GetNext();

	}

	//전체 평균을 출력한다
	cout << "\n전체 평균 = " << TotalAve << endl;

}

//링크드 리스트의 데이터 제거용 함수
//링크드 리스트가 노드의 데이터를 제거할 때 이 함수를 호출
void Students::DeleteData(void* data)
{
	//Student 구조체를 바꿔서 제거한다.
	delete (Student*)data;
}

