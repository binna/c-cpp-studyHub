#include <stdio.h>
int NumberCompare(int num1, int num2);

int main(void)
{
	printf("3과 4 중에서 큰 수는 %d이다.\n", NumberCompare(3, 4));
	printf("7과 2 중에서 큰 수는 %d이다.\n", NumberCompare(7, 2));
	return 0;
}

int NumberCompare(int num1, int num2)
{
	if (num1 > num2)
		return num1;

	return num2;
}