#include <stdio.h>

int main(void)
{
	int total = 0;
	int i, num;
	printf("0ºÎÅÍ num±îÁöÀÇ µ¡¼À, numÀº?");
	scanf_s("%d", &num);

	for (int i = 0; i < num + 1; i++)
	{
		total += 1;
	}

	printf("0ºÎÅÍ %d±îÁö µ¡¼À °á°ú : %d\n", num, total);

	return 0;
}