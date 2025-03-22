#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 1000;

struct StudentInfo {
    int id;
    string name;
    double gpa;

    bool operator==(const StudentInfo& other) const {
        return name == other.name && id == other.id && gpa == other.gpa;
    }

    bool operator!=(const StudentInfo& other) const {
        return !(*this == other);
    }

    const char* key() const {
        return name.c_str();
    }
};

class Student {
public:
    Student();
    ~Student() {};
    void InitValue(int id, const string& name, double gpa);
    void GetStudentInfo() const;
    static StudentInfo emptyStudent;
    const char* Key() const;


    bool operator==(const Student& other) const {
        return this->student.name == other.student.name;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    const char* key() const {
        return this->student.name.c_str();
    }

private:
    StudentInfo student;
};

