#ifndef __ARRAY_STACK_MY_H_
#define __ARRAY_STACK_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagArrayStack
{
	int Top;
	int Size;

	ElementType* Data;
}Stack;

Stack init1(int Size);

void Push1(Stack* Stack, ElementType NewData);
void Pop1(Stack* Stack);
#endif