#include<iostream>
using namespace std;

template<typename T>
struct NodeType
{
	T info;
	NodeType* next;
};

template <typename ItemType>
class UnsortedType
{
public:
private:
	NodeType<ItemType>* listPtr;
};