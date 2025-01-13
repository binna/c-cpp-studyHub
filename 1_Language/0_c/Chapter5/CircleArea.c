#include <stdio.h>

int main(void)
{
	double rad;
	double area;
	printf("원의 반지름 입력: ");
	scanf_s("%lf", &rad);

	area = rad * 3.14195f;
	printf("원의 넓이: %f\n", area);

	return 0;
}