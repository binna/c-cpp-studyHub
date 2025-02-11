#include <stdio.h>

int main(void)
{
	char name[10];
	char sex;
	int age, ret;

	FILE* fp;
	fopen_s(&fp, "friend.txt", "rt");

	if (fp == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	while (1)
	{
		ret = fscanf_s(fp, "%s %c %d", name, sizeof(name), &sex, sizeof(char), &age);

		if (ret == EOF)
			break;

		printf("%s %c %d\n", name, sex, age);
	}

	fclose(fp);
	return 0;
}