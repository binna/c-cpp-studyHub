#include <stdio.h>

int main(void)
{
	long fpos;
	int i;

	// 파일 생성
	FILE* fp;

	fopen_s(&fp, "text.txt", "wt");

	if (fp == NULL)
	{
		printf("파일 오픈 실패 - 1");
		return -1;
	}

	fputs("1234|", fp);
	fclose(fp);

	// 파일 개방
	fopen_s(&fp, "text.txt", "rt");

	if (fp == NULL)
	{
		printf("파일 오픈 실패 - 1");
		return -1;
	}

	for (i = 0; i < 4; i++)
	{
		putchar(fgetc(fp));
		fpos = ftell(fp);
		fseek(fp, -1, SEEK_END);
		putchar(fgetc(fp));
		fseek(fp, fpos, SEEK_SET);
	}

	fclose(fp);
	return 0;
}