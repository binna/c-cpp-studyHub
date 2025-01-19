#include <stdio.h>
#include <windows.h>

int main(void)
{
	char str[50];
	int idx = 0;

	printf("문자열 입력: ");
	scanf_s("%s", str, (unsigned int)_countof(str));		// 문자열을 입력 받아서 배열 str에 저장

	printf("문자 단위 출력: ");
	while (str[idx] != '\0')	// 문자열 끝까지 출력
	{
		printf("%c", str[idx]);
		idx++;
	}
	printf("\n");

	return 0;
}