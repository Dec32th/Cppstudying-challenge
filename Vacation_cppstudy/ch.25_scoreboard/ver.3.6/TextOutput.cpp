#include"TextOutput.h"
#include"MyException.h"

//생성자
TextOutput::TextOutput(STR filename)
{
	//파일을 생성한다
	fout.open(filename.c_str());

	//파일을 여는데 실패한 경우 예외를 던진다
	if (false == fout.is_open())
		throw MyException(filename + "을 열 수 없습니다.");
}

//소멸자
TextOutput::~TextOutput()
{
	//파일을 닫는다
	fout.close();
}

//ostream 객체를 반환한다. 
// 반환 값: ostream 객체인 fout을 반환한다.
ostream& TextOutput::StdOut()
{
	return fout;
}