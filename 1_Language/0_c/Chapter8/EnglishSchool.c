#include <stdio.h>

int main(void)
{
	int num;
	printf("1이상 5이하의 정수 입력: ");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		printf("1 One\n");
		break;
	case 2:
		printf("2 Two\n");
		break;
	case 3:
		printf("3 Three\n");
		break;
	case 4:
		printf("4 Four\n");
		break;
	case 5:
		printf("5 Five\n");
		break;
	case 6:
		printf("5 Five\n");
		break;
	default:
		printf("I don't know!\n");
	}

	return 0;
}