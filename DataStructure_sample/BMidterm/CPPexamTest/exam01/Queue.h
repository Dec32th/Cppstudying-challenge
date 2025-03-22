#pragma once
class Queue
{

};

//큐

//#include <iostream>
//
//class Queue {
//private:
//    int front;      // 큐의 앞부분을 가리키는 인덱스
//    int rear;       // 큐의 뒷부분을 가리키는 인덱스
//    int capacity;   // 큐의 최대 용량
//    int* queue;     // 큐의 요소를 저장하는 동적 배열
//
//public:
//    // 생성자: 큐의 크기를 설정하고 변수들을 초기화합니다.
//    Queue(int c) {
//        front = rear = 0;
//        capacity = c;
//        queue = new int[capacity];
//    }
//
//    // 소멸자: 동적으로 할당된 배열을 해제합니다.
//    ~Queue() {
//        delete[] queue;
//    }
//
//    // 큐에 데이터를 추가하는 함수
//    void enqueue(int data) {
//        if (capacity == rear) { // 큐가 가득 찼는지 검사
//            std::cout << "Queue is full\n";
//            return;
//        }
//        else {
//            queue[rear] = data; // rear 위치에 데이터 삽입
//            rear++;             // rear를 하나 증가
//        }
//    }
//
//    // 큐에서 데이터를 제거하고 반환하는 함수
//    int dequeue() {
//        if (front == rear) { // 큐가 비어 있는지 검사
//            std::cout << "Queue is empty\n";
//            return -1;
//        }
//        else {
//            int item = queue[front]; // front 위치의 데이터를 가져옴
//            for (int i = 0; i < rear - 1; i++) { // 큐의 데이터를 앞으로 이동
//                queue[i] = queue[i + 1];
//            }
//            rear--; // rear를 하나 감소
//            return item; // 제거된 원소 반환
//        }
//    }
//
//    // 큐의 맨 앞 원소를 반환하는 함수
//    int peek() {
//        if (front == rear) { // 큐가 비어 있는지 확인
//            std::cout << "Queue is empty\n";
//            return -1;
//        }
//        else {
//            return queue[front]; // front 위치의 데이터 반환
//        }
//    }
//
//    // 큐가 비어있는지 확인하는 함수
//    bool isEmpty() {
//        return (front == rear);
//    }
//};
//
//int main() {
//    Queue q(5);
//
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    std::cout << "Dequeued: " << q.dequeue() << std::endl;
//    std::cout << "Front item: " << q.peek() << std::endl;
//
//    return 0;
//}


//원형 큐
//#include <iostream>
//using namespace std;
//
//class CircularQueue {
//private:
//    int* queue;
//    int front;
//    int rear;
//    int capacity;
//
//public:
//    CircularQueue(int size) {
//        capacity = size;
//        queue = new int[capacity];
//        front = 0;
//        rear = 0;
//    }
//
//    ~CircularQueue() {
//        delete[] queue;
//    }
//
//    // 큐가 비어있는지 확인
//    bool isEmpty() {
//        return front == rear;
//    }
//
//    // 큐가 가득 찼는지 확인
//    bool isFull() {
//        return (rear + 1) % capacity == front;
//    }
//
//    // 요소 삽입
//    void enqueue(int data) {
//        if (isFull()) {
//            cout << "Queue is full!" << endl;
//            return;
//        }
//        queue[rear] = data;
//        rear = (rear + 1) % capacity;
//    }
//
//    // 요소 제거
//    int dequeue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//        int data = queue[front];
//        front = (front + 1) % capacity;
//        return data;
//    }
//
//    // 큐 전면의 요소 확인
//    int peek() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//        return queue[front];
//    }
//
//    // 큐 출력
//    void printQueue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        int i = front;
//        cout << "Queue contents: ";
//        while (i != rear) {
//            cout << queue[i] << " ";
//            i = (i + 1) % capacity;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    CircularQueue q(5); // 실제로는 4개의 요소만 저장 가능
//
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//    q.enqueue(4);
//    q.printQueue();
//
//    q.dequeue();
//    q.dequeue();
//    q.printQueue();
//
//    q.enqueue(5);
//    q.enqueue(6);
//    q.printQueue();
//
//    return 0;
//}

