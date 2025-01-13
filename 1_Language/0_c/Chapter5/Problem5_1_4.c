#include <stdio.h>

int main(void)
{
	int asc;
	printf("숫자 입력: ");
	scanf_s("%d", &asc);
	printf("아스키 문자: %c\n", asc);
	return 0;
}