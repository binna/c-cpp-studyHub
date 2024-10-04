#ifndef __CIRCULAR_LINKED_LIST_H_
#define __CIRCULAR_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagCDLLNode
{
	ElementType Data;
	struct TagCDLLNode* PrevNode;
	struct TagCDLLNode* NextNode;
}Node;

// New Create
Node* CDLL_CreateNode2(ElementType NewData);

// Create
void CDLL_AppendNode2(Node** Head, ElementType NewData);
//void CDLL_InsertNode2(Node** Head, int Location, ElementType NewData);

// Update
void CDLL_ModifyNode2(Node** Head, int Location, ElementType NewData);

//// Delete
//void CDLL_RemoveNode2ByLocation(Node* Head, int Location);
//void CDLL_RemoveNode2ByNode(Node** Head, Node* Remove);
//
//// Read
Node* CDLL_GetNode2(Node* Head, int Location);

// Size
int CDLL_GetNodeSize2(Node* Head);

// Print
void CDLL_Print2(Node* Head);
#endif