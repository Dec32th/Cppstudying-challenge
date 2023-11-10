//Practice 6 #7 Mathmatics Average 


//7번 문제 - EOF입력이 들어오기 전까지 값들을 입력받고 그 값을 이용해서 산술, 기하, 조화 평균을 구하시오.

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //변수 선언 입력 받을 수들은 dNum, 입력 받는 수를 이용해서 평균, 값들을 구할 변수들 지정
    //산술, 기하, 조화 평균의 입력값 0으로 선언 및 초기화

    double dNum = 0;     //입력 변수.

    double dSum = 0;     //산술평균 계산 중간값

    double dMul = 1;     //기하평균 계산 중간값

    double dRevSum = 0;  //조화평균 계산 중간값

    double dAmean = 0;   //산술 평균 변수

    double dGmean = 0;   //기하 평균 변수

    double dHarmean = 0; //조화 평균 변수

    int iCount = 0;      //개수를 세는 변수

    
    

    //do - while문을 이용해서 먼저 1번 입력받고 판단. EOF입력 시 중단.
    do
    {

        cout << "0이상의 실수를 입력해주세요 : ";
        cin >> dNum;

        //if문을 이용해서 EOF가 입력되었는지 판단.
        if (cin.eof())
        {
            break;
        }

        //산술, 기하, 조화평균을 계산.
        dSum += dNum;
        cout << "dSum  = " << dSum << endl;
        dMul *= dNum;
        cout << "dMul  = " << dMul << endl;
        dRevSum += 1. / dNum;
        iCount++;
    } while (!cin.eof());

    dAmean = dSum / iCount;
    dGmean = pow(dMul, 1. / iCount);
    dHarmean = 1. / dRevSum;

    //산술, 기하, 조화 평균 출력.

    cout << "dAmean의 값: " << dAmean << endl;
    cout << "dGmean의 값: " << dGmean << endl;
    cout << "dHarmean의 값: " << dHarmean << endl;
}