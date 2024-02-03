#pragma once

//Point class¡§¿«
class Point
{
public:
	enum
	{
		MIN_X = 0, MAX_X = 100, MIN_Y = 0, MAX_Y = 100
	};
	//memeber function
	void Print() const;

	//constructors
	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);

	//Accessor
	void SetX(int value);
	void SetY(int value);
	int GetX() const { return x; }
	int GetY() const { return y; }

private:
	//memeber variable
	int x, y;
};

//Accessor
inline void Point::SetX(int value)
{
	if (value < MIN_X) x = MIN_X;
	else if (value > MAX_X) x = MAX_X;
	else x = value;
}

inline void Point::SetY(int value)
{
	if (value < MIN_Y) y = MIN_Y;
	else if (value > MAX_Y) y = MAX_Y;
	else y = value;
}