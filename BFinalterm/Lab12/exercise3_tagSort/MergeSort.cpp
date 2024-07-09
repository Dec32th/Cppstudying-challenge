#include "MergeSort.h"

void MergeSortPointer(Student* values[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSortPointer(values, left, mid);
        MergeSortPointer(values, mid + 1, right);
        Merge(values, left, mid, right);
    }
}

void Merge(Student* values[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Student** leftArray = new Student * [leftSize];
    Student** rightArray = new Student * [rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = values[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = values[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (*leftArray[i] <= *rightArray[j]) {
            values[k] = leftArray[i];
            i++;
        }
        else {
            values[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        values[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        values[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}
