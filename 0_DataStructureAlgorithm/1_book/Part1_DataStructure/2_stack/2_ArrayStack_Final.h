#ifndef __ARRAY_STACK_FINAL_H_
#define __ARRAY_STACK_FINAL_H_

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

void AS_CreateStack2(ArrayStack** Stack, int Capacity);
void AS_DestroyStack2(ArrayStack* Stack);

void AS_Push2(ArrayStack* Stack, ElementType Data);
ElementType AS_Pop2(ArrayStack* Stack);

ElementType AS_Top2(ArrayStack* Stack);
int AS_GetSize2(ArrayStack* Stack);

int AS_IsEmpty2(ArrayStack* Stack);
int AS_IsFull2(ArrayStack* Stack);

void Print2(ArrayStack* Stack);
#endif