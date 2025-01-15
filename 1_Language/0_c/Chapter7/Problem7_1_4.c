#include <stdio.h>

int main(void)
{
	int num;
	int i = 9;

	printf("역순으로 출력할 단 입력 : ");
	scanf_s("%d", &num);

	while (i > 0)
	{
		printf("%dX%d=%d\n", num, i, num * i);
		i--;
	}

	return 0;
}