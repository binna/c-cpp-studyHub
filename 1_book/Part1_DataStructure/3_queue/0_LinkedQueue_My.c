#include "0_LinkedQueue_My.h"

void LQ_CreateQueue0(LinkedListQueue** Queue)
{
	(*Queue) = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));

	if ((*Queue) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->size = 0;
	(*Queue)->Tail = NULL;
	(*Queue)->Nodes = NULL;
}

void LQ_Enqueue0(LinkedListQueue* Queue, ElementType NewData)
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

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	if (Queue->Tail == NULL)
	{
		Queue->Tail = NewNode;
		Queue->Nodes = NewNode;
	}
	else
	{
		Queue->Tail->NextNode = NewNode;
		Queue->Tail = NewNode;
	}

	Queue->size += 1;
}

void LQ_Dequeue0(LinkedListQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Non-existent Queue\n");
		return;
	}

	if (LQ_IsEmpty0(Queue))
	{
		printf("System Notice : No Deleted Data\n");
		return;
	}

	Node* TargetNode = Queue->Nodes;

	Queue->Nodes = TargetNode->NextNode;
	Queue->size -= 1;

	free(TargetNode);
}

int LQ_IsEmpty0(LinkedListQueue* Queue)
{
	return (Queue->size == 0);
}

int LQ_GetSize0(LinkedListQueue* Queue)
{
	return Queue->size;
}

void LQ_Print0(LinkedListQueue* Queue)
{
	if (LQ_IsEmpty0(Queue))
	{
		printf("Circular List ==================================\n");
		printf("No Data\n");
		printf("================================================\n");
		return;
	}

	printf("Circular List ==================================\n");
	printf("Size : %d\n", LQ_GetSize0(Queue));

	int Count = 1;
	Node* TargetNode = Queue->Nodes;

	while (TargetNode != NULL)
	{
		printf(">> Data[%d] : %d\n", Count++, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
	}

	printf("================================================\n");
}