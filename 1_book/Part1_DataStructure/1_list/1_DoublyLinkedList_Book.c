#include "1_DoublyLinkedList_Book.h"

// 노드 생성
Node* DLL_CreateNode1(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 추가
void DLL_AppendNode1(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;		// 기존의 테일을 새 테일의 PrevNode를 가리킴
	}
}

// 노드 삽입
void DLL_InsertAfter1(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}

// 노드 소멸
void DLL_DestroyNode1(Node* Node)
{
	free(Node);
}

// 노드 제거
void DLL_RemoveNode1(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;

		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;

		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// 노드 탐색
Node* DLL_GetNodeAt1(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 수 세기
int DLL_GetNodeCount1(Node* Head)
{
	unsigned int Count = 0;

	Node* Current = Head;
	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count += 1;
	}

	return Count;
}