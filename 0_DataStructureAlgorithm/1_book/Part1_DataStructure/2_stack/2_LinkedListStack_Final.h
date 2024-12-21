#ifndef __LINKED_LIST_FINAL_H_
#define __LINKED_LIST_FINAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
	ElementType Data;
	struct TagNode* NextNode;

}Node;

typedef struct TagLinkedListStack
{
	Node* List;		// 헤드
	Node* Top;		// 테일
}LinkedListStack;

void LLS_CreateStack2(LinkedListStack** Stack);
void LLS_DestroyStack2(LinkedListStack* Stack);

Node* LLS_CreateNode2(ElementType NewData);
void LLS_DestoryNode2(Node* Node);

void LLS_Push2(LinkedListStack* Stack, ElementType NewData);
Node* LLS_Pop2(LinkedListStack* Stack);

Node* LLS_Top2(LinkedListStack* Stack);
int LLS_GetSize2(LinkedListStack* Stack);
int LLS_IsEmpty2(LinkedListStack* Stack);

void LLS_Print2(LinkedListStack* Stack);
#endif