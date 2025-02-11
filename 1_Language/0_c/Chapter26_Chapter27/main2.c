#include <stdio.h>
#include "areaArith.h"
#include "roundArith.h"

int main(void)
{
	printf("%g\n", TriangleArea(4, 2));
	printf("%g\n", CircleArea(3));

	printf("%g\n", RectangleRound(2.5, 5.2));
	printf("%g\n", SquareRound(3));

	return 0;
}