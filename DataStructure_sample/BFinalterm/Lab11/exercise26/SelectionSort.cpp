#include"SelectionSort.h"
#include<iostream>

void SelectionSort(Student& stu)
{
	int count = stu.GetStudentNum();
	StudentInfo* students = stu.GetStudents();

	for (int i = 0; i < count-1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < count; j++)
		{
			if (students[j].name < students[minIndex].name)
				minIndex = j;
		}
		if (minIndex != i)
		{
			StudentInfo temp = students[i];
			students[i] = students[minIndex];
			students[minIndex] = temp;
		}
	}
}