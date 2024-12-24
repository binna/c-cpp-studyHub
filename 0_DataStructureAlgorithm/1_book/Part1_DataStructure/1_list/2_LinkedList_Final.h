#ifndef __LINKED_LIST_FINAL_H_
#define __LINKED_LIST_FINAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagSLLNode
{
    ElementType Data;
    struct TagSLLNode* NextNode;
}Node;

// Node Create
Node* SLL_CreateNode2(ElementType NewData);

// Create
void SLL_AppendNode2(Node** Head, ElementType NewData);
void SLL_InsertNode2(Node** Head, int Location, ElementType NewData);

// Update
void SLL_ModifyNode2(Node** Head, int Location, ElementType Data);

// Delete
void SLL_RemoveNode2ByLocation(Node** Head, int Location);
void SLL_RemoveNode2ByNode(Node** Head, Node* Remove);

// Read
Node* SLL_GetNode2(Node* Head, int Location);

// Size
int SLL_GetNodeSize2(Node* Head);

// Print
void SLL_Print2(Node* Head);
#endif