#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 1000;

struct StudentInfo {
    int id;
    string name;
    double gpa;

    bool operator<(const StudentInfo& other) const {
        return name < other.name;
    }

    bool operator<=(const StudentInfo& other) const {
        return name <= other.name;
    }

    bool operator>(const StudentInfo& other) const {
        return name > other.name;
    }

    bool operator>=(const StudentInfo& other) const {
        return name >= other.name;
    }
};

class Student {
public:
    Student();
    ~Student() {};
    void InitValue(int index, int id, const string name, double gpa);
    void GetStudentInfo(int index) const;
    int GetStudentNum() const;
    StudentInfo* GetStudents();
    bool operator<(const Student& other) const {
        return students[0] < other.students[0];
    }

    bool operator<=(const Student& other) const {
        return students[0] <= other.students[0];
    }

    bool operator>(const Student& other) const {
        return students[0] > other.students[0];
    }

    bool operator>=(const Student& other) const {
        return students[0] >= other.students[0];
    }

private:
    StudentInfo students[MAX_STUDENTS];
    int studentNum; //현재 학생 수 
};

void Swap(Student*& item1, Student*& item2);
