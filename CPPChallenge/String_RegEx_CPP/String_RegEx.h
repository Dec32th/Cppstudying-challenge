#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<utility>
#include<iomanip>
#include<regex>
#include<stdexcept>
using namespace std;

// #23 바이너리 데이터를 문자열로 변환하기
// 문자 -> 숫자 -> 16진수의 변환이 가능하다. 즉, 16진수 -> 숫자 -> 문자의 형태가 필요
// 숫자 입력의 경우에는 바로 16진수로 변환해서 합친 후 문자열을 반환한다. 
// 16으로 변환한 것을 다시 string으로 만드는 것이 필요하다. 
// parameter는 vector

pair<string, string> binary_to_string(vector<int> v1);


// #24 문자열을 바이너리 데이터로 변환하기
// 16진수 문자열을 역직렬화 하고 결과로 8비트 정수들의 벡터를 변환
// 23번의 역과정, 2글자씩 잘라서 16진수로 변환
// 1. 문자열이 된 것을 숫자로 -> stoi 함수등
// 2. 숫자를 다시 16진수로 바꿔서 하나씩 넣어야한다.

vector<int> string_to_Binary(string st);


// #25 문자열을 제목 형식으로 바꾸기
// 공백 기준으로 공백 이후에 나오는 글자는 대문자. 문자열의 첫 글자는 대문자로 출력
// 출력은 그냥 16진수
// ex. the c++ challenge -> The C++ Challenge 변환
string to_title(string str1);

// #26
string make_sentence(vector<string> v1 = {});

// #27
vector<string> break_sentence(string str1);

// #28
pair<int, int> string_expand(int left, int right, const string& str);
string find_palindrome(string str);

// #29 
bool car_checker(const string& str);

// #30 
class URLParts
{
public:
    string sProtocol;
    string sDomain;
    string sPort;
    string sPath;
    string sQuery;
    vector<pair<string, string>> sParameter; // key=value 저장
    string sFragment;

    // URL 분석 함수 선언 (정의는 cpp에서)
    static URLParts parse(const string& url);

   

};

// #31

// 날짜가 제대로 되었는지 a반환하는 함수
class DateConverter {
public:
    static string convertDateFormat(const string& text);
private:
    static bool isValidDate(int day, int month, int year);
};
