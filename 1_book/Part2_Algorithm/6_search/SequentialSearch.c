#include "SingleLinkedList.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

#pragma region 전진 이동법
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
#pragma endregion

#pragma region 전위법
// 전위법
// 탐색된 항목을 바로 이전 항목과 교환한다 -> 많은 선택을 받은 데이터를 데이터 집합의 앞쪽에 보낸다
Node* SLL_Transpose(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* PPrevious = NULL;		// 이전노드의 이전노드
	Node* Previous = NULL;		// 이전노드
	Node* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;
			if (Previous != NULL)
			{
				if (PPrevious != NULL)
					PPrevious->NextNode = Current;
				else
					(*Head) = Current;

				Previous->NextNode = Current->NextNode;
				Current->NextNode = Previous;
			}
			break;
		}

		PPrevious = Previous;
		Previous = Current;
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

// 계수법
// 데이터 집합 내의 각 요소들이 탐색된 횟수를 별도의 공간에 저장해두고,
// 탐색된 횟수가 높은 순으로 데이터 집합을 재구성하는 전략의 알고리즘

// 1
// 가장 뒤에 있는 데이터가 가장 많은 선택을 받더라도,
// 데이터의 집합이 크면 가장 앞으로 올 수 있다는 것을 보장 받을 수 없음
// 왜? 단계적으로 이동하니깐
FCMNode1* SLL_FrequencyCountMethod1(FCMNode1** Head, int Target)
{
	FCMNode1* Current = (*Head);
	FCMNode1* PPrevious = NULL;
	FCMNode1* Previous = NULL;
	FCMNode1* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;

			// 대상 데이터 발견시 카운트 증가
			Current->Cnt += 1;

			// 재배치 필요 여부 확인
			if (Previous != NULL && Previous->Cnt < Current->Cnt)
			{
				if (PPrevious != NULL)
					PPrevious->NextNode = Current;
				else
					(*Head) = Current;

				// 연결 리스트 노드 재배치
				Previous->NextNode = Current->NextNode;
				Current->NextNode = Previous;
			}
			break;
		}

		PPrevious = Previous;
		Previous = Current;
		Current = Current->NextNode;
	}
	return Match;
}

// 2
// 선택된 데이터가 즉시 올바른 위치로 이동하도록 구현하여 개선
FCMNode2* SLL_FrequencyCountMethod2(FCMNode2** Head, int Target)
{
	FCMNode2* Current = (*Head);
	FCMNode2* Match = NULL;

	while (Current != NULL)
	{
		if (Current->Data == Target)
		{
			Match = Current;

			// 대상 데이터 발견시 카운트 증가
			Current->Cnt += 1;

			// 검색된 데이터 기준, 우선순위가 낮은 것이 있는지 탐색
			FCMNode2* Previous = Current->PrevNode;
			while (Previous != NULL && Previous->Cnt < Current->Cnt)
			{
				Previous = Previous->PrevNode;
			}

			// 없는 경우, 재배치 필요 없음
			if (Previous == Current->PrevNode)
				break;

			if (Current->PrevNode != NULL)
				Current->PrevNode->NextNode = Current->NextNode;

			if (Current->NextNode != NULL)
				Current->NextNode->PrevNode = Current->PrevNode;

			if (Previous != NULL)
			{
				if (Previous->NextNode != NULL)
					Previous->NextNode->PrevNode = Current;

				Current->NextNode = Previous->NextNode;
				Previous->NextNode = Current;
				Current->PrevNode = Previous;
			}
			else
			{
				Current->NextNode = (*Head);
				(*Head)->PrevNode = Current;
				(*Head) = Current;
			}
			break;
		}

		Current = Current->NextNode;
	}
	return Match;
}
#pragma endregion

int main(void)
{
#pragma region 전진이동법, 전위법 테스트
	//int DataSet[] = { 5,6,1,2,3,4 };
	//int size = sizeof DataSet / sizeof DataSet[0];

	//for (int i = 0; i < size; i++)
	//{
	//	printf("%d ", DataSet[i]);
	//}
	//printf("\n");

	////SLL_MoveToFrontArray(DataSet, size, 3);
	////SLL_MoveToFrontArray(DataSet, size, 1);

	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);
	//SLL_TransposeArray(DataSet, size, 3);

	//for (int i = 0; i < size; i++)
	//{
	//	printf("%d ", DataSet[i]);
	//}
#pragma endregion

#pragma region 계수법 1 테스트
	//// 데이터 생성 ////////////////////////////////////////////
	//FCMNode1* Node1 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node1->Data = 1;
	//Node1->Cnt = 0;
	//Node1->NextNode = NULL;

	//FCMNode1* Node2 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node2->Data = 2;
	//Node2->Cnt = 0;
	//Node2->NextNode = NULL;


	//FCMNode1* Node3 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node3->Data = 3;
	//Node3->Cnt = 0;
	//Node3->NextNode = NULL;

	//FCMNode1* Node4 = (FCMNode1*)malloc(sizeof(FCMNode1));
	//Node4->Data = 4;
	//Node4->Cnt = 0;
	//Node4->NextNode = NULL;

	//Node1->NextNode = Node2;
	//Node2->NextNode = Node3;
	//Node3->NextNode = Node4;

	//FCMNode1* Head = Node1;
	////////////////////////////////////////////////////////////

	//FCMNode1* Current;

	//printf("------------------------\n");
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
	//
	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 1);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 3);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
	//
	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 2);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//if (SLL_FrequencyCountMethod1(&Head, 5) == NULL)
	//{
	//	printf("노드(5)를 찾을 수 없습니다.\n");
	//}

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL)
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");

	//printf("------------------------\n");
	//SLL_FrequencyCountMethod1(&Head, 4);
	//Current = Head;
	//while (Current != NULL) 
	//{
	//	printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
	//	Current = Current->NextNode;
	//}
	//printf("------------------------\n");
#pragma endregion

#pragma region 계수법 2 테스트
	//// 데이터 생성 ////////////////////////////////////////////
	FCMNode2* Node1 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node1->Data = 1;
	Node1->Cnt = 0;
	Node1->PrevNode = NULL;
	Node1->NextNode = NULL;

	FCMNode2* Node2 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node2->Data = 2;
	Node2->Cnt = 0;
	Node2->PrevNode = NULL;
	Node2->NextNode = NULL;

	FCMNode2* Node3 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node3->Data = 3;
	Node3->Cnt = 0;
	Node3->PrevNode = NULL;
	Node3->NextNode = NULL;

	FCMNode2* Node4 = (FCMNode2*)malloc(sizeof(FCMNode2));
	Node4->Data =4;
	Node4->Cnt = 0;
	Node4->PrevNode = NULL;
	Node4->NextNode = NULL;

	Node2->PrevNode = Node1;
	Node3->PrevNode = Node2;
	Node4->PrevNode = Node3;

	Node1->NextNode = Node2;
	Node2->NextNode = Node3;
	Node3->NextNode = Node4;
	

	FCMNode2* Head = Node1;
	////////////////////////////////////////////////////////////
	FCMNode2* Current;
	printf("------------------------\n");
	Current = Head;
	while (Current != NULL) 
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 2);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 3);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");

	printf("------------------------\n");
	SLL_FrequencyCountMethod2(&Head, 4);
	Current = Head;
	while (Current != NULL)
	{
		printf("Data: %d, Count: %d\n", Current->Data, Current->Cnt);
		Current = Current->NextNode;
	}
	printf("------------------------\n");
	
#pragma endregion

	return 0;
}