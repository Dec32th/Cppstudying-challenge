//Practice 7 #10 multidemensional vector print and Transpose function

//실습 7 - 다차원벡터에 [0,99]의 임의의 값을 저장하고, Transpose를 하는 함수를 정의하여라.
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//다차원 벡터 출력을 위한 print함수 - Range-based for문
void print(const vector<vector<int>> &v)
{
    for (const auto &x : v)
    {
        for (const auto& elem : x)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Transpose함수 - 행과 열을 바꾸어 준다.
vector<vector<int>> Transpose(vector<vector<int>> v)
{
    //열 - 2개 - 세로
    int iRow = v[0].size();
    //행 - 3개 - 가로
    int iColumn = v.size();
    vector<vector<int>> v1(iRow, vector<int>(iColumn, 0));

    for (int i = 0; i < iRow; i++)
    {
        for (int k = 0; k < iColumn; k++) 
        {
            v1[i][k] = v[k][i];
        }
    }
    
    return v1;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    vector<vector<int>> m1 = { {0,0},{0,0}, {0,0} };


    //[0 - 99] 수들 중 임의의 값 할당
    for (int i = 0; i < m1.size() ; i++)
    {
        for (int j = 0; j < m1[i].size(); j++)
        {
            m1[i][j] = rand() % 100;
        }

    }

    //Transpose함수를 이용해서 m2를 선언하고 초기화함
    vector<vector<int>> m2 = Transpose(m1);

    //m1,m2출력
    print(m1);
    print(m2);

}