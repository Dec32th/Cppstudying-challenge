#pragma once


//12개 중에서 4개를 예측해야하고, 기존의 12개는 모두 이긴다고 계산을 해야함.
//추가로 정하지 않은 값 -> 이 값이 승부를 예측할 때, rand로 이길지, 비길지, 질지를 예측 - 무승부일때는 연승점수 유지.
//[가위, “바위”, 가위, 바위, 보, “보”, 가위, 보, 가위,   보, “바위”, “바위”]
//이김    이김    이김   이김 이김  무     이김  이김 이김    이김  이김     짐 = 1+(1+1)+(2+1)+(3+1)+(4+1)+0+(4+1)+
//[바위,   보,    바위,   보, 가위,  보,   바위, 가위, 바위, 가위,  보,       가위]
//승부 예측은 연승점수 없음. 그냥 이기면 +1, 지면 -1, 무승부면 0 이때, 정해야하는 4개는 rand를 이용해서 승/무/패중 하나를 골라서 넣기
//예측 점수 + 기존 점수를 해서 총점을 계산. 
//queue는 fifo 구조. 먼저 넣은게 먼저 나온다. front와 rear를 이용해서

class Queue
{
public:
	Queue();
	~Queue();
	bool IsFull(); //Blue 12개 입력 받는 경우
	int ScoreBlue(); //Blue팀의 승부 점수 예측
	int preScoreBlue();
	
private:
	int front;
	int rear;
	int max;
	int iCount; //연승 수를 count

	int scoreBlue; //blue 팀의 승부 점수.
	int preBlue; //blue 팀의 승부 점수 예측.
};