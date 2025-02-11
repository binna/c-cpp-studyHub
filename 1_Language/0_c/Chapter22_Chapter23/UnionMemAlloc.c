#include <stdio.h>

typedef struct sbox
{
	int mem1;
	int mem2;
	double mem3;
} SBox;

typedef union ubox
{
	int num1;
	int num2;
	double num3;
} UBox;

int main(void)
{
	SBox sbx;
	UBox ubx;

	printf("%p %p %p\n", &sbx.mem1, &sbx.mem2, &sbx.mem3);
	printf("%p %p %p\n", &ubx.num1, &ubx.num2, &ubx.num3);

	return 0;
}