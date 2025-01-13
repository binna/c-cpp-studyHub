#include <stdio.h>

int main(void)
{
	printf("literal int size: %d", sizeof(7));
	printf("literal double size: %d", sizeof(7.14));
	printf("literal char size: %d", sizeof('A'));
	
	return 0;
}