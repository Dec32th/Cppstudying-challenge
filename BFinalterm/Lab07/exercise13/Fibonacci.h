#pragma once

int Fibonacci_recursive(int n)
{
	if (n <= 1 && n >= 0)
		return n;
	else
		return Fibonacci_recursive(n - 1) + Fibonacci_recursive(n - 2);
}


int Fibonacci_non_recursive(int n) 
{
	int iTotal = n>0 ? 1 : 0;
	int iFib0 = 0;
	int iFib1 = 1;
	

	for (int i = 2; i < n; i++)
	{
		iFib0 = iFib1;
		iFib1 = iTotal;
		iTotal = iFib0 + iFib1;
	}

	return iTotal;
}