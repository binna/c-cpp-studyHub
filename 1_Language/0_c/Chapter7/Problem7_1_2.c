#include <stdio.h>

int main(void)
{
	int num = 0, cnt = 0;
	printf("배수의 개수: ");
	scanf_s("%d", &num);

	while (cnt++ < num)
	{
		printf("%d ", 3 * cnt);
	}

	return 0;
}