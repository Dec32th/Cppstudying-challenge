#include<iostream>
#include<cmath>
using namespace std;

// #1
//�Է� ���� ���� �������� �ϴ� �� �߿��� 3,5�� ������ �������� ���� ���� ���ϴ� ���� �ۼ��ϱ�
unsigned int cal35total(int maximum_number)
{
	unsigned int result = 0;
	for (int i = 1; i <= maximum_number; i++)
	{
		if (i % 3 == 0 && i % 15 != 0)
		{
			result += i;
		}
		else if (i % 5 == 0 && i % 15 != 0)
		{
			result += i;
		}
	}
	return result;
}

// #2-1
// �ִ� ����� ���α׷� �����ϱ�(���ο��� ū �� ���� �� �Ǵ��ϱ� + ���� ���� ������ �ʴ´ٰ� ����)
// ��;��� ����
unsigned int cal_gcd(unsigned int iNum1, unsigned int iNum2)
{
	unsigned int result = 0;
	unsigned int a = 0;
	unsigned int b = 0;
	if (iNum1 > iNum2)
	{
		unsigned int a = iNum1;
		unsigned int b = iNum2;
	}
	else
	{
		unsigned int a = iNum2;
		unsigned int b = iNum1;
	}
	
	while (a % b != 0)
	{
		result = a % b;
		a = b;
		b = result;
		
	}
	
	return result;
}
// #2-2 ��ͷ� �� ����

unsigned int cal_gcd_r(unsigned int iNum1, unsigned int iNum2)
{
	return iNum2 == 0 ? iNum1 : cal_gcd_r(iNum2, iNum1 % iNum2);
}

// #3 �ּ� ����� ���ϴ� ���α׷�
unsigned int cal_lcm(int iCalnum)
{

}

// #4 
// �־��� ������ ���� ���� ū �Ҽ��� ����ϴ� ���α׷�

//#4-1 ���� bool�� �Ҽ����� �ƴ��� �Ǵ��ϴ� �Լ�
bool is_Prime(unsigned int iNum)
{
	if (iNum <= 1)
		return false;
	if (iNum <= 3)
		return true;
	if (iNum % 2 == 0 || iNum%3 ==0)
		return false;
	for (unsigned int i = 5; i * i <= iNum; i += 6)
	{
				if (iNum % i == 0)
					return false;
	}
	return true;
}

//#4-2. ���� �Լ��� �̿��ؼ� ���.
unsigned int prime_cal(unsigned int iNum)
{
	//2���� ���� �Ҽ��� �������� ����
	if (iNum <= 2)
		return 0;
	for (int i = iNum - 1; i >= 2; i--)
		{
			if (is_Prime(i))
				return i;
		}
	
}

// #5 ���üҼ� ��� ���α׷� - �� ���� ���� 6�� �Ҽ��� ���
// #4���� ����� �Ҽ� üũ ���α׷� ���
void sexy_Prime(unsigned iNum)
{
	//�Ҽ����� �Ǵ��ϰ� 6���� ���� �Ҽ����� ���.
	// 4-1 ���� ���� �Լ��� ���
	for (int i = 2; i <= iNum; i++)
	{
		if (is_Prime(i)&& is_Prime(i+6))
		{
			cout << "( " << i << ", " << i+6 << " )";
		}
	}
}

//#6 ���׼� ��� ���α׷� - �ڱ� �ڽ��� �� ������� ���� �ڽź��� ū ��, ������ �� ���Ѱ�-�� ��
