#include "Student.h"

Student::Student() : studentNum(0) {}

void Student::InitValue(int index, int id, const string name, double gpa) {
    if (index >= 0 && index < MAX_STUDENTS) {
        students[index].id = id;
        students[index].name = name;
        students[index].gpa = gpa;
        studentNum++;
    }
}

void Student::GetStudentInfo(int index) const {
    if (index >= 0 && index < studentNum) {
        cout << "ID: " << students[index].id << ", Name: " << students[index].name << ", GPA: " << students[index].gpa << endl;
    }
}

int Student::GetStudentNum() const {
    return studentNum;
}

StudentInfo* Student::GetStudents() {
    return students;
}

void Swap(Student*& item1, Student*& item2) {
    Student* temp = item1;
    item1 = item2;
    item2 = temp;
}
