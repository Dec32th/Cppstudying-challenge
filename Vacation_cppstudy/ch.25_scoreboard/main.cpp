#include<iostream>
#include"student.h"
#include"students.h"
#include"menu.h"
using namespace std;

int main()
{
	// 프로그램이 종료할 때까지 메뉴를 보여주고
	while (1)
	{
		//메뉴를 보여준다
		MENU select;
		select = ShowMenu();

		//선택한 값에 따라서 처리
		switch (select)
		{
		case MENU_ADD_STUDENT:
		case MENU_ADD_STUDENT_ENG:
		//학생 성적 추가
		{
			// 일반 학생이라면 true를 인자로 넘긴다
			bool succeeded;
			succeeded = s.AddStudent((MENU_ADD_STUDENT==select ? true : false));

			//결과를 알린다
			if (succeeded)
				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
			else
				cout << "\n더이상 입력할 수 없습니다.\n";
			break;
		}
		case MENU_SHOW_ALL:
			//전체 성적 보기
		{
			//전체 성적 보기 함수를 호출한다
			ShowAll();

			break;
		}
		case MENU_QUIT:
			//종료
			cout << "\n프로그램을 종료합니다." << endl;
		}
	}
	
	//선택한 값에 따라서 처리
		
}