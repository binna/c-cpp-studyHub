#ifndef INC_2_LINKEDLIST_FINAL_H
#define INC_2_LINKEDLIST_FINAL_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagSLLNode
{
    ElementType Data;
    struct TagSLLNode* NextNode;
}Node;

// Create
Node* SLL_CreateNode2(ElementType NewData);
void SLL_AppendNode2(Node** Head, ElementType NewData);
void SLL_InsertNode2(Node** Head, int Location, ElementType NewData);

// Update
void SLL_ModifyNode2(Node** Head, int Location, ElementType Data);

// Delete
void SLL_RemoveNode2ByLocation(Node** Head, int Location);
void SLL_RemoveNode2ByNode(Node** Head, Node* Remove);

// Read
Node* SLL_GetNode2(Node* Head, int Location);

// size
int SLL_GetNodeSize2(Node* Head);

// print
void Print2(Node* Head);

#endif