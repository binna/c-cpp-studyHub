#include <stdio.h>

typedef struct student
{
	char name[20];
	char stdnum[20];
	char school[20];
	char major[20];
	int year;
} Student;

void ShowStudentInfo(Student* sptr)
{
	printf("학생 이름 : %s\n", sptr->name);
	printf("학생 고유번호 : %s\n", sptr->stdnum);
	printf("학교 이름 : %s\n", sptr->school);
	printf("선택 전공 : %s\n", sptr->major);
	printf("학년 : %d\n", sptr->year);
}

int main(void)
{
	//printf("%d", sizeof(Student));

	Student arr[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("이름 : "); scanf_s("%s", arr[i].name, sizeof(arr[i].name));
		printf("번호 : "); scanf_s("%s", arr[i].stdnum, sizeof(arr[i].stdnum));
		printf("학교 : "); scanf_s("%s", arr[i].school, sizeof(arr[i].school));
		printf("전공 : "); scanf_s("%s", arr[i].major, sizeof(arr[i].major));
		printf("학년 : "); scanf_s("%d", &arr[i].year);
	}
	
	for (i = 0; i < 3; i++)
		ShowStudentInfo(&arr[i]);

	return 0;
}