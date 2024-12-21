#include "0_LCRS_Tree_My.h"

void LCRS_TreeCreateNode0(Tree** Root, int depth, int NewData)
{
	Tree* NewNode = (Tree*)malloc(sizeof(Tree));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;

	if ((*Root) == NULL)
	{
		if (depth == 0)
		{
			(*Root) = NewNode;
			return;
		}

		printf("System Notice : No Root Data\n");
		return;
	}

	Tree* TargetNode = (*Root);

	for (int i = 0; i < depth; i++)
	{
		if (TargetNode->LeftChild == NULL)
		{
			if (i == depth - 1)
			{
				TargetNode->LeftChild = NewNode;
				return;
			}

			printf("System Notice : Wrong depth data\n");
			return;
		}

		TargetNode = TargetNode->LeftChild;
	}

	while (TargetNode->RightSibling != NULL)
	{
		TargetNode = TargetNode->RightSibling;
	}
	TargetNode->RightSibling = NewNode;
}

void LCRS_TreeDeleteNode0(Tree** Root, int depth, int childNum)
{
	if ((*Root) == NULL || childNum == 0)
	{
		printf("System Notice : No deleted data\n");
		return;
	}

	if (depth == 0 && childNum == 1)
	{
		if ((*Root)->RightSibling == NULL && (*Root)->LeftChild == NULL)
			(*Root) = NULL;

		printf("System Notice : Have a child and sibling\n");
		return;
	}

	Tree* PrevNode = (*Root);
	Tree* TatgetNode = (*Root);

	for (int i = 0; i < depth; i++)
	{
		if (TatgetNode->LeftChild == NULL)
		{
			printf("System Notice : Wrong depth\n");
			return;
		}

		PrevNode = TatgetNode;
		TatgetNode = TatgetNode->LeftChild;
	}

	if (childNum == 1)
	{
		if (TatgetNode->RightSibling != NULL)
		{
			PrevNode->LeftChild = TatgetNode->RightSibling;
			TatgetNode->RightSibling->LeftChild = TatgetNode->LeftChild;
			free(TatgetNode);
			return;
		}
		else if (TatgetNode->LeftChild == NULL)
		{
			PrevNode->LeftChild = NULL;
			free(TatgetNode);
			return;
		}
		printf("System Notice : Have a child\n");
		return;
	}

	for (int i = 0; i < childNum - 1; i++)
	{
		if (TatgetNode->RightSibling == NULL)
		{
			printf("System Notice : Wrong ChildNum %d\n", childNum);
			return;
		}

		PrevNode = TatgetNode;
		TatgetNode = TatgetNode->RightSibling;
	}

	PrevNode->RightSibling = TatgetNode->RightSibling;

	free(TatgetNode);
}

int LCRS_TreeGetNode0(Tree* Root, int depth, int childNum)
{
	if (Root == NULL)
	{
		printf("System Notice : No Select data\n");
		return -1;
	}

	Tree* TatgetNode = Root;

	for (int i = 0; i < depth; i++)
	{
		if (TatgetNode->LeftChild == NULL)
		{
			printf("System Notice : Wrong depth\n");
			return -1;
		}
		TatgetNode = TatgetNode->LeftChild;
	}

	for (int i = 1; i < childNum; i++)
	{
		if (TatgetNode->RightSibling == NULL)
		{
			printf("System Notice : Wrong ChildNum %d\n", childNum);
			return -1;
		}
		TatgetNode = TatgetNode->RightSibling;
	}

	return TatgetNode->Data;
}

void LCRS_TreePrintNode0(Tree* Root)
{
	printf("Tree Print ======================================\n");
	
	if (Root == NULL)
	{
		printf("No Data\n");
	}
	else
	{
		int depth = 0;

		Tree* NowDeptyNode = Root;
		Tree* NextDepthNode;
		
		do
		{
			printf("deep %d\n  > ", depth++);
			NextDepthNode = NowDeptyNode->LeftChild;
			while (NowDeptyNode->RightSibling != NULL)
			{
				printf("%d ", NowDeptyNode->Data);
				NowDeptyNode = NowDeptyNode->RightSibling;
			}

			printf("%d ", NowDeptyNode->Data);
			printf("\n");
			NowDeptyNode = NextDepthNode;
		} while (NextDepthNode != NULL);
	}

	printf("=================================================\n");
}