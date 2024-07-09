#include"InsertionSort.h"

void InsertionSort(Student& stu)
{
	int count = stu.GetStudentNum();
	StudentInfo* students = stu.GetStudents();

	for (int i = 1; i < count; i++)
	{
		StudentInfo key = students[i];
		int j = i - 1;
		while (j >= 0 && students[j].name > key.name)
		{
			students[j + 1] = students[j];
			j--;
		}
		students[j + 1] = key;
	}
}