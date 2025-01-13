//#include "1_CircularLinkedList_Book.h"
//
//int main(void)
//{
//	int Count = 0;
//	Node* List = NULL;
//	Node* NewNode = NULL;
//	Node* Current = NULL;
//
//	// 노드 5개 추가
//	for (int i = 0; i < 5; i++)
//	{
//		NewNode = CDLL_CreateNode1(i);
//		CDLL_AppendNode1(&List, NewNode);
//	}
//
//	// 리스트 출력
//	Count = CDLL_GetNodeCount1(List);
//	for (int i = 0; i < Count; i++)
//	{
//		Current = CDLL_GetNodeAt1(List, i);
//		printf("List[%d] : %d\n", i, Current->Data);
//	}
//
//	// 리스트의 세 번째 칸 뒤에 노드 삽입
//	printf("\nInserting 3000 After [2]...\n\n");
//
//	Current = CDLL_GetNodeAt1(List, 2);
//	NewNode = CDLL_CreateNode1(3000);
//	CDLL_InsertAfter1(Current, NewNode);
//
//	// 리스트 출력
//	// 노드 수의 2배만큼 루프를 돌며 환형임을 확인
//	Count = CDLL_GetNodeCount1(List);
//	for (int i = 0; i < Count * 2; i++)
//	{
//		if (i == 0)
//			Current = List;
//		else
//			Current = Current->NextNode;
//
//		printf("List[%d] : %d\n", i, Current->Data);
//	}
//
//	// 모든 노드를 메모리에서 제거
//	printf("\nDestroying List...\n\n");
//
//	Count = CDLL_GetNodeCount1(List);
//
//	for (int i = 0; i < Count; i++)
//	{
//		Current = CDLL_GetNodeAt1(List, 0);
//
//		if (Current != NULL)
//		{
//			CDLL_RemoveNode1(&List, Current);
//			CDLL_DestroyNode1(Current);
//		}
//	}
//
//	return 0;
//}


#include "2_CircularLinkedList_Final.h"

int main(void)
{
	Node* list = NULL;
	Node* TargetNode = NULL;

	CDLL_AppendNode2(&list, 1111);

	printf(">>>>>>> Size : %d\n", CDLL_GetNodeSize2(list));

	for (int i = 0; i < 5; i++)
	{
		CDLL_AppendNode2(&list, i);
	}
	
	TargetNode = list;
	for (int i = 0; i < 15; i++)
	{
		printf("i[%d] : %d\n", i, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}

	printf("========================================\n");

	CDLL_Print2(list);

	printf("========================================\n");

	CDLL_InsertNode2(&list, 0, 100000);

	TargetNode = list;
	for (int i = 0; i < 18; i++)
	{
		printf("i[%d] : %d\n", i, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}

	printf("========================================\n");

	CDLL_Print2(list);

	printf("========================================\n");

	CDLL_InsertNode2(&list, 7, 700000);
	CDLL_InsertNode2(&list, 6, 600000);
	CDLL_InsertNode2(&list, 5, 500000);
	CDLL_InsertNode2(&list, 3, 300000);

	CDLL_Print2(list);

	printf("========================================\n");

	for (int i = 0; i < 24; i++)
	{
		printf("i[%d] : %d\n", i, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}

	printf("========================================\n");

	printf(">>>>>>> Size : %d\n", CDLL_GetNodeSize2(list));
	CDLL_Print2(list);

	printf("========================================\n");

	CDLL_ModifyNode2(&list, 0, 100);
	CDLL_ModifyNode2(&list, 3, 300);
	CDLL_ModifyNode2(&list, 5, 500);
	CDLL_ModifyNode2(&list, 7, 700);
	CDLL_ModifyNode2(&list, 6, 600);
	CDLL_ModifyNode2(&list, 8, 600);

	printf(">>>>>>> Size : %d\n", CDLL_GetNodeSize2(list));
	CDLL_Print2(list);

	printf("========================================\n");

	Node* SelectResult = CDLL_GetNode2(list, 0);
	printf(">>>>>>> 조회 : %d\n", SelectResult == NULL ? -1 : SelectResult->Data);
	
	SelectResult = CDLL_GetNode2(list, 9);
	printf(">>>>>>> 조회 : %d\n", SelectResult == NULL ? -1 : SelectResult->Data);

	SelectResult = CDLL_GetNode2(list, 15);
	printf(">>>>>>> 조회 : %d\n", SelectResult == NULL ? -1 : SelectResult->Data);

	CDLL_Print2(list);

	printf("========================================\n");
	printf("========================================\n");

	printf(">>>>>>> Size : %d\n", CDLL_GetNodeSize2(list));
	int Size = CDLL_GetNodeSize2(list);
	for (int i = 0; i < Size; i++)
	{
		SelectResult = CDLL_GetNode2(list, 0);
		CDLL_RemoveNode2ByNode(&list, SelectResult);
	}
	CDLL_Print2(list);

	printf("========================================\n");
	printf("========================================\n");

	return 0;
}