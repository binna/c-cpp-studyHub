//#include "0_LinkedQueue_My.h"
//
//int main(void)
//{
//	LinkedListQueue* Queue;
//
//	LQ_CreateQueue0(&Queue);
//
//	LQ_Dequeue0(Queue);
//
//	LQ_Print0(Queue);
//
//	LQ_Enqueue0(Queue, 1);
//	LQ_Enqueue0(Queue, 2);
//	LQ_Enqueue0(Queue, 3);
//	LQ_Enqueue0(Queue, 4);
//	LQ_Enqueue0(Queue, 5);
//	LQ_Enqueue0(Queue, 6);
//
//	LQ_Print0(Queue);
//
//	LQ_Dequeue0(Queue);
//	LQ_Dequeue0(Queue);
//	LQ_Dequeue0(Queue);
//
//	LQ_Print0(Queue);
//
//	LQ_Dequeue0(Queue);
//	LQ_Dequeue0(Queue);
//	LQ_Dequeue0(Queue);
//	LQ_Dequeue0(Queue);
//
//	LQ_Print0(Queue);
//	
//	return 0;
//}

//#include "1_LinkedQueue_Book.h"
//
//int main(void)
//{
//	Node* Popped;
//	LinkedQueue* Queue;
//
//	LQ_CraeteQueue1(&Queue);
//
//	LQ_Enqueue1(Queue, LQ_CreateNode1("abc"));
//	LQ_Enqueue1(Queue, LQ_CreateNode1("def"));
//	LQ_Enqueue1(Queue, LQ_CreateNode1("efg"));
//	LQ_Enqueue1(Queue, LQ_CreateNode1("hij"));
//
//	printf("Queue Size : %d\n", Queue->Count);
//
//	while (LQ_IsEmpty1(Queue) == 0)
//	{
//		Popped = LQ_Dequeue1(Queue);
//
//		printf("Dequeue : %s\n", Popped->Data);
//
//		LQ_DestroyNode1(Popped);
//	}
//
//	LQ_DestroyQueue1(Queue);
//
//	return 0;
//}

#include "2_LinkedQueue_Final.h"

int main(void)
{
	LinkedListQueue* Queue;

	LQ_CreateQueue2(&Queue);

	LQ_Dequeue2(Queue);

	LQ_Print2(Queue);

	LQ_Enqueue2(Queue, "a");
	LQ_Enqueue2(Queue, "b");
	LQ_Enqueue2(Queue, "c");
	LQ_Enqueue2(Queue, "d");
	LQ_Enqueue2(Queue, "e");
	LQ_Enqueue2(Queue, "f");

	LQ_Print2(Queue);

	LQ_Dequeue2(Queue);
	LQ_Dequeue2(Queue);
	LQ_Dequeue2(Queue);

	LQ_Print2(Queue);

	LQ_Dequeue2(Queue);
	LQ_Dequeue2(Queue);
	LQ_Dequeue2(Queue);
	LQ_Dequeue2(Queue);

	LQ_Print2(Queue);
	
	return 0;
}