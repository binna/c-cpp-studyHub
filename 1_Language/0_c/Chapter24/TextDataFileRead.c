#include <stdio.h>

int main(void)
{
	char str[30];
	int ch;
	FILE* fp;

	fopen_s(&fp, "simple.txt", "rt");

	if (fp == NULL)
	{
		printf("파일 오픈 실패");
		return -1;
	}

	ch = fgetc(fp);
	printf("%c \n", ch);

	ch = fgetc(fp);
	printf("%c \n", ch);

	fgets(str, sizeof(str), fp);
	printf("%s", str);

	fgets(str, sizeof(str), fp);
	printf("%s", str);

	fclose(fp);
	return 0;
}