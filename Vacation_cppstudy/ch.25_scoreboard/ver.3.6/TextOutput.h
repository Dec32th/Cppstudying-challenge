#pragma once

#include"ConsoleOutput.h"
#include<fstream>
using namespace std;

//텍스트파일 출력을 도와주는 함수
class TextOutput : public ConsoleOutput
{
public:
	TextOutput(STR filename);
	virtual ~TextOutput();

	//BaseOutput의 멤버 함수들을 따로 오버라이드할 필요는 없다

protected:
	virtual ostream& StdOut();
	ofstream fout;
};