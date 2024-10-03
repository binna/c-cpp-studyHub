#include "1_CircularLinkedList_Book.h"

int main(void)
{
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	// 노드 5개 추가
	for (int i = 0; i < 5; i++)
	{
		NewNode = CDLL_CreateNode1(i);
		CDLL_AppendNode1(&List, NewNode);
	}

	// 리스트 출력
	Count = CDLL_GetNodeCount1(List);
	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt1(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 리스트의 세 번째 칸 뒤에 노드 삽입
	printf("\nInserting 3000 After [2]...\n\n");

	Current = CDLL_GetNodeAt1(List, 2);
	NewNode = CDLL_CreateNode1(3000);
	CDLL_InsertAfter1(Current, NewNode);

	// 리스트 출력
	// 노드 수의 2배만큼 루프를 돌며 환형임을 확인
	Count = CDLL_GetNodeCount1(List);
	for (int i = 0; i < Count * 2; i++)
	{
		if (i == 0)
			Current = List;
		else
			Current = Current->NextNode;

		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 모든 노드를 메모리에서 제거
	printf("\nDestroying List...\n\n");

	Count = CDLL_GetNodeCount1(List);

	for (int i = 0; i < Count; i++)
	{
		Current = CDLL_GetNodeAt1(List, 0);

		if (Current != NULL)
		{
			CDLL_RemoveNode1(&List, Current);
			CDLL_DestroyNode1(Current);
		}
	}

	return 0;
}