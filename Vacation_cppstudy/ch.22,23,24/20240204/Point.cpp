#include"Point.h"
#include<iostream>

using namespace std;


Point::Point(const Point& pt)
{
	x = pt.x;
	y = pt.y;
}

Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

Point::Point()
{
	x = 0;
	y = 0;
}

void Point::Print() const
{
	cout << "( " << x << ", " << y << " )" << endl;
}