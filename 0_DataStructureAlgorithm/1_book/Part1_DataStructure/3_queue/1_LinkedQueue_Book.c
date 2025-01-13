#include "1_LinkedQueue_Book.h"

void LQ_CraeteQueue1(LinkedQueue** Queue)
{
	// 큐를 자유저장소에 생성
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue1(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty1(Queue))
	{
		Node* Popped = LQ_Dequeue1(Queue);
		LQ_DestroyNode1(Popped);
	}

	// 큐를 자유저장소에서 해제
	free(Queue);
}

Node* LQ_CreateNode1(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy_s(NewNode->Data, strlen(NewData) + 1, NewData);	// 데이터를 저장

	NewNode->NextNode = NULL;

	return NewNode;
}

void LQ_DestroyNode1(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LQ_Enqueue1(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count += 1;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count += 1;
	}
}

Node* LQ_Dequeue1(LinkedQueue* Queue)
{
	// 함수가 반환할 최상위 노드
	Node* Front = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count--;

	return Front;
}

int LQ_IsEmpty1(LinkedQueue* Queue)
{
	return (Queue->Front == NULL);
}