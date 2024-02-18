#include<iostream>
#include"complex.h"
#include"a.h"
using namespace std;
//港港捞 包访 巴甸
namespace Dog
{
	//港港捞 茄 付府 沥焊
	struct Info
	{
		char name[20];
		int age;
	};

	Info dogs[20];		// 港港捞 府胶飘
	int count;			//傈眉 港港捞甸狼 荐

	void CreataAll();	//葛电 港港捞 积己窃荐
};

//具克捞 包访 巴甸
namespace Cat
{
	//具克捞 茄 付府 沥焊
	class Info
	{
	public:
		void Meow();
	protected:
		char name[20];
	};

	Info cats[20];		//具克捞 府胶飘
	int count;			//傈眉 具克捞甸狼 荐

	void CreateAll();	//葛电 具克捞 积己窃荐
}

//傈眉 港港捞客 具克捞狼 荐 
int count;


ostream& operator<<(ostream& os, const Complex right)
{
	os << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return os;
}

int main()
{
	//葛电 具克捞甫 积己茄促
	Cat::CreateAll();

	//具克捞 硅凯俊 立辟茄促
	Cat::cats[0].Meow();

	//葛电 港港捞甫 积己茄促.
	Dog::CreataAll();

	//港港捞狼 俺荐甫 掘绢柯促.
	int dog_count = Dog::count;
}