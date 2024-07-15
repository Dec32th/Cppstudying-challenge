#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

//각 자리는 0-255까지의 세자리수로 되어있으며, .으로 구별됨
//0-255로 되어있고, 1.0.0.1 부터 255.255.255.255까지 가능하다. -> 입력을 string 으로 받아서 짜르자!!!
//thtrow catch 구문을 이용해서 이상한 값이 입력되었을 경우를 대비한다. 

const int MAX_IPV4_SIZE = 4;

class IPv4
{
public:
	IPv4() {};
	IPv4(string ipstr) 
	{ 
		makeIPArray(ipstr); 
		ipv4Size = size(aIPv4);
	};
	//입력 받은 string을 배열에 넣는 함수 -> 이때, .을 기준으로 나누어 넣어한다. 
	void makeIPArray(string IpNum);

	//출력을 위한 print 함수
	void Print();
	
	//사이에 존재하는 IP의 값을 출력하는 함수. 
	void InterIP(IPv4 ip1);
	
private:
	int aIPv4[MAX_IPV4_SIZE];		//배열에는 숫자만 저장된다. print를 할 때는 사이에.을 넣어서 출력해줘야함.
	int ipv4Size;
};



// 일단 입력 받은 숫자를 .을 기준으로 잘라야한다. 그치만 그 전에 배열에 넣는 게 필요함. 
// 여기에 throw catch 구문을 넣어서 에러를 던지고 잡기 
void IPv4::makeIPArray(string ipNum)
{
	istringstream ss(ipNum);
	string temp1;
	vector<string> v1;

	while (getline(ss, temp1, '.'))
	{
		v1.push_back(temp1);
	}

	for (auto iter = v1.begin(); iter != v1.end(); iter++)
	{
		int i = 0;
		string temp = *iter;
		int temp1 = stoi(temp);
		aIPv4[i] = temp1;
		i++;
	}
}

void IPv4::Print()
{
	for (int i = 0; i < MAX_IPV4_SIZE; i++)
	{
		if (i == 3)
			cout << aIPv4[i];
		else
			cout << aIPv4[i] << ".";
	}
}

void IPv4::InterIP(IPv4 ip1)
{
	for (int i = 0; i < MAX_IPV4_SIZE; i++)
	{
		if (this->aIPv4[i] == ip1.aIPv4[i])
		{
			if (i == 3)
			{
				for (int j = ip1.aIPv4[i] + 1; j < this->aIPv4[i]; j++)
				{
					cout << ip1.aIPv4[0] << "." << ip1.aIPv4[1] << "." << ip1.aIPv4[2] << "." << j;
				}
			}
		}
	}
}