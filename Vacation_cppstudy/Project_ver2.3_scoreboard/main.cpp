#include<iostream>
#include"student.h"
#include"menu.h"
#include<iomanip>
#include<string>

using namespace std;




int main()
{
	//프로그램이 종료될 때까지 메뉴를 보여주고 작업 처리
	while (true)
	{

		//메뉴를 보여준다
		MENU select;
		select = ShowMenu();

		//선택한 값에 따라 처리
		switch (select)
		{
		case MENU_ADD_STUDENT:
			//학생 성적 추가
		{
			//학생 성적 추가 함수 call
			bool succeeded;
			succeeded = AddStudent();

			//결과를 알린다.
			if (succeeded)
			{
				cout << "\n학생 성적이 올바르게 입력되었습니다." << endl;
			}
			else
			{
				cout << "\n더 이상 입력할 수 없습니다.\n";
			}
			break;
		}
		case MENU_SHOW_ALL:
			//전체 성적 보기
		{
			//전체 성적 보기 함수 call
			ShowAll();
			break;
		}
		case MENU_QUIT:
		{
			//종료
			cout << "\n프로그램을 종료합니다.\n";
		}
		}
	}
}