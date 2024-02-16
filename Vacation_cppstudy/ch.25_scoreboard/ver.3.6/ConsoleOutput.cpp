#include<iostream>
#include"BaseOutput.h"
#include"ConsoleOutput.h"
#include<string>
#include<iomanip>



// 표의 헤더를 출력한다
// headers: 헤더들
// numbers: 헤더의 개수
void ConsoleOutput::PutHeader(string headers[], int number)
{
	//헤더의 개수를 보관한다
	columns = number;

	//헤더를 그려준다.
	for (int i = 0; i < number; ++i)
		cout << setw(9) << headers[i];
	
	cout << endl;
}

//표의 레코드를 출력한다
//record : 레코드. 한사람의 데이터를 의미한다
void ConsoleOutput::PutRecord(string record[])
{
	//레코드를 출력한다
	for (int i = 0; i < columns; ++i)
		cout << setw(9) << record[i];

	cout << endl;
}

void ConsoleOutput::EndTable()
{
	//하는 일 없음. 그냥 한 칸 띄워준다
	StdOut() << "\n";
}

void ConsoleOutput::Write(STR text)
{
	StdOut() << text << "\n";
}

ostream& ConsoleOutput::StdOut()
{
	return cout;
}

ConsoleOutput::ConsoleOutput()
{
	columns = 0;
}

ConsoleOutput::~ConsoleOutput()
{

}

void ConsoleOutput::BeginTable(STR title)
{
	//제목을 출력한다
	StdOut() << "\t\t\t\t" << title << "\n";
}