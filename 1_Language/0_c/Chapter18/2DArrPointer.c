#include <stdio.h>

int main(void)
{
	int arr1[3][2];
	int arr2[2][3];

	printf("arr1 : %p\n\n", arr1);

	printf("arr1 + 1 : %p\n", arr1 + 1);
	printf("arr1 + 2 : %p\n\n", arr1 + 2);

	printf("arr2 : %p\n", arr2);
	printf("arr2 + 1 : %p\n", arr2 + 1);
	printf("arr2 + 2 : %p\n\n", arr2 + 2);

	printf("(arr1 + 1)[0] : %p\n", (arr1 + 1)[0]);
	printf("(arr1 + 1)[1] : %p\n\n", (arr1 + 1)[1]);

	printf("(arr1 + 2)[0] : %p\n", (arr1 + 2)[0]);
	printf("(arr1 + 2)[1] : %p\n\n", (arr1 + 2)[1]);

	printf("(arr1 + 1)[4] : %p\n", (arr1 + 1)[4]);
	printf("(arr1 + 2)[4] : %p\n\n", (arr1 + 2)[4]);

	return 0;
}