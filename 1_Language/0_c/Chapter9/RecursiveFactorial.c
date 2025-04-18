#include <stdio.h>

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main(void)
{
	printf("!1 = %d\n", Factorial(1));
	printf("!1 = %d\n", Factorial(2));
	printf("!1 = %d\n", Factorial(3));
	printf("!1 = %d\n", Factorial(4));
	printf("!1 = %d\n", Factorial(9));

	return 0;
}