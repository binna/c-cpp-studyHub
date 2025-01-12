#include <stdio.h>

int main(void)
{
	int num1 = 15;				// 0000 0000  0000 0000  0000 0000  0000 1111
	int num2 = 20;				// 0000 0000  0000 0000  0000 0000  0001 0100
	int num3 = num1 & num2;		// 0000 0000  0000 0000  0000 0000  0000 0100
	printf("AND 연산의 결과 : %d\n", num3);
	return 0;
}