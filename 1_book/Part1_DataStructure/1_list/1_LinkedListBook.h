#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagSLLNode
{
    ElementType Data;
    struct TagSLLNode* NextNode;
}Node;

// 함수 원형 선언
Node* SLL_CreateNode1(ElementType NewData);

void SLL_DestroyNode1(Node* Node);

void SLL_AppendNode1(Node** Head, Node* NewNode);
void SLL_InsertAfter1(Node* Current, Node* NewNode);
void SLL_InsertNewHead1(Node** Head, Node* NewHead);

void SLL_RemoveNode1(Node** Head, Node* Remove);

Node* SLL_GetNodeAt1(Node* Head, int Location);
int SLL_GetNodeCount1(Node* Head);
#endif