#include <stdio.h>

int main(void)
{
	FILE* fp;
	fopen_s(&fp, "data.txt", "wt");

	if (fp == NULL)
	{
		printf("파일 오픈 실패");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	
	fclose(fp);
	return 0;
}