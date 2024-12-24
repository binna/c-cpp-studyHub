#include "0_CircularQueue_My.h"

void CQ_CreateQueue0(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	if ((*Queue) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->Data = (ElementType*)malloc(sizeof(ElementType) * (Capacity + 1));

	if ((*Queue)->Data == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_Enqueue0(CircularQueue* Queue, ElementType NewData)
{
	if (CQ_IsFULL0(Queue))
	{
		printf("Sysatem Notice : Full Queue\n");
		return;
	}

	int Position = Queue->Front;

	if (Queue->Front >= Queue->Capacity)
	{
		Position = 0;
	}
	else
	{
		Position += 1;
	}

	Queue->Data[Position] = NewData;
	Queue->Front = Position;
}

void CQ_Dequeue0(CircularQueue* Queue)
{
	if (CQ_IsEmpty0(Queue))
	{
		printf("System Notice : No Deleted Data\n");
		return;
	}

	int Position = Queue->Rear;

	if (Queue->Rear >= Queue->Capacity)
	{
		Position = 0;
	}
	else
	{
		Position += 1;
	}

	Queue->Rear = Position;
}

int CQ_IsEmpty0(CircularQueue* Queue)
{
	return Queue->Front == Queue->Rear;
}

int CQ_IsFULL0(CircularQueue* Queue)
{
	if (Queue->Rear == 0)
		return Queue->Front == Queue->Capacity;

	return (Queue->Rear - 1) == Queue->Front;
}

int CQ_GetSize0(CircularQueue* Queue)
{
	if (CQ_IsEmpty0(Queue))
		return 0;

	if (Queue->Front > Queue->Rear)
		return Queue->Front - Queue->Rear;

	return (Queue->Capacity + 1 - Queue->Rear) + (0 - Queue->Front);
}

void CQ_Print0(CircularQueue* Queue)
{
	if (CQ_IsEmpty0(Queue))
	{
		printf("Circular List ==================================\n");
		printf("No Data\n");
		printf("================================================\n");
		return;
	}

	int Count = 1;

	printf("Circular List ==================================\n");
	printf("%d %d / Size : %d\n", Queue->Front, Queue->Rear, CQ_GetSize0(Queue));

	if (Queue->Front > Queue->Rear) 
	{
		for (int i = Queue->Rear + 1; i < Queue->Capacity + 1; i++)
		{
			printf(">> Data[%d] : %d\n", Count++, Queue->Data[i]);
		}
		printf("================================================\n");
		return;
	}
	
	for (int i = Queue->Rear + 1; i < Queue->Capacity + 1; i++)
	{
		printf(">> Data[%d] : %d\n", Count++, Queue->Data[i]);
	}
	for (int i = 0; i <= Queue->Front; i++)
	{
		printf(">> Data[%d] : %d\n", Count++, Queue->Data[i]);
	}
	printf("================================================\n");
}