//선택 정렬 알고리즘 함수 coding - C++ 자료구조론(2nd Edition) p.22

#include<iostream>
#include<array>
using namespace std;


//크기가 n인 배열을 입력 받고 그 배열을 돌면서 a[i]의 값이 
//a[j]의 값보다 크면, a[j]와 a[i]의 값의 위치를 바꾼다.

void SelectionSort(int* a, const int n)
{
	//최초의 값을 입력 받을 임시변수 temp 선언
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; ++j)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				continue;
		}
	}
}



int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2, 1 };

	//sizeof는 배열의 크기를 구하고, 그 크기에 변수의 크기를 곱해서 배열이 차지하는 byte 수를 구한다.
	int arr_size = sizeof(arr)/4;

	SelectionSort(arr, arr_size);

	for (int i = 0; i < arr_size; ++i)
	{
		std::cout <<"arr[" << i <<"] = " << arr[i] << " ,";
	}
	std::cout << endl;
}