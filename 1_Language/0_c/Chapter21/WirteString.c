#include <stdio.h>

int main(void)
{
	const char* str = "Simple String";

	printf("1. puts test ------ \n");
	puts(str);
	puts("So Simple String");

	printf("2. puts test ------ \n");
	fputs(str, stdout); printf("\n");
	fputs("So Simple String", stdout); printf("\n");

	printf("3. end of main ------ \n");

	return 0;
}