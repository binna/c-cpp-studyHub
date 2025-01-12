#include <stdio.h>

int main(void)
{
	int num = 3;

	num = num << 3;		// 8의 곱
	num = num >> 2;		// 4의 나누기

	printf("%d\n", num);

	return 0;
}