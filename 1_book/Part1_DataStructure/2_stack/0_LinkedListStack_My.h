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

typedef struct TagListStack
{
	unsigned int Capacity;
	struct TagNode* Top;
	
	Node* Nodes;
}ListStack;

ListStack* LS_CreateStack0();
Node* LS_CreateStackNode0(ElementType NewData);

void LS_Push0(ListStack** Stack, ElementType NewData);
ElementType LS_Pop0(ListStack* Stack);

Node* LS_Top0(ListStack* Stack);
unsigned int LS_GetSize0(ListStack* Stack);

int LS_IsEmpty0(ListStack* Stack);
// 내 생각 : 리스트이기 때문에 IsFull의 의미가 없을 것 같음

void LS_Print0(ListStack* Stack);
#endif
