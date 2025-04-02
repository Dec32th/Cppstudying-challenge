#include"String_RegEx.h"

int main()
{
	// #23 test
	vector<int> v0; 
	v0 = { 0xBA, 0xAD,0xF0,0x0D };
	pair<string, string> result = binary_to_string(v0);
	cout << result.first << " " << result.second;
	cout << endl;

	//#24 test
	vector<int> vec = string_to_Binary(result.first);
	for (int num : vec)
	{
		cout << "0x" << hex << uppercase<< num << " ";
	}
	cout << endl;

	string st1 = "010203040506";
	vector<int> v12 = string_to_Binary(st1);
	for (int num : v12)
	{
		cout << num << " ";
	}
	cout << endl;

	// #25 test
	string str1 = "the c++ challenger";
	string title_str1 = to_title(str1);
	cout << title_str1;
	cout << endl;

	// #26 test
	vector<string> vec12 = { "The", "C++", "Challenge" };
	vector<string> vec13 = {};
	string str12 = make_sentence(vec12);
	string str13 = make_sentence();
	cout << str12 << endl;
	cout << str13;

	// #27 test
	string sStr = "there!!!is,. an! Apple,, tree!";
	vector<string> v1;
	v1 = break_sentence(sStr);

	for (string str : v1)
	{
		cout << str << " ";
	}
	cout << endl;

	// #28 test
	string sStr1 = "help";
	string sStr2 = "sahararahnide";
	string sStr3 = "level";
	string sStr4 = "I";

	string sResult1 = find_palindrome(sStr1);
	string sResult2 = find_palindrome(sStr2);
	string sResult3 = find_palindrome(sStr3);
	string sResult4 = find_palindrome(sStr4);

	cout << sResult1 << " " << sResult2 << " " << sResult3 << " " << sResult4;
	cout << endl;


	// #29 test
	string sstring1 = "SSS - UW 352";
	string sstring2 = "QUS - FW 3528";
	string sstring3 = "QUSQ - FFW 128";

	cout << car_checker(sstring1) << " " << car_checker(sstring2) << " " << car_checker(sstring3);
	cout << endl;

	// #30 test
	string testURL = "https://example.com:8080/path?key=value&foo=bar#section";
	URLParts parts = URLParts::parse(testURL);

	cout << "Protocol: " << parts.sProtocol << endl;
	cout << "Domain: " << parts.sDomain << endl;
	cout << "Port: " << parts.sPort << endl;
	cout << "Path: " << parts.sPath << endl;
	cout << "Fragment: " << parts.sFragment << endl;

	cout << "Parameters:\n";
	for (const auto& param : parts.sParameter)
	{
		cout << "  " << param.first << " = " << param.second << endl;
	}

	// #31 test
	vector<std::string> test_cases = {
		"오늘은 31.02.2025입니다.",
		"유효한 날짜: 15-08-2023",
		"테스트: 29.02.2024 (윤년)",
		"잘못된 날짜: 30-02-2021",
		"또 다른 테스트: 31-04-2022"
	};

	for (const auto& text : test_cases) {
		try {
			std::string result = DateConverter::convertDateFormat(text);
			std::cout << "변환된 문자열: " << result << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "오류 발생: " << e.what() << std::endl;
		}
	}

}
