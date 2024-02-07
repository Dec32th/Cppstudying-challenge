#include"docwriter.h"
#include<fstream>
using namespace std;

DocWriter::DocWriter()
{
	//파일 이름과 텍스트를 default로 지정해둔다.
	_fileName = "NoName.txt";
	_content = "There is no content.";
}

DocWriter::DocWriter(const string& fileName, const string& content)
{
	_fileName = fileName;
	_content = content;
}
DocWriter::~DocWriter()
{
}

//파일 이름을 지정
void DocWriter::SetFileName(const string& fileName)
{
	_fileName = fileName;
}

//저장할 텍스트 지정
void DocWriter::SetContent(const string& content)
{
	_content = content;
}

//파일에 텍스트 저장
void DocWriter::Write()
{
	//파일을 연다
	ofstream of(_fileName.c_str());
	//간단한 헤더를 출력한다
	of << "# Content #\n\n";
	//텍스트를 있는 그대로 저장
	of << _content;
}