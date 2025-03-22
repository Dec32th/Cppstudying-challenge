#pragma once
#include"ItemType.h"

//exception handling
class FullStack
{};

class EmptyStack
{};

class DoubleStack
{
public:
	DoubleStack();

	bool IsEmpty();
	//비어있는지 아닌지 확인

	bool IsFull();
	// flag1과 flag2의 값이 연속되어있으면 IsFull

	void Push(int item);
	//item의 값에 따라서 넣는 위치가 달라진다.
	//1. IsFull 판별,
	//2. item의 값 판별 (1000이하, 초과)

	void Print();
private:
	int flag1;
	int flag2;
	int items[MAX_ITEMS];
};