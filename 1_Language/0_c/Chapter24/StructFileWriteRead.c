#include <stdio.h>

typedef struct fren
{
	char name[10];
	char sex;
	int age;
} Friend;

int main(void)
{
	FILE* fp;
	Friend myfren1;
	Friend myfren2;

	// file write
	fopen_s(&fp, "friend.bin", "wb");
	if (fp == NULL)
	{
		printf("파일 오픈 실패");
		return -1;
	}

	printf("이름, 성별, 나이 순 입력 : ");
	scanf_s("%s %c %d", myfren1.name, 10, &myfren1.sex, 1, &myfren1.age);
	fwrite((void*)&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);

	// file read
	fopen_s(&fp, "friend.bin", "rb");
	if (fp == NULL)
	{
		printf("파일 오픈 실패");
		return -1;
	}

	fread((void*)&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d\n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

	return 0;
}