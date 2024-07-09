#include "Student.h"

StudentInfo Student::emptyStudent = { 0, "", 0.0 };

Student::Student() {
    student = emptyStudent;
}

void Student::InitValue(int id, const string& name, double gpa) {
    student.id = id;
    student.name = name;
    student.gpa = gpa;
}

void Student::GetStudentInfo() const {
    cout << "ID : " << student.id
        << " ,Name : " << student.name
        << " ,GPA : " << student.gpa << endl;
}

const char* Student::Key() const {
    return student.key();
}
