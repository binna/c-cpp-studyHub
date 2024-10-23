#ifndef __LINKED_QUEUE_BOOK_H_
#define __LINKED_QUEUE_BOOK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TagNode
{
	char* Data;
	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
}LinkedQueue;

void LQ_CraeteQueue1(LinkedQueue** Queue);
void LQ_DestroyQueue1(LinkedQueue* Queue);

Node* LQ_CreateNode1(char* NewData);
void LQ_DestroyNode1(Node* _Node);

void LQ_Enqueue1(LinkedQueue* Queue, Node* NewNode);
Node* LQ_Dequeue1(LinkedQueue* Queue);

int LQ_IsEmpty1(LinkedQueue* Queue);
#endif