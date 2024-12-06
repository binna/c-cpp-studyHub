#ifndef __LCRS_TREE_BOOK_H_
#define __LCRS_TREE_BOOK_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

// LCRS : Left Child, Right Sibling
typedef struct TagLCRSNode
{
	struct TagLCRSNode* LeftChile;
	struct TagLCRSNode* RightSibling;

	ElementType Data;
}LCRSNode;

LCRSNode* LCRS_CreateNode1(ElementType NewData);

void LCRS_DestroyNode1(LCRSNode* Node);
void LCRS_DestroyTree1(LCRSNode* Root);

void LCRS_AddChildNode1(LCRSNode* ParentNode, LCRSNode* ChildNode);

void LCRS_PrintTree1(LCRSNode* Node, int Depth);
#endif