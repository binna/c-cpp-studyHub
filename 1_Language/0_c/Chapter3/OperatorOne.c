#include <stdio.h>

int main(void)
{
	int num1 = 2, num2 = 4, num3 = 6;

	printf("%d+%d=%d\n", num1, num2, num1 + num2);
	printf("%d-%d=%d\n", num1, num2, num1 - num2);
	printf("%d*%d=%d\n", num1, num2, num1 * num2);
	printf("%d/%d=%d\n", num1, num2, num1 / num2);
	printf("%d%%%d=%d\n", num1, num2, num1 % num2);
	return 0;
}