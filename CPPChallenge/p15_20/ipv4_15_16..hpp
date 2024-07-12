#include<iostream>
#include<array>
#include<string>
using namespace std;

//각 자리는 0-255까지의 세자리수로 되어있으며, .으로 구별됨
//0-255로 되어있고, 1.0.0.1 부터 255.255.255.255까지 가능하다. -> 입력을 string으로 받아서 짜르자!!!

const int MAX_IPV4_SIZE = 15;

class IPv4
{
public:
	//입력 받은 string을 배열에 넣는 함수 -> 이때, .을 기준으로 나누어 넣어한다. 
	int makeIPArray(string IpNum);
	
private:
	string IpNum;
	int aIPv4[MAX_IPV4_SIZE];
	int ipv4Size;
};



// 일단 입력 받은 숫자를 .을 기준으로 잘라야한다. 그치만 그 전에 배열에 넣는 게 필요함. 
int IPv4::makeIPArray(string ipNum)
{
	
}