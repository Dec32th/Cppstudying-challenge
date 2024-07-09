#pragma once
#include<iostream>
using namespace std;

int BinarySearch(int array[], int sizeOfArray, int value)
{
	int iFirst = 0;
	int iLast = sizeOfArray - 1;
	int iMidPoint;

	while ( iFirst <= iLast)
	{
		iMidPoint = (iFirst + iLast) / 2;

		if (array[iMidPoint] == value)
		{
			return iMidPoint;
		}
		else if (array[iMidPoint] > value)
		{
			iLast = iMidPoint - 1;
		}
		else
		{
			iFirst = iMidPoint+1;
		}
	}
	return -1;

}

int BinarySearch2(int array[], int sizeOfArray, int value)
{
	int iFirst = 0;
	int iLast = sizeOfArray - 1;
	int iMidPoint;

	while (iFirst <= iLast)
	{
		iMidPoint = (iFirst + iLast) / 2;

		if (array[iMidPoint] == value)
		{
			return array[iMidPoint];
		}
		else if (array[iMidPoint] > value)
		{
			iLast = iMidPoint - 1;
		}
		else
		{
			iFirst = iMidPoint + 1;
		}
	}
	return array[iFirst-1];

}

int BinarySearch3(int array[], int sizeOfArray, int value)
{
	int iFirst = 0;
	int iLast = sizeOfArray - 1;
	int iMidPoint;

	while (iFirst <= iLast)
	{
		iMidPoint = (iFirst + iLast) / 2;

		if (array[iMidPoint] == value)
		{
			return array[iMidPoint];
		}
		else if (array[iMidPoint] > value)
		{
			iLast = iMidPoint - 1;
		}
		else
		{
			iFirst = iMidPoint + 1;
		}
	}
	return array[iMidPoint];

}