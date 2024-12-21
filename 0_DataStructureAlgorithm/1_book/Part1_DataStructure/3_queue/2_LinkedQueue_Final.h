#ifndef __LINKED_QUEUE_FINAL_H_
#define __LINKED_QUEUE_FINAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TagNode
{
	char* Data;
	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedListQueue
{
	Node* Front;
	Node* Rear;

	int Count;
}LinkedListQueue;

void LQ_CreateQueue2(LinkedListQueue** Queue);

void LQ_Enqueue2(LinkedListQueue* Queue, const char* NewData);
Node* LQ_Dequeue2(LinkedListQueue* Queue);

int LQ_IsEmpty2(LinkedListQueue* Queue);

int LQ_GetSize2(LinkedListQueue* Queue);

void LQ_Print2(LinkedListQueue* Queue);
#endif