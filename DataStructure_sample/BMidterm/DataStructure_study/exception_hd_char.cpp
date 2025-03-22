#include<iostream>
#include<array>
using namespace std;

void ArrSum(int arr[], int arr1[], int arr2[], int arr3[], int k)
{
	//char 형 error 처리를 이용해서 exception handling
	char error0[] = "the number n is not conformed";

	if (k < 0)
	{
		throw error0;
	}
	else
		cout << arr[k] + arr1[k] + arr2[k] + arr3[k];
}


int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[10] = { 0,1,2,3,4,5,6,7,8 };
	int arr3[10] = { -1,0,1,2,3,4,5,6,7 };
	int arr4[10] = { -2,-1,0,1,2,3,4,5,6 };

	try
	{
		ArrSum(arr1, arr2, arr3, arr4, 0);
	}
	catch(char ex[])
	{
		cout << "The number 'k' is out of range. k is must be same or bigger than 0.";
	}
}