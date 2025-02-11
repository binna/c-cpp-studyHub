#include <stdio.h>

typedef struct point
{
	int xpos;
	int ypos;
	int testPos;
} Point;

Point AddPoint(Point pos1, Point pos2)
{
	Point pos = { pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos, 300 };
	return pos;
}

Point MinusPoint(Point pos1, Point pos2)
{
	Point pos = { pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos, 400 };
	return pos;
}

void main(void)
{
	Point pos1 = { 5,6, 100 };
	Point pos2 = { 2,9, 200 };
	Point result;

	result = AddPoint(pos1, pos2);
	printf("[%d, %d]\n", result.xpos, result.ypos);

	result = MinusPoint(pos1, pos2);
	printf("[%d, %d]\n", result.xpos, result.ypos);

	return 0;
}