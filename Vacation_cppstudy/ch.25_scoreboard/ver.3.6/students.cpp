#include"students.h"
#include"student.h"
#include"BaseOutput.h"
#include"ConsoleOutput.h"
#include"HTMLOutput.h"
#include"TextOutput.h"
#include<sstream>
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
	Student* std = NULL;
	try
	{
		//학생의 종류에 맞는 객체를 생성한다
		if (general)
			std = new Student(NumberOfStudent + 1);
		else
			std = new EngStudent(NumberOfStudent + 1);

		//개인 정보를 입력받는다
		std->Input();

		//기존 값을 사용해서 새로운 전체 평균을 계산
		const int current = NumberOfStudent + 1;		//현재까지 입력받은 학생 수
		const int prev = NumberOfStudent;				//조금 전까지 입력 받은 학생 수

		TotalAve = (TotalAve * prev / current) + (std->GetAverage() / current);

		//입력 받은 학생 수를 증가시킨다
		NumberOfStudent++;

		//students 리스트에 새 노드를 추가한다
		students.InsertNodeAfter(students.GetTail(), std);
	}
	catch (...)
	{
		delete std;
		std = NULL;

		throw;
	}
	//if (general)
	//	std = new Student(NumberOfStudent + 1);
	//else
	//	std = new EngStudent(NumberOfStudent + 1);

	////개인 정보를 입력 받는다.
	//std -> Input();

	////기존 값을 사용하여 새로운 전체 평균을 계산한다.
	//const int current = NumberOfStudent + 1;
	//const int prev = NumberOfStudent;
	//
	//TotalAve = (TotalAve * prev / current) + (std->GetAverage());

	////입력 받은 학생 수를 증가시킨다
	//NumberOfStudent++;

	////Students 리스트에 새 노드를 증가시킨다
	//students.InsertNodeAfter(students.GetTail(), std);

	//return true;
}



//링크드 리스트의 데이터 제거용 함수
//링크드 리스트가 노드의 데이터를 제거할 때 이 함수를 호출
void Students::DeleteData(void* data)
{
	//Student 구조체를 바꿔서 제거한다.
	delete (Student*)data;
}

void Students::ShowAll(FORMAT fmt)
{
	//예외를 대비해서 스마트 포인터 사용
	// (소스를 간결하게 하기 위해서 타입을 새로 정의)
	typedef auto_ptr<BaseOutput> POUT;
	POUT out;

	//출력 형식에 맞는 객체를 생성한다.
	if (TEXTFILE == fmt)
		out = (POUT) new TextOutput(DEFAULT_TEXT_FILENAME);
	else if (HTMLFILE == fmt)
		out = (POUT) new HTMLOutput(DEFAULT_TEXT_FILENAME);
	else
		out = (POUT) new ConsoleOutput;

	//성적표의 출력을 시작한다
	out->BeginTable("< 전체 성적 보기 >");

	//header 부분 출력
	string header[7] = { "학번", "이름", "국어", "영어", "수학", "고급영어", "평균" };
	out->PutHeader(header, 7);

	//리스트에 있는 모든 학생의 정보를 출력한다.
	Node* current = students.GetHead()->GetNext();
	while (current != students.GetHead())
	{
		//현재 노드의 데이터를 꺼내온다.
		const Student* std = (Student*)current->GetData();

		//개인 성적 정보를 출력한다
		//출력 객체를 인자로 넘긴다
		std->Show(*out);

		//다음 노드를 가리킨다.
		current = current->GetNext();
	}

	//성적표의 출력을 마친다
	out->EndTable();

	//전체 평균 정보를 하나의 문자열로 만든다
	stringstream ss;
		ss.precision(2);
		ss << fixed;
		ss << "전체 평균 = " << TotalAve;

		//출력 객체에 문자열을 보낸다
		out->Wrtie(ss.str());

		//출력 객체를 제거한다
		delete out;
		out = NULL;

}