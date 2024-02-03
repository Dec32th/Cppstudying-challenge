#include<iostream>
#include"Rect.h"
using namespace std;

Rect::Rect()
{
}

void Rect::SetTopLeft(const Point& topLeft)
{
	_topLeft = topLeft;
}

void Rect::SetBottomRight(const Point& bottomRight)
{
	_bottomRight = bottomRight;
}

void Rect::SetRect(int left, int top, int right, int bottom)
{
	_topLeft.SetX(left);
	_topLeft.SetY(top);
	_bottomRight.SetX(right);
	_bottomRight.SetY(bottom);
}

Point Rect::GetTopLeft() const
{
	return _topLeft;
}

Point Rect::GetBottomRight() const
{
	return _bottomRight;
}

void Rect::GetRect(int& left, int& top, int& right, int& bottom)
{
	left = _topLeft.GetX();
	top = _topLeft.GetY();
	right = _bottomRight.GetX();
	bottom = _bottomRight.GetY();
	bottom = _bottomRight.GetY();
}

//넓이 계산
int Rect::GetWidth() const
{
	return(_bottomRight.GetX() - _topLeft.GetX() + 1);
}

//높이 계산
int Rect::GetHeight() const
{
	return (_bottomRight.GetY() - _topLeft.GetY() + 1);
}

//내용 출력
void Rect::Print() const
{
	cout << " (L = " << _topLeft.GetX() << ", T = " << _topLeft.GetY();
	cout << " ,R = " << _bottomRight.GetX() << ", B = " << _bottomRight.GetY() <<")" << endl;

}