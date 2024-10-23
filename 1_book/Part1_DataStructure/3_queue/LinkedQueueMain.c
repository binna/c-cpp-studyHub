#include "0_LinkedQueue_My.h"

int main(void)
{
	LinkedListQueue* Queue;

	LQ_CreateQueue0(&Queue);

	LQ_Dequeue0(Queue);

	LQ_Print0(Queue);

	LQ_Enqueue0(Queue, 1);
	LQ_Enqueue0(Queue, 2);
	LQ_Enqueue0(Queue, 3);
	LQ_Enqueue0(Queue, 4);
	LQ_Enqueue0(Queue, 5);
	LQ_Enqueue0(Queue, 6);

	LQ_Print0(Queue);

	LQ_Dequeue0(Queue);
	LQ_Dequeue0(Queue);
	LQ_Dequeue0(Queue);

	LQ_Print0(Queue);

	LQ_Dequeue0(Queue);
	LQ_Dequeue0(Queue);
	LQ_Dequeue0(Queue);
	LQ_Dequeue0(Queue);

	LQ_Print0(Queue);
	
	return 0;
}