#pragma once
//복소수 클래스
class Complex
{
public:
	//constructor
	Complex(int realPart, int imaginaryPart)
		:real(realPart), imaginary(imaginaryPart)
	{}

	//accessor
	int Real(int realPart) { real - realPart; return real; }
	int Imaginary(int ImaginaryPart) { imaginary = ImaginaryPart; return imaginary; }

	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

	friend Complex operator+(const Complex& left, const Complex& right);

	//C++ 전치연산
	Complex operator++()
	{
		//실수부의 값을 먼저 더한다
		this->real++;

		//현재 값을 반환한다
		return *this;
	}

	//C++ 후치연산
	Complex operator++(int)
	{
		//현재 값을 먼저 보관한다
		Complex prev(this->real, this->imaginary);

		//실수부의 값을 더한다.
		this->real++;

		//보관한 값을 반환한다
		return prev;
	}

	//C++ 전치연산
	Complex operator--()
	{
		//실수부의 값을 먼저 감소
		this->real--;

		//현재 값을 반환
		return *this;
	}

	//C++ 후치연산
	Complex operator--(int)
	{
		//실수부의 값을 먼저 보관
		Complex prev(this->real, this->imaginary);

		//실수부의 값을 감소
		this->real--;

		//보관한 값을 반환
		return prev;


	}

private:
	int real;			//실수부
	int imaginary;		//허수부
};