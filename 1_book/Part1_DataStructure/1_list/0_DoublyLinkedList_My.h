#ifndef __DOUBLY_LINKED_LIST_MY_H_
#define __DOUBLY_LINKED_LIST_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElememetType;

typedef struct TagDLL_Node
{
	ElememetType Data;
	struct TagDLL_Node* PrevNode;
	struct TagDLL_Node* NextNode;
}Node;

// Create
void AppendNode0(Node** List, int Data);
void InsertNode0(Node** List, int Location, int Data);

// Update
void ModifyNode0(Node** List, int Location, int Data);

// Delete
void DeleteNode0(Node** List, int Location);

// Read
int GetNode0(Node* List, int Location);

// Size
int GetNodeSize0(Node* List);

// Print
void Print0(Node* List);
#endif
