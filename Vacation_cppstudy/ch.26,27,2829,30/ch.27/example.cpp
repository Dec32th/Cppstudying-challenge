#include<iostream>
#include"complex.h"
using namespace std;


Complex operator+(const Complex& left, const Complex& right)
{
	//실수부와 허수부를 각각 더한다
	int real = left.real + right.real;
	int imag = left.imaginary + right.imaginary;

	//결과를 보관한 복소수 객체를 반환한다.
	return Complex(real, imag);
}

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 0);

	//+연산자를 사용한 덧셈
	c3 = c1 + c2;
	c3 = operator+(c1, c2);

	cout << c3.Real() << endl;
	cout << c3.Imaginary() << endl;
}