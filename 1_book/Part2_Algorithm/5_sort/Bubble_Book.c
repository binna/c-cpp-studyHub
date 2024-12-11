#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
	int i = 0, j = 0, temp = 0;

	// 바깥에 있는 for 루프는
	// 데이터 집합의 크기만큼 내부에 있는 for 루프를 실행한다
	for (i = 0; i < Length - 1; i++)
	{
		// 내부에 있는 for 루프는 
		//		바깥에 있는 for 루프가 한 번 실행될 때마다 그 반복횟수가 줄어든다
		// 외부에 있는 for 루프는 
		//		한 번 실행할 때마다 정렬 대상으로 삼는 데이터 집합의 크기가 줄어들기 때문이다
		for (j = 0; j < Length - (i + 1); j++)
		{
			if (DataSet[j] > DataSet[j + 1])
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main(voie)
{
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	BubbleSort(DataSet, Length);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");

	return 0;
}