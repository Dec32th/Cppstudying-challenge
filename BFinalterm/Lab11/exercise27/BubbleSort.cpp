#include"BubbleSort.h"

void BubbleSort(Student& stu)
{
	int count = stu.GetStudentNum();
	StudentInfo* students = stu.GetStudents();

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (students[j].name > students[j + 1].name)
			{
				StudentInfo temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
}