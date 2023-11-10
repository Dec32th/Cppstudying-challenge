//Practice 7 #9 Range-Based for loop & vector Reverse & Random value generate

//실습 7 - 크기가 5인 [0,99]중 임의의 값을 저장하는 vector를 만들고, 그 값의 순서를 역순으로 바꾸는 Reverse함수를 정의하라.
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//범위기반 for문. vector의 원소에 접근, 그 값을 출력.
void print(const vector<int>& v)
{
    for (const auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

//벡터의 저장된 순서를 역순으로 바꾸어 주는 Reverse함수
vector<int> Reverse(vector<int> v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        int t = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = t;
    }
    return v;
}

int main()
{
    vector<int> v1;

    //[0,99]의 random한 값을 시간을 seed로 해서 만들고 그 값을 vector에 저장.
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(rand() % 100);
    }

    //Reverse function call
    vector<int> v2 = Reverse(v1);

    print(v1);
    print(v2);

}