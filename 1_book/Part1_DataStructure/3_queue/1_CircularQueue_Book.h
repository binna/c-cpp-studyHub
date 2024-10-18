#ifndef __CIRCULAR_QUEUE_BOOK_H
#define __CIRCULAR_QUEUE_BOOK_H

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

void CQ_CreateQueue1(CircularQueue** Queue, int Capacity);

void CQ_DestroyQueue1(CircularQueue* Queue);
void CQ_Enqueue1(CircularQueue* Queue, ElementType Data);

ElementType CQ_Dequeue1(CircularQueue* Queue);

int CQ_GetSize1(CircularQueue* Queue);

int CQ_IsEmpty1(CircularQueue* Queue);
int CQ_IsFull1(CircularQueue* Queue);
#endif