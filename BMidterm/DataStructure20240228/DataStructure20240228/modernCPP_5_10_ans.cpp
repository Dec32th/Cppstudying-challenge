#include<iostream>
#include<numeric>

using namespace std;

unsigned long long Multiple3or5(int iLimit)
{
	unsigned long long lTotal = 0;
	if (iLimit < 3)
	{
		cout << "There are no numbers in that range." << endl;
	}
	else
	{
		for (unsigned int i = 3; i < iLimit; i++)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				lTotal += i;
			}
		}
	}
	return lTotal;
}

unsigned int iGcd(unsigned int iNum1, unsigned int iNum2)
{
	return iNum2 == 0 ? iNum1 : iGcd(iNum2, iNum1 % iNum2);
}

unsigned int iLcm(int const a, int const b)
{
	int h = gcd(a, b);
	return h ? (a * (b / h)) : 0;
}

template <class InputIt>
int ilcm(InputIt first, InputIt end)
{
	return std::accumulate(first, last, 1, lcm);
}

bool is_prime(int const num)
{
	if (num <= 3)
		return num > 1;
	else if (num % 2 == 0 || num % 3 == 0)
		return false;
	else
	{
		for (int i = 5; i * i <= num; i += 6)
		{
			if (num % i == 0 || num % (i + 2) == 0)
				return false;
		}
		return true;
	}
}

int iSexyPrime(int iLimit)
{
	for (int n = 2; n <= iLimit; n++)
	{
		if (is_prime(n) && is_prime(n + 6))
		{
			cout << n << ", " << n + 6 << endl;
		}
	}
}