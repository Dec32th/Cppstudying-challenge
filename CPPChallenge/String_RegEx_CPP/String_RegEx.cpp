#include"String_RegEx.h"

// #23 바이너리 데이터를 문자열로 변환하기
// 문자 -> 숫자 -> 16진수의 변환이 가능하다. 즉, 16진수 -> 숫자 -> 문자의 형태가 필요
// 숫자 입력의 경우에는 바로 16진수로 변환해서 합친 후 문자열을 반환한다. 
// 16으로 변환한 것을 다시 string으로 만드는 것이 필요하다. 
// parameter는 vector
pair<string, string> binary_to_string(vector<int> v1)
{
	string str1;
	string str2;

	//기본형 소문자
	for (int num : v1)
	{
		stringstream ss;
		ss << setw(2) << setfill('0') << hex << nouppercase << num;
		str1 += ss.str();
	}

	// 변형 대문자
	for (int i = 0; i < str1.size(); i++)
	{
		str2 += toupper(str1[i]);
	}
	return make_pair(str1, str2);
}

// #24 역직렬화과정
// 만약에 01, 02, 06 같은 경우에는 그냥 10진법으로 
// 자릿수는 최대 2자리로 정하기
vector<int> string_to_Binary(string st)
{
	vector<int> v1;
	for (int i = 0; i < st.size(); i+=2)
	{
		//변환해서 vector의 넣기 전 숫자로 변형하는 걸 임시로 저장
		int temp;
		
		// 2개씩 자른 값을 저장할 string변수
		string tempstr = st.substr(i, 2);

		stringstream ss;
		ss << hex << tempstr;
		ss >> temp;
		v1.push_back(temp);
	}
	
	return v1;
}

// #25 문자열을 제목 형식으로 바꾸는 함수 만들기
// ex. the c++ challenger -> The C++ Challenger
string to_title(string str1)
{
	//반환할 string
	string resultStr = "";
	
	//첫 글자는 대문자로 저장
	resultStr += toupper(str1[0]);

	//처음은 대문자 이므로 검사할 필요 없음.
	for (int i = 1; i<str1.size(); i++)
	{
		//바로 앞의 문자열이 공백인 경우 대문자로 저장하기
		if (str1[i - 1] == ' ')
		{
			resultStr += toupper(str1[i]);
		}
		else
			resultStr += str1[i];
	}
	return resultStr;
}

// #26
// 구획 문자로 나누어진 문자열 합치기
// 입력받은 vector의 원소들과, 구분자를 합쳐서 하나의 문자열로 만들기.
// 단, 입력 문자열이 없으면 빈 문자열 + 구분자는 맨 마지막에는 나오지 않아야함.

string make_sentence(vector<string> v1)
{
	// 구분자 문자열 출력
	string sChecker = " ";
	//결과를 출력할 문자열
	string sResult = "";

	//입력받은 문자열 벡터 -> 순환하면서 뒤에 구분자를 붙임
	//마지막에는 붙이지 않는다.
	for (int i = 0; i < v1.size(); i++)
	{
		sResult += v1[i];
		if(i < v1.size()-1)
			sResult += sChecker;
	}
	return sResult;
}

//#27 구획 문자 리스트를 바탕으로 문자열을 토큰으로 분리해서 vector로 반환
// 문자열 1개를 입력으로 받고, 구획 문자는 , . ! 그리고 공백
vector<string> break_sentence(string str1)
{
	regex delimiter("[,\\.\\! ]+");
	vector<string> v1;
	sregex_token_iterator it(str1.begin(), str1.end(), delimiter, -1);
	sregex_token_iterator end;

	while (it != end)
	{
		v1.push_back(*it++);
	}
	return v1;
}