#include<iostream>
#include"BinarySearch.h"

int main()
{
	int array1[] = { 2,4,5,6,8,9,10 };
	int value1 = BinarySearch(array1, 7, 8);
	int value2 = BinarySearch(array1, 7, 3);
	int value3 = BinarySearch2(array1, 7, 8);
	int value4 = BinarySearch2(array1, 7, 7);
	int value5 = BinarySearch3(array1, 7, 6);
	int value6 = BinarySearch3(array1, 7, 7);
	cout << value1 << endl;
	cout << value2 << endl;
	cout << value3 << endl;
	cout << value4 << endl;
	cout << value5 << endl;
	cout << value6 << endl;
}