#ifndef __DOUBLY_LINKED_LIST_FINAL_H_
#define __DOUBLY_LINKED_LIST_FINAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagDLLNode
{
	ElementType Data;
	struct TagDLLNode* PrevNode;
	struct TagDLLNode* NextNode;
}Node;

// Node Create
Node* DLL_CreateNode2(ElementType NewData);

// Create
void DLL_AppendNode2(Node** Head, ElementType NewData);
void DLL_InsertNode2(Node** Head, int Location, ElementType NewData);

// Update
void DLL_ModifyNode2(Node** Head, int Location, ElementType NewData);

// Delete
void DLL_RemoveNode2ByLocation(Node** Head, int Locaion);
void DLL_RemoveNode2ByNode(Node** Head, Node* Remove);

// Read
Node* DLL_GetNode2(Node* Head, int Location);

// Size
int DLL_GetNodeSize2(Node* Head);

// Print
void DLL_Print2(Node* Head);
#endif