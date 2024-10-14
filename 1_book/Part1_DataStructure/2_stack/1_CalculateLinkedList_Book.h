#ifndef __CALCULATE_LINKED_LIST_H_
#define __CALCULATE_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TagNode
{
	char* Data;
	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedListStack
{
	struct TagNode* List;
	struct TagNode* Top;
}LinkedListStack;

void LLS_CreatStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);

Node* LLS_CreateNode(char* NewData);
void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop(LinkedListStack* Stack);

Node* LLS_Top(LinkedListStack* Stack);
int LLS_GetSize(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);
#endif