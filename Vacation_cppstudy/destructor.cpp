#include<iostream>
using namespace std;

class DynamicArray
{
public:
	int* arr;

	DynamicArray(int arraySize)
	{
		//동적으로 메모리를 할당
		arr = new int[arraySize];
	}
	~DynamicArray() //소멸자. instance가 소멸하면서 호출되고 소멸
	{
		delete[] arr;
		arr = NULL;
	}
};
int main()
{
	//몇 개의 정수를 입력할 지 물어본다
	int size;
	cout << "몇 개의 정수를 입력하시겠습니까?";
	cin >> size;

	//필요한 만큼의 메모리를 준비
	DynamicArray da(size);

	

	//정수를 입력받는다
	for (int i = 0; i < size; ++i)
	{
		cin >> da.arr[i];
	}

	//역순으로 정수 출력
	for (int i = size - 1; i >= 0; --i)
	{
		cout << da.arr[i] << " ";
	}

	cout << endl;

	//따로 메모리 해제핯 필요 없음
}