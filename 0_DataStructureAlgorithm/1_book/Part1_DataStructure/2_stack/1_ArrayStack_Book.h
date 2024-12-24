#ifndef __ARRAY_STACK_BOOK_H_
#define __ARRAY_STACK_BOOK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
}Node;

typedef struct TagArrayStack
{
	int Capacity;
	int Top;

	Node* Nodes;
}ArrayStack;

void AS_CreateStack1(ArrayStack** Stack, int Capacity);
void AS_DestroyStack1(ArrayStack* Stack);

void AS_Push1(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop1(ArrayStack* Stack);

ElementType AS_Top1(ArrayStack* Stack);
int AS_GetSize1(ArrayStack* Stack);

int AS_IsEmpty1(ArrayStack* Stack);
int AS_IsFull1(ArrayStack* Stack);
#endif