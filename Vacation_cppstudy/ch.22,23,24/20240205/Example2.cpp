#include"HTMLWriter.h"
#include"DocWriter.h"

int main()
{
	//HTMLWriter 객체 생성
	HTMLWriter hw("test.html", "HTMLWriter Content");

	//DocWriter pointer로 객체를 가리킨다
	DocWriter* pDW = &hw;

	pDW->Write();
}