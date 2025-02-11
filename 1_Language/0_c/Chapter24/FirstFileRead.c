#include <stdio.h>

int main(void)
{
	int ch, i;

	FILE* fp;
	fopen_s(&fp, "data.txt", "rt");

	if (fp == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	for (i = 0; i < 3; i++)
	{
		ch = fgetc(fp);
		printf("%c\n", ch);
	}

	fclose(fp);
	return 0;
}