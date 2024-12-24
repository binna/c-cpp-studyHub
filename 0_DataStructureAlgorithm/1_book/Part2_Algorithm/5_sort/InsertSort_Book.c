#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length)
{
	int i = 0, j = 0, value = 0;

	for (i = 1; i < Length; i++)
	{
		if (DataSet[i - 1] <= DataSet[i])
			continue;

		value = DataSet[i];

		for (j = 0; j < i; j++)
		{
			if (DataSet[j] > value)
			{
				// memmove 함수
				// 메모리의 내용을 이동시키는 기능을 수행한다
				// 배열처럼 연속된 데이터를 단번에 이동시킬 때 아주 유용하다
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void)
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	InsertionSort(DataSet, Length);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}