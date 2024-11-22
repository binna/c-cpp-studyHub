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

LCRSNode* LCRS_CreateNode(ElementType NewData);

void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);

void LCRS_PrintTree(LCRSNode* Node, int Depth);
#endif