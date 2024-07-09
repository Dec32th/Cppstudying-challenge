#include"QuickSort.h"
#include"Student.h"
#include <iostream>

void Swap(StudentInfo& one, StudentInfo& two) {
    StudentInfo temp = one;
    one = two;
    two = temp;
}

void Split(StudentInfo values[], int first, int last, int& splitPoint) {
    StudentInfo splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;
    do {
        onCorrectSide = true;
        while (onCorrectSide) { // Move first toward last.
            if (values[first] > splitVal) {
                onCorrectSide = false;
            }
            else {
                first++;
                onCorrectSide = (first <= last);
            }
        }
        onCorrectSide = (first <= last);
        while (onCorrectSide) { // Move last toward first.
            if (values[last] <= splitVal) {
                onCorrectSide = false;
            }
            else {
                last--;
                onCorrectSide = (first <= last);
            }
        }
        if (first < last) {
            Swap(values[first], values[last]);
            first++;
            last--;
        }
    } while (first <= last);

    splitPoint = last;
    Swap(values[saveFirst], values[splitPoint]);
}

void QuickSort(Student& stu, int first, int last) {
    if (first < last) {
        int splitPoint;
        Split(stu.GetStudents(), first, last, splitPoint);
        QuickSort(stu, first, splitPoint - 1);
        QuickSort(stu, splitPoint + 1, last);
    }
}