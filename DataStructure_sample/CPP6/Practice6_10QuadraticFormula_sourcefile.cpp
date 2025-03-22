//Practice6_#10 Quardratic formula

//10번 문제 - 근의 공식을 이용해서 이차방정식의 해를 구하는 프로그램을 작성하시오

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //2차방정식의 계수 - 변수 초기화 및 선언
    double a = 0;
    double b = 0;
    double c = 0;
    
    //2차방정식의 두 실근 및 1차방정식의 근 선언.
    double x1, x2;
    double x;

    //2차방정식의 계수인 a,b,c 변수 입력 받기
    cout << "Enter the number(a): ";
    cin >> a;
    cout << "Enter the number(b): ";
    cin >> b;
    cout << "Enter the number(c): ";
    cin >> c;
    
   //if문을 이용해서 Quardratic formula 게산

    //방정식이 아닌 경우.
    if (a == 0 && b == 0)
    {
        cout << "You enter the wrong number. Enter the right number.";
    }

    //2차 방정식이 아니라 1차방정식인 경우.
    else if (a == 0 && b != 0)
    {
        x = -c / b;
        cout << "x = " << x;
    }

    //2차 방정식의 근을 계산 - 허근일 경우.
    else if (b * b - 4 * a * c < 0)
    {
        cout << "There is not a real solution." << endl;
    }

    //2차 방정식의 근을 계산 - 서로 다른 두 실근일 경우& 중근일 경우
    else
    {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
        x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
}