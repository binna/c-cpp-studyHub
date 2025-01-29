#include <stdio.h>

void ShowAllString(int argc, char* argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
}

//void ShowArr2D(int (*arr2d)[4], int column)
void ShowArr2D(int arr2d[][4], int column)
{
	int i, j;
	for (i = 0; i < column; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr2d[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	char* str[3] = { "C Programming", "C++ Programming", "JAVA Programming" };
	ShowAllString(3, str);

	int arr2d[2][4] = { 1,2,3,4,5,6,7,8 };
	ShowArr2D(arr2d, sizeof(arr2d) / sizeof(arr2d[0]));

	return 0;
}