#include<iostream>
#include<array>
#include"Item.h"

using namespace std;

//array에서 찾고, sizeOfArray가 배열의 크기, value값을 찾고 없을 경우에는 -1
int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int First = 0;
	int Last = sizeOfArray - 1;
	

	bool bChecker = false;

	while (First != Last && bChecker)
	{
		midPoint = (First + Last)/2;
		switch (1)
		{
			
		}
	}
	return 0;
}