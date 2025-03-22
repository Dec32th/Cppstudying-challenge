#include <iostream>
#include "Student.h"
#include "HashTable.hpp"

int main() {
    Student students[MAX_STUDENTS];
    students[0].InitValue(2003200111, "ÀÌ¿õÀç", 3.0);
    students[1].InitValue(2004200121, "±Ç¿ÀÁØ", 3.2);
    students[2].InitValue(2005200132, "±èÁøÀÏ", 2.7);

    HashTable<Student> studentTable;

    for (int i = 0; i < 3; ++i) {
        studentTable.InsertItem(students[i]);
    }

    std::string searchName;
    std::cout << "Enter student name to search: ";
    std::cin >> searchName;

    Student searchStudent;
    searchStudent.InitValue(0, searchName, 0.0);
    bool found;
    studentTable.RetrieveItem(searchStudent, found);

    if (found) {
        searchStudent.GetStudentInfo();
    }
    else {
        std::cout << "Student not found." << std::endl;
    }

    return 0;
}
