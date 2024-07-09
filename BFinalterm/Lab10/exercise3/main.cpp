#include<iostream>
#include"Heap.h"
using namespace std;

int main()
{
    // HeapType 인스턴스 생성
    HeapType<int> heap;
    heap.numElements = 5;
    heap.elements = new int[heap.numElements];

    // 임의의 값으로 힙을 채우기
    int values[] = { 10, 20, 5, 30,25 };
    for (int i = 0; i < heap.numElements; ++i) {
        heap.elements[i] = values[i];
    }

    // 힙의 요소 출력
    cout << "Initial heap elements: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    //// ReheapDown 테스트
    heap.ReheapDown(0, heap.numElements - 1);

    // ReheapDown 후 힙의 요소 출력
    cout << "Heap elements after ReheapDown: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    // ReheapUp 테스트
    heap.elements[4] = 35;
    heap.ReheapUp(0, heap.numElements - 1);

    // ReheapUp 후 힙의 요소 출력
    cout << "Heap elements after ReheapUp: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    // 동적 배열 해제
    delete[] heap.elements;

    return 0;
}

//heap은 최악의 경우에도 O(log_2n)을 보장한다.  
//그리고 reheapdown과 reheapup 둘다 최악의 경우에도 트리의 높이에 비례해서 동작한다.
// 따라서 둘의 시간복잡도는 O(logn)