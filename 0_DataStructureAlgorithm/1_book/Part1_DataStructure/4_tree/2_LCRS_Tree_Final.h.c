#include "2_LCRS_Tree_Final.h"

void LCRS_CreateTree2(LCRSNode** Root)
{
	(*Root) = (LCRSNode*)malloc(sizeof(LCRSNode));

	if ((*Root) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Root)->Data = 0;
	(*Root)->LeftChild = NULL;
	(*Root)->RightSibling = NULL;
}

void LCRS_AddChildNodeByDepth2(LCRSNode* Root, int Depth, ElementType NewData)
{
	if (Root == NULL)
	{
		printf("System Notice : Not found Tree Data\n");
		return;
	}

	if (Depth == 0 && Root->Data == 0)
	{
		Root->Data = NewData;
		return;
	}

	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	LCRSNode* TempNode = Root;
	for (int i = 0; i < Depth; i++)
	{
		if (TempNode->LeftChild == NULL)
		{
			if (i == Depth - 1)
			{
				TempNode->LeftChild = NewNode;
				return;
			}
			printf("System Notice : Wrong Depth\n");
			return;
		}

		TempNode = TempNode->LeftChild;
	}

	while (TempNode->RightSibling != NULL)
	{
		TempNode = TempNode->RightSibling;
	}

	TempNode->RightSibling = NewNode;
}

void LCRS_DestroyTree2(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree2(Root->RightSibling);

	if (Root->LeftChild != NULL)
		LCRS_DestroyTree2(Root->LeftChild);

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	free(Root);
}

void LCRS_DeleteChildNode2(LCRSNode* Root, int Depth, int ChildNum)
{
	if (Root == NULL)
	{
		printf("System Notice : Not found Tree Data\n");
		return;
	}

	if (ChildNum <= 0)
	{
		printf("System Notice : Wrong ChildNum\n");
		return;
	}

	if (Depth == 0 && ChildNum == 1)
	{
		if (Root->LeftChild == NULL && Root->RightSibling == NULL)
			Root->Data = 0;

		printf("System Notice : Have a child and sibling");
		return;
	}

	LCRSNode* PrevNode = Root;
	LCRSNode* TempNode = Root;
	for (int i = 0; i < Depth; i++)
	{
		if (TempNode->LeftChild == NULL)
		{
			printf("System Notice : Wrong Depth (%d)\n", Depth);
			return;
		}
		PrevNode = TempNode;
		TempNode = TempNode->LeftChild;
	}

	if (ChildNum == 1)
	{
		if (TempNode->RightSibling != NULL)
		{
			PrevNode->LeftChild = TempNode->RightSibling;
			TempNode->RightSibling->LeftChild = TempNode->LeftChild;
			free(TempNode);
			return;
		}
		else if (TempNode->LeftChild == NULL)
		{
			PrevNode->LeftChild = NULL;
			free(TempNode);
			return;
		}
		printf("System Notice : Have a child\n");
		return;
	}

	for (int i = 0; i < ChildNum - 1; i++)
	{
		if (TempNode->RightSibling == NULL)
		{
			printf("System Notice : Wrong ChildNum (%d)\n", ChildNum);
			return;
		}
		PrevNode = TempNode;
		TempNode = TempNode->RightSibling;
	}

	PrevNode->RightSibling = TempNode->RightSibling;

	free(TempNode);
}

char LCRS_GetNodeData2(LCRSNode* Root, int Depth, int ChildNum)
{
	LCRSNode* TempNode = Root;
	for (int i = 0; i < Depth; i++)
	{
		if (TempNode->LeftChild == NULL)
		{
			printf("System Notice : Wrong Depth (%d)\n", Depth);
			return 0;
		}
		TempNode = TempNode->LeftChild;
	}

	for (int i = 0; i < ChildNum - 1; i++)
	{
		if (TempNode->RightSibling == NULL)
		{
			printf("System Notice : Wrong ChildNum (%d)\n", ChildNum);
			return 0;
		}
		TempNode = TempNode->RightSibling;
	}

	return TempNode->Data;
}

void LCRS_PrintTree2(LCRSNode* Root)
{
	printf("Tree Print ======================================\n");

	if (Root == NULL)
		printf("No Data\n");
	
	else if (Root->Data == 0)
		printf("No Data\n");
	
	else
	{
		int depth = 0;
		LCRSNode* DepthNode = Root;
		LCRSNode* SiblingNode = Root;

		while (DepthNode != NULL)
		{
			printf("Depth : %d\n", depth);

			while (SiblingNode != NULL)
			{
				printf("%c  ", SiblingNode->Data);
				SiblingNode = SiblingNode->RightSibling;
			}

			printf("\n");
			DepthNode = DepthNode->LeftChild;
			SiblingNode = DepthNode;
			depth += 1;
		}
	}

	printf("=================================================\n");
}