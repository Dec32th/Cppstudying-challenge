#pragma once


//lab4 stack


//stack
//#include <iostream>
//#include <climits> // INT_MIN을 사용하기 위해 필요
//using namespace std;
//
//class Stack {
//private:
//    int top;        // 스택의 가장 상단 요소를 가리키는 인덱스
//    int capacity;   // 스택의 최대 용량
//    int* stack;     // 스택의 요소를 저장하는 동적 배열
//
//public:
//    // 생성자: 스택의 크기를 설정하고 top을 -1로 초기화합니다.
//    Stack(int size) {
//        capacity = size;
//        stack = new int[capacity];
//        top = -1;
//    }
//
//    // 소멸자: 동적으로 할당된 배열을 해제합니다.
//    ~Stack() {
//        delete[] stack;
//    }
//
//    // 스택에 요소를 추가하는 함수
//    void push(int value) {
//        if (top == capacity - 1) { // 스택이 가득 찼는지 검사
//            cout << "Stack Overflow" << endl;
//            return;
//        }
//        else {
//            stack[++top] = value; // top을 증가시킨 후 그 위치에 값 저장
//        }
//    }
//
//    // 스택에서 최상위 요소를 제거하고 반환하는 함수
//    int pop() {
//        if (top == -1) { // 스택이 비어 있는지 검사
//            cout << "Stack Underflow" << endl;
//            return INT_MIN;
//        }
//        else {
//            return stack[top--]; // 현재 top의 요소를 반환하고 top을 감소
//        }
//    }
//
//    // 스택의 최상위 요소를 반환하는 함수 (제거하지 않음)
//    int peek() {
//        if (top == -1) { // 스택이 비어 있는지 검사
//            cout << "Stack is empty" << endl;
//            return INT_MIN;
//        }
//        else {
//            return stack[top]; // 현재 top의 요소를 반환
//        }
//    }
//
//    // 스택이 비어있는지 확인하는 함수
//    bool isEmpty() {
//        return top == -1;
//    }
//};
//
//int main() {
//    Stack s(5);  // 스택의 크기를 5로 설정
//
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    cout << "Popped: " << s.pop() << endl;
//    cout << "Top element: " << s.peek() << endl;
//
//    return 0;
//}
