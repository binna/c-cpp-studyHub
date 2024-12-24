#ifndef __LINKED_LIST_BOOK_H_
#define __LINKED_LIST_BOOK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TagNode
{
	char* Data;
	struct TagNode* NextNode;
}Node;

typedef struct TagLinkedListStack
{
	Node* List;		// 헤드
	Node* Top;		// 테일
}LinkedListStack;

void LLS_CreateStack1(LinkedListStack** Stack);
void LLS_DestroyStack1(LinkedListStack* Stack);

Node* LLS_CreateNode1(char* NewData);
void LLS_DestroyNode1(Node* _Node);

void LLS_Push1(LinkedListStack* Stack, Node* NewNode);
Node* LLS_Pop1(LinkedListStack* Stack);

Node* LLS_Top1(LinkedListStack* Stack);
int LLS_GetSize1(LinkedListStack* Stack);
int LLS_IsEmpty1(LinkedListStack* Stack);
#endif
