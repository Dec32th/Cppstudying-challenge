#include<iostream>
#include<string>

using namespace std;

int  main()
{
	string text = "Napster's pay-to-play service is officially out, "
		"and we have a review of the now-legit Napster."
		"We also size up its companion music player from Samsung."; //문자열을 이렇게 쓰면 ;이 마침표 역할을 하기 때문에 여러 줄에 걸쳐서 쓸 수 있다!! 대신에 주석을 중간에 달 수는 없다. 
	cout << "Offset of 'official' = " << text.find("official") << endl;
}