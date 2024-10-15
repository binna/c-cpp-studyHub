#include "0_CircularQueue_My.h"

int main(void)
{
	CircularQueue* Queue;

	CQ_CreateQueue0(&Queue, 5);

	CQ_Print0(Queue);

	CQ_Enqueue0(Queue, 1);
	CQ_Enqueue0(Queue, 2);
	CQ_Enqueue0(Queue, 3);
	CQ_Enqueue0(Queue, 4);
	CQ_Enqueue0(Queue, 5);
	CQ_Print0(Queue);

	CQ_Enqueue0(Queue, 6);
	CQ_Print0(Queue);

	CQ_Dequeue0(Queue);
	CQ_Print0(Queue);

	CQ_Enqueue0(Queue, 6);
	CQ_Print0(Queue);

	CQ_Enqueue0(Queue, 7);
	CQ_Print0(Queue);

	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	CQ_Dequeue0(Queue);
	CQ_Dequeue0(Queue);
	CQ_Dequeue0(Queue);
	CQ_Print0(Queue);

	CQ_Dequeue0(Queue);
	CQ_Dequeue0(Queue);
	CQ_Print0(Queue);

	CQ_Dequeue0(Queue);
	CQ_Print0(Queue);

	return 0;
}