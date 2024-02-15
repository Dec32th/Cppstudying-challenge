#include<iostream>
#include<exception>
#include"students.h"
#include"BaseOutput.h"
#include"menu.h"
#include"list.h"
using namespace std;

int main()
{
	Students s;
	// 프로그램이 종료할 때까지 메뉴를 보여주고
	while (1)
	{
		try
		{
			//메뉴를 보여준다
			MENU select;
			select = ShowMenu();

			//선택된 값에 따라서 처리
			switch (select)
			{
				//메뉴를 보여준다
				MENU select;
				select = ShowMenu();

				//선택된 값에 따라 처리
				switch (select)
				{
				case MENU_ADD_STUDENT:
				case MENU_ADD_STUDENT_ENG:
					//학생 성적 추가
					{
						//학생 성적 추가 함수를 호출한다
						//(일반학생이라면 true를 인자로 넘긴다.)
						bool succeeded;
						succeeded = s.AddStudent((MENU_ADD_STUDENT == select ? true : false));

						//결과를 알린다.
						if (succeeded)
							cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
						else
							cout << "\n더 이상 입력할 수 없습니다.\n";
						break;
					}
				case MENU_SHOW_ALL:
					//전체 성적 보기
				{
					s.ShowAll(Students::CONSOLE);
					break;
				}
				case MENU_SAVE_TEXT:
					//텍스트 파일로 전체 성적 저장
				{
					//전체 성적 보기 함수를 호출한다
					s.ShowAll(Students::TEXTFILE);
					cout << "\n텍스트 파일이 저장되었습니다. \n";
					break;
					
				}
				case MENU_SAVE_HTML:
					//html파일로 전체 성적 저장
				{
					//전체 성적 보기 함수를 호출한다
					s.ShowAll(Students::HTMLFILE);
					
					cout << "\nHTML 파일이 저장되었습니다. \n";
				}
				case MENU_QUIT:
					//종료
				{
					//사용한 리소스를 정리해주지 않아도 된다.
					//Teardown();
					cout << "\n프로그램을 종료합니다\n";
				}

				}
			} 
		} //try의 끝
		catch (exception& e)
		{
			//예외 내용을 출력하고 계속 진행한다.
			cout << "\n[ 다음과 같은 문제가 발생했습니다 ]\n";
			cout << "=> " << e.what() << "\n\n";
		}
	}
	
	//선택한 값에 따라서 처리
		
}