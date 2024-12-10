#include <stdio.h>

// 개선된 버블 정렬
// 버블 정렬은 미리 정렬되어 있어도 모든 루프를 돌며 비교를 수행하는 미련하기 그지없는 알고리즘!
// => 정렬되어 있는 경우에는 루프를 취소하고 빠져나오도록 개선 완료

void Bubble(int* data, int lengh)
{
	int i, j, temp, isSort;
	for (i = 0; i < lengh - 1; i++)
	{
		isSort = 1;

		for (j = 0; j < lengh - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				isSort = 0;
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}

		if (isSort == 1)
		{
			printf("in %d\n", i);
			break;
		}
	}
}

int main(void)
{
	int data1[] = { 5,1,6,4,2,3 };
	int data2[] = { 1,2,3,4,6,5 };
	int size = sizeof(data1) / sizeof(int);

	Bubble(data2, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", data2[i]);
	}
}