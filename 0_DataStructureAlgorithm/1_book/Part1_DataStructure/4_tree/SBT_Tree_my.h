#ifndef __SBT_TREE_H_
#define __SBT_TREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// SBT : Simple Binary Tree
typedef struct tagSBTNode
{
	struct tagSBTNode* Left;
	struct tagSbtNode* Rigth;

	ElementType Data;
}SBTNode;

typedef struct tagStack
{
	struct stack* ListNode;
	struct stack* TailNode;
}stackInfo;

SBTNode* SBT_CreateNode(ElementType Data);

void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Node);

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);
#endif