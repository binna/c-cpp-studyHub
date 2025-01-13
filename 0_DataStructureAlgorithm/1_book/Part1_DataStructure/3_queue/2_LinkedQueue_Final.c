#include "2_LinkedQueue_Final.h"

void LQ_CreateQueue2(LinkedListQueue** Queue)
{
	(*Queue) = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));

	if ((*Queue) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;

	(*Queue)->Count = 0;
}

// 삽입연산은 후단의 위치를 가리키는 Rear가 관리
void LQ_Enqueue2(LinkedListQueue* Queue, char* NewData)
{
	if (Queue == NULL)
	{
		printf("System Notice : Non-existent Queue\n");
		return;
	}

	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	NewNode->Data = (char*)malloc(sizeof(char) * strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	strcpy_s(NewNode->Data, strlen(NewData) + 1, NewData);
	NewNode->NextNode = NULL;

	if (Queue->Rear == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
	
	Queue->Count += 1;
}

// 제거연산은 전단의 위치를 가리키는 Front가 관리
Node* LQ_Dequeue2(LinkedListQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Non-existent Queue\n");
		return NULL;
	}

	if (Queue->Front == NULL)
	{
		printf("System Notice : No Data\n");
		return NULL;
	}

	Node* DeletedNode = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else 
	{
		Queue->Front = Queue->Front->NextNode;
	}

	Queue->Count -= 1;
	
	return DeletedNode;
}

int LQ_IsEmpty2(LinkedListQueue* Queue)
{
	return (Queue->Count == 0);
}

int LQ_GetSize2(LinkedListQueue* Queue)
{
	return Queue->Count;
}

void LQ_Print2(LinkedListQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Non-existent Queue\n");
		return;
	}

	if (LQ_IsEmpty2(Queue))
	{
		printf("Circular List ==================================\n");
		printf("No Data\n");
		printf("================================================\n");
		return;
	}
	if (Queue->Front == NULL)
	{
		return;
	}

	printf("Circular List ==================================\n");
	printf("Size : %d\n", LQ_GetSize2(Queue));

	int Count = 1;
	Node* TargetNode = Queue->Front;

	while (TargetNode != NULL)
	{
		printf(">> Data[%d] : %s\n", Count++, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}

	printf("================================================\n");
}