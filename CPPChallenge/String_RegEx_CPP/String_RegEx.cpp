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

// #28 가장 긴 회문 부분 문장열 출력하기 
// 1. 입력 받은 문자여레서 가장 긴 회문을 찾아 반환하는 함수
// 2. 회문의 길이가 같은게 여러개 있다면, 첫 번째로 찾은 결과를 반환.
// 3. 문자열을 입력 받으면 띄어쓰기 없고 일부만 잘라서 회문이 되면 됨. 전부 다 회문이 될 필요도 없고 글자도 될 필요가 없음. 
pair<int, int> string_expand(int left, int right, const string& str)
{
	while (left >= 0 && right < str.size() && str[left] == str[right])
	{
		left--;
		right++;
	}
	return make_pair(left+1, right-1);
}

string find_palindrome(string str)
{
	//실제 회문 문자열의 크기 저장
	//회문 문자열이 없을 경우 첫 글자가 회문으로 취급.
	if (str.empty())
		return "";

	int iStringLen = 1;

	//회문 문자열 저장
	// 없을 경우 첫 글자가 회문으로 저장
	string sStr = str.substr(0,1);

	// 홀수인 경우
	for (int i = 0; i < str.size(); i++)
	{
		pair<int, int> p1 = string_expand(i, i, str);

		if ((p1.second - p1.first +1) > iStringLen)
		{
			iStringLen = p1.second - p1.first +1;
			sStr = str.substr(p1.first, iStringLen);
		}

		//짝수인 경우
		if (i + 1 < str.size() && str[i] == str[i + 1])
		{
			pair<int, int> p1 = string_expand(i, i + 1, str);
			if ((p1.second - p1.first + 1) > iStringLen)
			{
				iStringLen = p1.second - p1.first + 1;
				sStr = str.substr(p1.first, iStringLen);
			}
		}
	}

	return sStr;
}

// #29 차량 번호판 검증하기 
// LLL - LL DDD or LLL - LL DDDD (L은 A부터 Z까지의 대문자, D는 숫자) 자동차 번호판
bool car_checker(const string& str)
{
	regex pattern(R"([A-Z]{3} - [A-Z]{2}\s[0-9]{3,4})");
	
	if (regex_match(str, pattern))
		return true;
	return false;
}




// #30 URL 추출하기
// url을 나타내는 문자열이 주어진 경우에, URL의 각 부분을 분석하고 추출하는 함수
// protocol, domain, port, 경로, 쿼리, prament를 분석하고 추출하는 함수를 작성

vector<pair<string, string>> parseQueryParameters(const string& query)
{
	vector<pair<string, string>> parameters;
	stringstream ss(query);
	string params;

	while (getline(ss, params, '&'))
	{
		size_t equalPos = params.find('=');
		if (equalPos != string::npos)
		{
			parameters.emplace_back(params.substr(0, equalPos), params.substr(equalPos + 1));
		}
	}
	return parameters;
}

URLParts URLParts::parse(const string& url)
{
	URLParts parts;
	regex pattern(R"(^([a-zA-Z]+):\/\/([^\/:]+)(?::(\d+))?(\/[^?#]*)?(?:\?([^#]*))?(?:#(.*))?$)");
	smatch matches;

	if (regex_match(url, matches, pattern))
	{
		parts.sProtocol = matches[1].str();
		parts.sDomain = matches[2].str();
		parts.sPort = matches[3].matched ? matches[3].str() : "";
		parts.sPath = matches[4].matched ? matches[4].str() : "/";
		parts.sQuery = matches[5].matched ? matches[5].str() : "";

		// 파라미터 분석
		stringstream ss(parts.sQuery);
		string param;
		while (getline(ss, param, '&'))
		{
			size_t equalPos = param.find('=');
			if (equalPos != string::npos)
				parts.sParameter.emplace_back(param.substr(0, equalPos), param.substr(equalPos + 1));
		}

		parts.sFragment = matches[6].matched ? matches[6].str() : "";
	}
	return parts;
}


// #31 날짜를 문자열로 변환하기
// dd.mm.yyyy or dd-mm-yyyy형식의 날짜가 포함된 텍스트가 주어진 경우, yyyy-mm-dd형식으로 변환하는 함수작성
bool DateConverter::isValidDate(int day, int month, int year) {
	if (month < 1 || month > 12 || day < 1) return false;
	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// 윤년 확인
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		daysInMonth[1] = 29;
	}

	return day <= daysInMonth[month - 1];
}

std::string DateConverter::convertDateFormat(const std::string& text) {
	std::regex date_pattern(R"((\d{2})[.-](\d{2})[.-](\d{4}))");
	std::smatch match;
	std::string result = text;

	std::string::const_iterator search_start(text.cbegin());
	while (std::regex_search(search_start, text.cend(), match, date_pattern)) {
		int day = std::stoi(match[1]);
		int month = std::stoi(match[2]);
		int year = std::stoi(match[3]);

		if (!isValidDate(day, month, year)) {
			throw std::invalid_argument("Invalid date: " + match.str());
		}

		std::string formatted_date = match[3].str() + "-" + match[2].str() + "-" + match[1].str();
		result.replace(match.position(), match.length(), formatted_date);
		search_start = match.suffix().first;
	}
	return result;
}
