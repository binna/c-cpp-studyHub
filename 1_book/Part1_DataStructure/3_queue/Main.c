//#include "0_CircularQueue_My.h"
//
//int main(void)
//{
//	CircularQueue* Queue;
//
//	CQ_CreateQueue0(&Queue, 5);
//
//	CQ_Print0(Queue);
//
//	CQ_Enqueue0(Queue, 1);
//	CQ_Enqueue0(Queue, 2);
//	CQ_Enqueue0(Queue, 3);
//	CQ_Enqueue0(Queue, 4);
//	CQ_Enqueue0(Queue, 5);
//	CQ_Print0(Queue);
//
//	CQ_Enqueue0(Queue, 6);
//	CQ_Print0(Queue);
//
//	CQ_Dequeue0(Queue);
//	CQ_Print0(Queue);
//
//	CQ_Enqueue0(Queue, 6);
//	CQ_Print0(Queue);
//
//	CQ_Enqueue0(Queue, 7);
//	CQ_Print0(Queue);
//
//	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
//
//	CQ_Dequeue0(Queue);
//	CQ_Dequeue0(Queue);
//	CQ_Dequeue0(Queue);
//	CQ_Print0(Queue);
//
//	CQ_Dequeue0(Queue);
//	CQ_Dequeue0(Queue);
//	CQ_Print0(Queue);
//
//	CQ_Dequeue0(Queue);
//	CQ_Print0(Queue);
//
//	return 0;
//}

#include "1_CircularQueue_Book.h"

int main(void)
{
	CircularQueue* Queue;

	CQ_CreateQueue1(&Queue, 10);

	CQ_Enqueue1(Queue, 1);
	CQ_Enqueue1(Queue, 2);
	CQ_Enqueue1(Queue, 3);
	CQ_Enqueue1(Queue, 4);

	for (int i = 0; i < 3; i++)
	{
		printf("Dequeue : %d, ", CQ_Dequeue1(Queue));
		printf("Front : %d, Rear : %d\n\n", Queue->Front, Queue-> Rear);
	}

	int num = 100;
	while (CQ_IsFull1(Queue) == 0)
	{
		CQ_Enqueue1(Queue, num++);
	}

	printf("Capacity : %d, Size : %d\n\n", Queue->Capacity, CQ_GetSize1(Queue));

	while (CQ_IsEmpty1(Queue) == 0)
	{
		printf("Dequeue : %d, ", CQ_Dequeue1(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
	}

	CQ_DestroyQueue1(Queue);

	return 0;
}