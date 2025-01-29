#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[20];
	char str2[20];

	printf("문자열 입력 1 : ");
	scanf_s("%s", str1, 20);

	printf("문자열 입력 2 : ");
	scanf_s("%s", str2, 20);

	str1[19] = 0;
	str2[19] = 0;

	if (strcmp(str1, str2) == 0)
	{
		puts("두 문자열은 완벽히 동일합니다.");
	}
	else
	{
		puts("두 문자열은 동일하지 않습니다.");

		if (strncmp(str1, str2, 3) == 0)
			puts("그러나 앞 세글자는 동일합니다.");
	}

	return 0;
}