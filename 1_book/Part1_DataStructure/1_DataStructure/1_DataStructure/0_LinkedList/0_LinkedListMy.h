#ifndef LINKEDLISTMY_H
#define LINKEDLISTMY_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
    ElementType Data;
    struct TagNode* NextNode;
}Node;

// Create
void AppendNode(Node** List, int Data);
void InsertNode(Node** List, int lLcation, int Data);

// Update
void ModifyNode(Node** List, int Data, int Location);

// Delete
void DeleteNode(Node** List, int Location);

// read
int Select(Node* List, int Location);

// size
int Size(Node* List);

// print
void Print(Node* List);

#endif //LINKEDLISTMY_H