#include <stdio.h>

int main(void)
{
	FILE* src, * des;
	char buf[20];
	int readCnt;

	fopen_s(&src, "src.txt", "rt");
	fopen_s(&des, "des.txt", "wt");

	if (src == NULL || des == NULL)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	while (1)
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf))
		{
			if (feof(src) != 0)
			{
				fwrite((void*)buf, 1, readCnt, des);
				puts("파일 복사 완료");
				break;
			}
			else
			{
				puts("파일 복사 실패");
			}
			break;
		}
		fwrite((void*)buf, 1, readCnt, des);
	}

	fclose(src);
	fclose(des);
	return 0;
}