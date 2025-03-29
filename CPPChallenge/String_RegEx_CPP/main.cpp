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
}
