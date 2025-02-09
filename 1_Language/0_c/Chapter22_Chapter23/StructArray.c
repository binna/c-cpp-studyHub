#include <stdio.h>

struct point
{
	int xpos;
	int ypos;
};

int main(void)
{
	struct point arr[3];
	//int i;

	for (int i = 0; i < 3; i++)
	{
		printf("점의 좌표 입력 : ");
		scanf_s("%d %d", &arr[i].xpos, &arr[i].ypos);
	}

	for (int i = 0; i < 3; i++)
	{
		printf("[%d, %d]", arr[i].xpos, arr[i].ypos);
	}

	return 0;
}
