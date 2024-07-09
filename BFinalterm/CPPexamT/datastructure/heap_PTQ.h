//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//class Heap {
//private:
//    std::vector<int> heap;
//
//    // Reheap up to maintain the heap property after insertion
//    void reheapUp(int index) {
//        if (index == 0) {
//            return; // Root node, no parent to compare with
//        }
//        int parentIndex = (index - 1) / 2;
//        if (heap[index] > heap[parentIndex]) {
//            std::swap(heap[index], heap[parentIndex]);
//            reheapUp(parentIndex); // Recursively reheap up
//        }
//    }
//
//    // Reheap down to maintain the heap property after removal
//    void reheapDown(int index) {
//        int leftChildIndex = 2 * index + 1;
//        int rightChildIndex = 2 * index + 2;
//        int largest = index;
//
//        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largest]) {
//            largest = leftChildIndex;
//        }
//        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largest]) {
//            largest = rightChildIndex;
//        }
//        if (largest != index) {
//            std::swap(heap[index], heap[largest]);
//            reheapDown(largest); // Recursively reheap down
//        }
//    }
//
//public:
//    Heap() {}
//
//    void insert(int value) {
//        heap.push_back(value);
//        reheapUp(heap.size() - 1); // Maintain heap property after insertion
//    }
//
//    int extractMax() {
//        if (heap.empty()) {
//            throw std::out_of_range("Heap is empty");
//        }
//        int maxValue = heap[0];
//        heap[0] = heap.back();
//        heap.pop_back();
//        reheapDown(0); // Maintain heap property after removal
//        return maxValue;
//    }
//
//    int peekMax() const {
//        if (heap.empty()) {
//            throw std::out_of_range("Heap is empty");
//        }
//        return heap[0];
//    }
//
//    bool isEmpty() const {
//        return heap.empty();
//    }
//
//    void display() const {
//        for (int val : heap) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    Heap heap;
//    heap.insert(10);
//    heap.insert(20);
//    heap.insert(5);
//    heap.insert(30);
//    heap.insert(25);
//
//    std::cout << "Heap elements: ";
//    heap.display();
//
//    std::cout << "Max element: " << heap.extractMax() << std::endl;
//    std::cout << "Heap elements after extraction: ";
//    heap.display();
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <stdexcept>
//
//class PriorityQueue {
//private:
//    Heap heap;
//
//public:
//    void push(int value) {
//        heap.insert(value);
//    }
//
//    int pop() {
//        return heap.extractMax();
//    }
//
//    int top() const {
//        return heap.peekMax();
//    }
//
//    bool empty() const {
//        return heap.isEmpty();
//    }
//
//    void display() const {
//        heap.display();
//    }
//};
//
//int main() {
//    PriorityQueue pq;
//    pq.push(10);
//    pq.push(20);
//    pq.push(5);
//    pq.push(30);
//    pq.push(25);
//
//    std::cout << "Priority Queue elements: ";
//    pq.display();
//
//    std::cout << "Max element: " << pq.pop() << std::endl;
//    std::cout << "Priority Queue elements after pop: ";
//    pq.display();
//
//    return 0;
//}

