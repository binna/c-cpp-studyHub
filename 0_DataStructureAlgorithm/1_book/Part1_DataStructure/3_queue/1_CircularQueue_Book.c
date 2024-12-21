#include "1_CircularQueue_Book.h"

void CQ_CreateQueue1(CircularQueue** Queue, int Capacity)
{
	// 큐를 자유 저장소에 생성
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	// 입력된 Capacity + 1 만큼의 노드를 자유 저장소에서 생성
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue1(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

// 삽입 연산은
// 후단의 위치를 가리키는 Rear를 살피고 잘 다루는 것이 핵심
void CQ_Enqueue1(CircularQueue* Queue, ElementType Data)
{
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

	Queue->Nodes[Position].Data = Data;
}

// 제거 연산에서는 
// 전달을 잘 관리해 주는 것이 중요
ElementType CQ_Dequeue1(CircularQueue* Queue)
{
	int Position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[Position].Data;
}

int CQ_GetSize1(CircularQueue* Queue)
{
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;

	return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty1(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull1(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;

	return (Queue->Rear + 1) == Queue->Front;
}