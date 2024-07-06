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
void AppendNode(Node** List, int Data);
void InsertNode(Node** List, int Location, int Data);

// Update
void ModifyNode(Node** List, int Location, int Data);

// Delete
void DeleteNode(Node** List, int Location);

// Read
int Select(Node* List, int Location);

// size
int Size(Node* List);

// print
void Print(Node* List);

#endif