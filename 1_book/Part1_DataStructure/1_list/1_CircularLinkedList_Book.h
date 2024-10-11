#ifndef __CIRCULAR_LINKDE_LIST_BOOK_H_
#define __CIRCULAR_LINKDE_LIST_BOOK_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagCDLLNode
{
	ElementType Data;
	struct TagCDLLNode* PrevNode;
	struct TagCDLLNode* NextNode;
}Node;

// 함수 원형 선언
Node* CDLL_CreateNode1(ElementType NewData);

void CDLL_AppendNode1(Node** Head, Node* NewNode);
void CDLL_InsertAfter1(Node* Current, Node* NewNode);

void CDLL_DestroyNode1(Node* Node);
void CDLL_RemoveNode1(Node** Head, Node* Remove);

Node* CDLL_GetNodeAt1(Node* Head, int Location);

int CDLL_GetNodeCount1(Node* Head);

void PrintNode(Node* _Node);
#endif