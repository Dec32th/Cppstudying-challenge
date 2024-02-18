#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	// 동적 배열을 생성해서 임의의 영문자를 추가
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	//sort()함수를 사용해서 정렬
	sort(vec.begin(), vec.end());

	//정렬 후 상태를 출력한다
	cout << "vector 정렬 후 \n";
	vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	//임의의 문자열을 넣어 만든 배열 정렬
	char arr[5] = { 'd', 'c', 'b', 'a', 'e'};

	//sort()함수를 사용해서 정렬
	sort(arr, arr + 5);

	//정렬 후 상태 출력
	for (char* p = arr; p != arr + 5; ++p)
		cout << *p;
	cout << endl;
}