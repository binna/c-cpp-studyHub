#ifndef LINKEDLISTMY_H
#define LINKEDLISTMY_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagSLLNode
{
    ElementType Data;
    struct TagSLLNode* NextNode;
}Node;

// Create
void AppendNode0(Node** List, int Data);
void InsertNode0(Node** List, int Location, int Data);

// Update
void ModifyNode0(Node** List, int Location, int Data);

// Delete
void DeleteNode0(Node** List, int Location);

// Read
int Select0(Node* List, int Location);

// size
int GetSize0(Node* List);

// print
void Print0(Node* List);
#endif