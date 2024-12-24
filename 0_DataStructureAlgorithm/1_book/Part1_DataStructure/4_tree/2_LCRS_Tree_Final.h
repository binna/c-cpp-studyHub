#ifndef __LCRS_TREE_FINAL_H_
#define __LCRS_TREE_FINAL_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TagLCRSNode
{
	struct TagLCRSNode* LeftChild;
	struct TagLCRSNode* RightSibling;

	ElementType Data;
}LCRSNode;

void LCRS_CreateTree2(LCRSNode** Root);

void LCRS_AddChildNodeByDepth2(LCRSNode* Root, int Depth, ElementType NewData);

void LCRS_DestroyTree2(LCRSNode** Root);

void LCRS_DeleteChildNode2(LCRSNode* Root, int Depth, int ChildNum);

char LCRS_GetNodeData2(LCRSNode* Root, int Depth, int ChildNum);

void LCRS_PrintTree2(LCRSNode* Root);
#endif