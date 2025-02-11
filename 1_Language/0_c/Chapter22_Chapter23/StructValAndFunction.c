#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
	int xtest;
	int ytest;
} Point;

void ShowPosition(Point pos)
{
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void)
{
	Point cen;
	printf("Input current pos: ");
	scanf_s("%d %d", &cen.xpos, &cen.ypos);
	cen.xtest = 10;
	cen.ytest = 20;
	return cen;
}

int main(void)
{
	Point curPos = GetCurrentPosition();
	ShowPosition(curPos);

	return 0;
}