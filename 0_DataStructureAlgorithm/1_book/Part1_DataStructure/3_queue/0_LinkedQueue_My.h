#ifndef __LINKED_QUEUE_MY_H_
#define __LINKED_QUEUE_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;

	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedListQueue
{
	int size;
	Node* Tail;
	
	Node* Nodes;
}LinkedListQueue;

void LQ_CreateQueue0(LinkedListQueue** Queue);

void LQ_Enqueue0(LinkedListQueue* Queue, ElementType NewData);
void LQ_Dequeue0(LinkedListQueue* Queue);

int LQ_IsEmpty0(LinkedListQueue* Queue);

int LQ_GetSize0(LinkedListQueue* Queue);

void LQ_Print0(LinkedListQueue* Queue);
#endif