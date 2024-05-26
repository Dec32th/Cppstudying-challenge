//재귀함수보다 for문이 더 성능을 향상시킨다고 생각한다. 
//재귀함수를 사용하는 경우에는 함수를 호출하는 과정에서 stack memory를 사용하게 되는데, 피보나치 수열의 경우
//2갈래로 갈라지면서 많은 stack memory를 사용하게 되고, stack overflow가 발생하는 원인이 될 수 있다.
//또한 bigO표현법을 이용하여 보는 경우에도 시간복잡도가 재귀함수가 훨씬 더 나쁘다. 


#include <iostream>
#include"Fibonacci.h"
using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main()
{
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;

	return 0;
}
