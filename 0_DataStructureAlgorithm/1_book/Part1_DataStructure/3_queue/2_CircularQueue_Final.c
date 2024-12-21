#include "2_CircularQueue_Final.h"

void CQ_CreateQueue2(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	if ((*Queue) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->Nodes = (ElementType*)malloc(sizeof(ElementType) * (Capacity + 1));

	if ((*Queue)->Nodes == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_Enqueue2(CircularQueue* Queue, ElementType NewData)
{
	if (Queue == NULL)
	{
		printf("System Notice : Not Found Queue\n");
		return;
	}

	if (CQ_IsFull2(Queue))
	{
		printf("System Notice : FUll Queue\n");
		return;
	}

	int Position = 0;

	if (Queue->Rear == Queue->Capacity)
	{
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else 
	{
		Position = Queue->Rear++;
	}

	Queue->Nodes[Position].Data = NewData;
}

ElementType CQ_Dequeue2(CircularQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Not Found Queue\n");
		return NULL;
	}

	if (CQ_IsEmpty2(Queue))
	{
		printf("System Notice : Is Empty\n");
		return NULL;
	}

	if (Queue == NULL)
	{
		return NULL;
	}

	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front += 1;

	return Queue->Nodes[Position].Data;
}

int CQ_IsEmpty2(CircularQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Not Found Queue\n");
		return;
	}

	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull2(CircularQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Not Found Queue\n");
		return;
	}

	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;

	return (Queue->Rear + 1) == Queue->Front;
}

int CQ_GetSize2(CircularQueue* Queue)
{
	if (Queue == NULL)
	{
		printf("System Notice : Not Found Queue\n");
		return -1;
	}

	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;

	return Queue->Capacity - Queue->Front + Queue->Rear + 1;
}

void CQ_Print2(CircularQueue* Queue)
{
	if (CQ_IsEmpty2(Queue))
	{
		printf("Circular List ==================================\n");
		printf("No Data\n");
		printf("================================================\n");
		return;
	}

	int count = 1;

	printf("Circular List ==================================\n");
	printf("%d %d / Size : %d\n", Queue->Front, Queue->Rear, CQ_GetSize2(Queue));

	if (Queue->Front <= Queue->Rear)
	{
		for (int i = Queue->Front; i < Queue->Rear; i++)
		{
			printf(">>> Data[%d] : %d\n", count++, Queue->Nodes[i].Data);
		}
		printf("================================================\n");
		return;
	}

	for (int i = Queue->Front; i < Queue->Capacity + 1; i++)
	{
		printf(">>> Data[%d] : %d\n", count++, Queue->Nodes[i].Data);
	}

	for (int i = 0; i < Queue->Rear; i++)
	{
		printf(">>> Data[%d] : %d\n", count++, Queue->Nodes[i].Data);
	}
	printf("================================================\n");
}
