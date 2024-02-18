#include<iostream>
#include"complex.h"
#include"a.h"
using namespace std;


ostream& operator<<(ostream& os, const Complex right)
{
	os << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return os;
}

int main()
{
	Complex c1(10, 5);

	int i = 5;
	c1 = i;
	c1 = Complex(i);


	c1 = c1 + 1;
	c1 = c1 + Complex(i);
	cout << c1 << endl;
}