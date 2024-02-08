#pragma once

//동적 배열 클래스
class DynamicArray
{
public:
	//constructor, destructor
	DynamicArray(int arraySize);
	~DynamicArray();

	//accessor
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;

protected:
	int* arr;		//할당한 메모리 보관
	int size;		//배열의 길이 보관
};