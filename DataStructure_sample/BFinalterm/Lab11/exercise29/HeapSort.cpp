#include"HeapSort.h"

void HeapSort(Student& stu) {
    int count = stu.GetStudentNum();
    StudentInfo* students = stu.GetStudents();
    HeapType<StudentInfo> heap;
    heap.elements = students;
    heap.numElements = count;

    // 힙 만들기
    for (int index = count / 2 - 1; index >= 0; index--) {
        heap.ReheapDown(index, count - 1);
    }

    // 정렬
    for (int index = count - 1; index >= 1; index--) {
        Swap(heap.elements[0], heap.elements[index]);
        heap.ReheapDown(0, index - 1);
    }
}