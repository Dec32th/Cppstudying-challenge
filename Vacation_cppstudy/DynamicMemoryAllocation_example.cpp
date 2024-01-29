#include<iostream>
using namespace std;

char* ReverseString(const char* src, int len)
{
	char* reverse = new char[len + 1];
	
	for (int i = 0; i < len; i++)
	{
		reverse[i] = src[len - i - 1];
	}
	reverse[len] = NULL; //문자열이 끝났음을 알 수 있도록 맨 뒤에 NULL을 넣어준다.
	return reverse;
}

int main()
{
	char original[] = "NEMODORI";

	char* copy = ReverseString(original, 8);
	//copy는 할당된 메모리의 주소값을 저장한다.
	
	cout << original << endl;
	cout << copy << endl;

	delete[] copy; 
	//함수에서 reverse가 사용하지만, 그것은 함수 내의 변수이고, return된 reverse를 copy가 받아오기 때문에 copy의 메모리를 삭제해야한다.
	//함수는 끝났으나 동적으로 할당된 메모리는 여전히 살아있기 떄문에 가능.
	
	
	copy = NULL;

}