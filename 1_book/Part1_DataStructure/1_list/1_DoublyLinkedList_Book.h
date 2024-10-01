#ifndef __DOUBLY_LINKED_LIST_H_
#define __DOUBLY_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagDLLNode
{
	ElementType Data;
	struct TagDLLNode* PrevNode;
	struct TagDLLNode* NextNode;
}Node;

// 함수 원형 선언
Node* DLL_CreateNode1(ElementType NewData);

void DLL_AppendNode1(Node** Head, Node* NewNode);
void DLL_InsertAfter1(Node* Current, Node* NewNode);

void DLL_DestroyNode1(Node* Node);
void DLL_RemoveNode1(Node** Head, Node* Remove);

Node* DLL_GetNodeAt1(Node* Head, int Location);

int DLL_GetNodeCount1(Node* Head);
#endif