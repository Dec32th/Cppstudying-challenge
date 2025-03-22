#include <iostream>
#include "Student.h"
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;

int main() {
    Student students[MAX_STUDENTS];
    students[0].InitValue(0, 2003200111, "ÀÌ¿õÀç", 3.0);
    students[1].InitValue(1, 2004200121, "±Ç¿ÀÁØ", 3.2);
    students[2].InitValue(2, 2005200132, "±èÁøÀÏ", 2.7);

    Student* studentPointers[3];
    for (int i = 0; i < 3; i++) {
        studentPointers[i] = &students[i];
    }

    cout << "Before QuickSortPointer:" << endl;
    for (int i = 0; i < 3; i++) {
        studentPointers[i]->GetStudentInfo(0);
    }

    QuickSortPointer(studentPointers, 0, 2);

    cout << "After QuickSortPointer:" << endl;
    for (int i = 0; i < 3; i++) {
        studentPointers[i]->GetStudentInfo(0);
    }

    // Reinitializing for MergeSortPointer
    students[0].InitValue(0, 2003200111, "ÀÌ¿õÀç", 3.0);
    students[1].InitValue(1, 2004200121, "±Ç¿ÀÁØ", 3.2);
    students[2].InitValue(2, 2005200132, "±èÁøÀÏ", 2.7);
    for (int i = 0; i < 3; i++) {
        studentPointers[i] = &students[i];
    }

    cout << "Before MergeSortPointer:" << endl;
    for (int i = 0; i < 3; i++) {
        studentPointers[i]->GetStudentInfo(0);
    }

    MergeSortPointer(studentPointers, 0, 2);

    cout << "After MergeSortPointer:" << endl;
    for (int i = 0; i < 3; i++) {
        studentPointers[i]->GetStudentInfo(0);
    }
}
