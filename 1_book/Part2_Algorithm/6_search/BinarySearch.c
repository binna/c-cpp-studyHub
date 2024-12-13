#include <stdio.h>
#include <stdlib.h>

#include "Score.h"

typedef int ElementType;

#pragma region 이진 탐색
ElementType BinarySearch1(ElementType DataSet[], int Size, ElementType Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	// 탐색 범위의 크기가 0일 될 때까지 루프를 반복한다
	while (Left <= Right)
	{
		// 중앙 요소의 위치를 계산한다
		Mid = (Left + Right) / 2;

		// 중앙 요소가 담고 있는 값과 목표 값이 일치하면 해당 요소를 반환하다
		if (Target == DataSet[Mid])
			return DataSet[Mid];
		else if (Target > DataSet[Mid])
			Left = Mid + 1; 
		else
			Right = Mid - 1;
	}

	return NULL;
}
#pragma endregion

#pragma region 이진 탐색 예제 - 콩쥐 문제
Score* BinarySearch2(Score ScoreList[], int Size, double Target)
{
	int Left, Right, Mid;

	Left = 0;
	Right = Size - 1;

	while (Left <= Right)
	{
		Mid = (Left + Right) / 2;

		if (Target == ScoreList[Mid].score)
			return &(ScoreList[Mid]);
		else if (Target > ScoreList[Mid].score)
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}

	return NULL;
}

// 정렬 알고리즘은 
//  : 비교 함수가 반환한 양수, 음수, 0을 사용해 두 값의 상대적인 위치를 결정
// 비교 함수가 양수를 반환할 때만 교환이 이루어진다
int CompareScore(const void* _elem1, const void* _elem2)
{
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}
#pragma endregion


int Partition(Score ScoreList[], int Left, int Right)
{
	int First = Left;
	Score Pivot = ScoreList[Left];

	Left += 1;

	while (Left <= Right)
	{
		while (ScoreList[Left].score <= Pivot.score && Left < Right)
			Left += 1;

		while (ScoreList[Right].score > Pivot.score && Left <= Right)
			Right -= 1;

		if (Left >= Right)
			break;

		Score Temp = ScoreList[Left];
		ScoreList[Left] = ScoreList[Right];
		ScoreList[Right] = Temp;
	}

	ScoreList[First] = ScoreList[Right];
	ScoreList[Right] = Pivot;
	return Right;
}

void QuickSort(Score ScoreList[], int Left, int Right)
{
	if (Left < Right)
	{
		int idx = Partition(ScoreList, Left, Right);
		QuickSort(ScoreList, Left, idx - 1);
		QuickSort(ScoreList, idx + 1, Right);
	}
}

int main(void)
{
	//int DataSet[] = { 1,7,11,12,14,23,67,139,672,871 };
	//int Length = sizeof DataSet / sizeof DataSet[0];

	//printf("%d\n", BinarySearch1(DataSet, Length, 55));

	//////////////////////////////////////////////////////////

	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	Score* found = NULL;

	// 점수를 오름차순으로 정렬
	//qsort(DataSet, Length, sizeof(Score), CompareScore);
	QuickSort(DataSet, 0, Length - 1);

	// 671.78점을 받은 학생 찾기
	found = BinarySearch2(DataSet, Length, 671.78);

	printf("found : %d %f\n", found->number, found->score);

	return 0;
}