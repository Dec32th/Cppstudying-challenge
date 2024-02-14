#include"BaseOutput.h"
#include"HTMLOutput.h"
#include<iostream>
#include<iomanip>
using namespace std;

//생성자
//filename : HTML 파일 이름
HTMLOutput::HTMLOutput(STR filename)
{
	columns = 0;
	
	//파일을 열고 기본 태그를 추가한다
	fout.open(filename.c_str());

	fout << "<html><head><title>IT 백두대간 C++ 프로젝트</title></head></html><center>";
}

void HTMLOutput::BeginTable(STR title)
{
	//타이틀을 출력한다
	fout << "<h3>" << title << "</h3>";

	//테이블 시작 태그를 넣는다
	fout <<"<table bgcolor = 'slategray' cellspacing = '1' cellpadding ='4' border = '0'>";
}

//표의 레코드를 출력한다
//record : 레코드. 한 사람의 데이터를 의미한다
void HTMLOutput::PutRecord(string record[])
{
	//태그와 함께 레코드를 삽입한다
	//레코드를 출력한다
	fout << "<TR bgcolor = 'white' align = 'right'>";
	for (int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}