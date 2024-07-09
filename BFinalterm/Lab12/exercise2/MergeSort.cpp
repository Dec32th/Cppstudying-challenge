#include"MergeSort.h"
#include<iostream>

void Merge(StudentInfo values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int index = leftFirst;
    int saveFirst = leftFirst;
    int size = rightLast - leftFirst + 1;
    StudentInfo* tempArray = new StudentInfo[size];

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        if (values[leftFirst] < values[rightFirst]) {
            tempArray[index - saveFirst] = values[leftFirst];
            leftFirst++;
        }
        else {
            tempArray[index - saveFirst] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while (leftFirst <= leftLast) {
        tempArray[index - saveFirst] = values[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast) {
        tempArray[index - saveFirst] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++) {
        values[index] = tempArray[index - saveFirst];
    }

    delete[] tempArray;
}

void MergeSort(Student& stu, int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        MergeSort(stu, first, middle);
        MergeSort(stu, middle + 1, last);
        Merge(stu.GetStudents(), first, middle, middle + 1, last);
    }
}