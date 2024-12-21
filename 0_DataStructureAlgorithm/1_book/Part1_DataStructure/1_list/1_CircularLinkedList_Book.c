#include "1_CircularLinkedList_Book.h"

// 노드 생성
Node* CDLL_CreateNode1(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 추가
void CDLL_AppendNode1(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head
	if (*Head == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		
		Node* Tail = (*Head)->PrevNode;		// 테일과 헤드 사이에 NewNode를 삽입
		
		Tail->NextNode->PrevNode = NewNode;	// Tail->NextNode->PrevNode는 결국 Head의 Prev
											// Head의 Prev는 새로 추가하는 노드여야 함
		Tail->NextNode = NewNode;			// 테일 뒤에 새로운 노드 삽입
											// 새로운 노드가 이제 테일

		NewNode->NextNode = *Head;
		NewNode->PrevNode = Tail;			// 기존의 테일을 새로운 테일의 PrevNode가 가리킴
	}
}

// 노드 삽입
void CDLL_InsertAfter1(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}

// 노드 소멸
void CDLL_DestroyNode1(Node* Node)
{
	free(Node);
}

// 노드 제거
// 책 상으로는 아래와 같이 코드가 짜여 있으나 전체 삭제시 문제 발생함
void CDLL_RemoveNode1(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;	// 테일의 Prev(=테일 정보)의 Next(=헤드 정보) = 헤드의 다음 노드
		(*Head)->NextNode->PrevNode = Remove->PrevNode;	// 테일의 Next의 Prev(=새로운 헤드에 테일 정보 저장) = 헤드의 Prev(= 테일)

		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

// 노드 탐색
Node* CDLL_GetNodeAt1(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 수 세기
int CDLL_GetNodeCount1(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;

		if (Current == Head)
			break;
	}

	return Count;
}

// 출력
void PrintNode(Node* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);

	printf("  Current: %d", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->NextNode->Data);
}