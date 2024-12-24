#ifndef __CIRCULAR_QUEUE_FINAL_H_
#define __CIRCULAR_QUEUE_FINAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
}Node;

typedef struct TagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
}CircularQueue;

void CQ_CreateQueue2(CircularQueue** Queue, int Capacity);

void CQ_Enqueue2(CircularQueue* Queue, ElementType NewData);
ElementType CQ_Dequeue2(CircularQueue* Queue);

int CQ_IsEmpty2(CircularQueue* Queue);
int CQ_IsFull2(CircularQueue* Queue);

int CQ_GetSize2(CircularQueue* Queue);

void CQ_Print2(CircularQueue* Queue);
#endif

