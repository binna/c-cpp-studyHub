#include "SingleLinkedList.h"

#include <stdio.h>
#include <string.h>

#pragma region 순차 탐색
Node* SLL_SequentialSearch(Node* Head, int Target)
{
	Node* Current = Head;
	Node* Match = NULL;

	while (Current != NULL)
	{
		// 찾고자 하는 값을 해당 노드가 가지고 있으면
		// 노드의 주소를 Match에 저장한다
		if (Current->Data == Target)
		{
			Match = Current;
			break;
		}

		// 현재 노드에 찾는 값이 없으면
		// 다음 노드를 조사한다
		Current = Current->NextNode;
	}

	// 찾는 값을 갖고 있는 노드의 주소를 반환한다
	return Match;
}
#pragma endregion

#pragma region 자기 구성 순차 탐색 - 자주 사용하는 항목을 데이터 집합의 앞쪽에 배치
// 전진 이동법
// 어느 항목이 한 번 탐색하고 나면, 그 항목을 데이터 집합의 가장 앞에 위치시키는 방법
Node* SLL_MoveToFront(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* Previos = NULL;
	Node* Match = NULL;

	while (Current != NULL)
	{
		// 찾고자 하는 값을 해당 노드가 갖고 있으면
		// 노드의 주소를 Match에 저장한다
		if (Current->Data == Target)
		{
			Match = Current;

			if (Previos != NULL)
			{
				// 자신의 앞 노드와 다음 노드를 연결
				Previos->NextNode = Current->NextNode;

				// 자신을 리스트의 가장 앞으로 옮기기
				Current->NextNode = (*Head);
				(*Head) = Current;
			}
			break;
		}
		Previos = Current;
		Current = Current->NextNode;
	}
	
	return Match;
}

// 전진 이동법 - 배열 버전
void SLL_MoveToFrontArray(int DataSet[], int Length, int Target)
{
	for (int i = 0; i < Length; i++)
	{
		if (DataSet[i] == Target)
		{
			memmove(&DataSet[1], &DataSet[0], sizeof(int) * i);
			DataSet[0] = Target;
			break;
		}
	}
}

// 전위법
// 탐색된 항목을 바로 이전 항목과 교환한다 -> 많은 선택을 받은 데이터를 데이터 집합의 앞쪽에 보낸다
Node* SLL_Transpose(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* PPrevios = NULL;		// 이전노드의 이전노드
	Node* Previos = NULL;		// 이전노드
	Node* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;
			if (Previos != NULL)
			{
				if (PPrevios != NULL)
					PPrevios->NextNode = Current;
				else
					(*Head) = Current;

				Previos->NextNode = Current->NextNode;
				Current->NextNode = Previos;
			}
			break;
		}

		PPrevios = Previos;
		Previos = Current;
		Current = Current->NextNode;
	}

	return Match;
}

// 전위법 - 배열 버전
void SLL_TransposeArray(int DataSet[], int Length, int Target)
{
	for (int i = 0; i < Length; i++)
	{
		if (DataSet[i] == Target)
		{
			if (i != 0)
			{
				int Temp = DataSet[i];
				DataSet[i] = DataSet[i - 1];
				DataSet[i - 1] = Temp;
			}
			break;
		}
	}
}
#pragma endregion

int main(void)
{
	int DataSet[] = { 5,6,1,2,3,4 };
	int size = sizeof DataSet / sizeof DataSet[0];

	for (int i = 0; i < size; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");

	//SLL_MoveToFrontArray(DataSet, size, 3);
	//SLL_MoveToFrontArray(DataSet, size, 1);

	SLL_TransposeArray(DataSet, size, 3);
	SLL_TransposeArray(DataSet, size, 3);
	SLL_TransposeArray(DataSet, size, 3);
	SLL_TransposeArray(DataSet, size, 3);
	SLL_TransposeArray(DataSet, size, 3);
	SLL_TransposeArray(DataSet, size, 3);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", DataSet[i]);
	}

	return 0;
}