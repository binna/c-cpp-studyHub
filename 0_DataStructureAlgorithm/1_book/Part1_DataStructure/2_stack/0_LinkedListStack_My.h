#ifndef __LINKED_LIST_MY_H_
#define __LINKED_LIST_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
	struct TagNode* PrevNode;
	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedListStack
{
	unsigned int Capacity;
	struct TagNode* Top;
	
	Node* Nodes;
}LinkedListStack;

LinkedListStack* LS_CreateStack0();
Node* LS_CreateStackNode0(ElementType NewData);

void LS_Push0(LinkedListStack** Stack, ElementType NewData);
ElementType LS_Pop0(LinkedListStack* Stack);

Node* LS_Top0(LinkedListStack* Stack);
unsigned int LS_GetSize0(LinkedListStack* Stack);

int LS_IsEmpty0(LinkedListStack* Stack);
// 내 생각 : 리스트이기 때문에 IsFull의 의미가 없을 것 같음

void LS_Print0(LinkedListStack* Stack);
#endif
