#include <stdio.h>

int main(void)
{
	int num;

	printf("정수 입력: ");
	scanf_s("%d", &num);

	num = ~num + 1;

	printf("부호를 바꾼 결과: %d", num);

	return 0;
}