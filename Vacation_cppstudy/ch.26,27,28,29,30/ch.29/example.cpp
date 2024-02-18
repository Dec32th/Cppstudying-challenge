#include<iostream>
using namespace std;

template <typename T>
class AutoArray
{
public:
	AutoArray(T* ptr)
	{
		_ptr = ptr;
	}

	~AutoArray()
	{
		delete[] _ptr;
	}

	T& operator[] (int index)
	{
		return _ptr[index];
	}

private:
	T* _ptr;
};

template<typename A, typename B, int MAX>
class TwoArray 
{
protected:
	A arr1[MAX];
	B arr2[MAX];
};

int main()
{
	AutoArray <float> arr(new float[100]);

	arr[0] = 99.99f;
}