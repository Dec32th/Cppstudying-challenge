#pragma once
//heap

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void reheapDown(vector<int>& arr, int n, int i) {
//    int largest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    if (left < n && arr[left] > arr[largest])
//        largest = left;
//
//    if (right < n && arr[right] > arr[largest])
//        largest = right;
//
//    if (largest != i) {
//        swap(arr[i], arr[largest]);
//        reheapDown(arr, n, largest);
//    }
//}
//
//void reheapUp(vector<int>& arr, int i) {
//    if (i&& arr[(i - 1) / 2] < arr[i]) {
//        swap(arr[i], arr[(i - 1) / 2]);
//        reheapUp(arr, (i - 1) / 2);
//    }
//}
//
//void heapSort(vector<int>& arr) {
//    int n = arr.size();
//
//    for (int i = n / 2 - 1; i >= 0; i--)
//        reheapDown(arr, n, i);
//
//    for (int i = n - 1; i > 0; i--) {
//        swap(arr[0], arr[i]);
//        reheapDown(arr, i, 0);
//    }
//}
//
//int main() {
//    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
//    heapSort(arr);
//    for (int x : arr)
//        cout << x << " ";
//    return 0;
//}

//PTQ 

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class PriorityQueue {
//private:
//    vector<int> heap;
//
//    void reheapDown(int i) {
//        int largest = i;
//        int left = 2 * i + 1;
//        int right = 2 * i + 2;
//
//        if (left < heap.size() && heap[left] > heap[largest])
//            largest = left;
//
//        if (right < heap.size() && heap[right] > heap[largest])
//            largest = right;
//
//        if (largest != i) {
//            swap(heap[i], heap[largest]);
//            reheapDown(largest);
//        }
//    }
//
//    void reheapUp(int i) {
//        if (i && heap[(i - 1) / 2] < heap[i]) {
//            swap(heap[i], heap[(i - 1) / 2]);
//            reheapUp((i - 1) / 2);
//        }
//    }
//
//public:
//    void push(int val) {
//        heap.push_back(val);
//        reheapUp(heap.size() - 1);
//    }
//
//    void pop() {
//        if (heap.size() > 1) {
//            heap[0] = heap.back();
//            heap.pop_back();
//            reheapDown(0);
//        }
//        else {
//            heap.pop_back();
//        }
//    }
//
//    int top() {
//        if (!heap.empty()) return heap.front();
//        throw out_of_range("Heap is empty");
//    }
//
//    bool empty() {
//        return heap.empty();
//    }
//
//    int size() {
//        return heap.size();
//    }
//};
//
//int main() {
//    PriorityQueue pq;
//    pq.push(3);
//    pq.push(1);
//    pq.push(4);
//    pq.push(1);
//    pq.push(5);
//    pq.push(9);
//
//    while (!pq.empty()) {
//        cout << pq.top() << " ";
//        pq.pop();
//    }
//    return 0;
//}

