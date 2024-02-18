#pragma once
class A
{
public:
	virtual void Func() {}
};

class B : public A
{
};

class C : public B
{
};