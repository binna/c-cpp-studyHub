#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum { RED, BLACK } Color;

	ElementType Data;
}RBTNode;

RBTNode* RBT_CreateNode(ElementType NewData);

void RBT_DestroyNode(RBTNode* Node);
void RBT_DestroyTree(RBTNode* Tree);

//RBTNode* RBT_SearchNode();
//RBTNode* RBT_SearchNode();
//void RBT_InsertNode();
//void RBT_InsertNodeHelper();

void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent);
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);


//void PrintTree(RBTNode* Node, int Depth, int BlackCount);