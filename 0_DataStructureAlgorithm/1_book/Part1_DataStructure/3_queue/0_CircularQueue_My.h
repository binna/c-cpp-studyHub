#ifndef __CIRCULAR_QUEUE_MY_H_
#define __CIRCULAR_QUEUE_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagCircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	ElementType* Data;
}CircularQueue;

void CQ_CreateQueue0(CircularQueue** Queue, int Capacity);

void CQ_Enqueue0(CircularQueue* Queue, ElementType NewData);
void CQ_Dequeue0(CircularQueue* Queue);

int CQ_IsEmpty0(CircularQueue* Queue);
int CQ_IsFULL0(CircularQueue* Queue);

int CQ_GetSize0(CircularQueue* Queue);

void CQ_Print0(CircularQueue* Queue);
#endif