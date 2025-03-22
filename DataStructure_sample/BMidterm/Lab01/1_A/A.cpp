#include<iostream>
#include<array>

using namespace std;

//array에서 찾고, sizeOfArray가 배열의 크기, value값을 찾고 없을 경우에는 -1
int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int First = 0;
	int Last = sizeOfArray - 1;

	while (First <= Last)
	{
		midPoint = (First + Last) / 2;

		if (array[midPoint] == value)
			return midPoint;

		else if (array[midPoint] < value)
		{
			First = midPoint + 1;
		}
		else
			Last = midPoint - 1;
	}

	return -1;
}