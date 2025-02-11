#include <stdio.h>

int main(void)
{
	char name[10];
	char sex;
	int age, i;

	FILE* fp;

	fopen_s(&fp, "friend.txt", "wt");

	if (fp == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		printf("이름 성별 나이 순 입력 : ");
		scanf_s("%s %c %d", name, sizeof(name), &sex, sizeof(char), &age);
		getchar();		// 버퍼에 남아있는 \n의 소멸을 위하여
		fprintf(fp, "%s %c %d", name, sex, age);
	
	}

	fclose(fp);
	return 0;
}