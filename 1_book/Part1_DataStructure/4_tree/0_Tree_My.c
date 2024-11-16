#include "0_Tree_My.h"

void TreeCreateNode0(Tree** Root, int deep, int NewData)
{
	Tree* NewNode = (Tree*)malloc(sizeof(Tree));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return 0;
	}

	NewNode->Data = NewData;
	NewNode->leftNode = NULL;
	NewNode->rightNode = NULL;

	if ((*Root) == NULL)
	{
		(*Root) = NewNode;
		return;
	}

	int i;
	Tree* TargetNode = (*Root);

	for (i = 0; i <= deep; i++)
	{
		if (TargetNode->rightNode == NULL)
			break;

		TargetNode = TargetNode->rightNode;
	}
	
	if (i < deep)
	{
		if (i + 1 == deep)
		{
			TargetNode->rightNode = NewNode;
			return;
		}
		printf("System Notice : Error deep data\n");
		return;
	}

	while (TargetNode->leftNode != NULL)
	{
		TargetNode = TargetNode->leftNode;
	}
	TargetNode->leftNode = NewNode;
}

void TreeDeleteNode0(Tree** Root, int deep, int childNo)
{
	if ((*Root) == NULL || childNo == 0)
	{
		printf("System Notice : No deleted data\n");
		return 0;
	}

	if (deep == 0 && childNo == 1)
	{
		if ((*Root)->rightNode == NULL && (*Root)->leftNode == NULL)
			(*Root) = NULL;

		printf("System Notice : Have a child\n");
		return;
	}

	childNo -= 1;

	Tree* PrevNode = NULL;
	Tree* TatgetNode = (*Root);

	while (deep && TatgetNode->rightNode != NULL)
	{
		deep -= 1;
		PrevNode = TatgetNode;
		TatgetNode = TatgetNode->rightNode;
	}

	if (deep != 0)
	{
		printf("System Notice : Wrong deep\n");
		return;
		
	}

	if (childNo == 0)
	{
		if (TatgetNode->rightNode != NULL)
		{
			printf("System Notice : Have a child\n");
			return;
		}

		PrevNode->rightNode = NULL;
		free(TatgetNode);
		return;
	}

	while (childNo && TatgetNode->leftNode != NULL)
	{
		childNo -= 1;
		PrevNode = TatgetNode;
		TatgetNode = TatgetNode->leftNode;
	}

	if (childNo != 0)
	{
		printf("System Notice : Wrong ChildNo\n");
		return;
	}

	if (TatgetNode->rightNode != NULL)
	{
		printf("System Notice : Have a child\n");
		return;
	}

	PrevNode->leftNode = NULL;
	free(TatgetNode);
}

int TreeGetNode0(Tree** Root, int deep, int childNo)
{
	if (Root == NULL)
	{
		printf("System Notice : No Select data\n");
		return -1;
	}

	childNo -= 1;

	Tree* TatgetNode = Root;

	while (deep && TatgetNode->rightNode != NULL)
	{
		deep -= 1;
		TatgetNode = TatgetNode->rightNode;
	}

	if (deep != 0)
	{
		printf("System Notice : wrong deep\n");
		return -1;

	}

	while (childNo && TatgetNode->leftNode != NULL)
	{
		childNo -= 1;
		TatgetNode = TatgetNode->leftNode;
	}

	if (childNo != 0)
	{
		printf("System Notice : wrong ChildNo\n");
		return -1;
	}

	return TatgetNode->Data;
}

void TreePrintNode0(Tree* Root)
{
	printf("Tree Print ======================================\n");
	
	if (Root == NULL)
	{
		printf("No Data\n");
	}
	else
	{
		int deep = 0;

		Tree* TargetNode = Root;
		Tree* NextDeepNode;
		
		do
		{
			printf("deep %d\n  > ", deep++);
			NextDeepNode = TargetNode->rightNode;
			while (TargetNode->leftNode != NULL)
			{
				printf("%d ", TargetNode->Data);
				TargetNode = TargetNode->leftNode;
			}

			printf("%d ", TargetNode->Data);
			printf("\n");
			TargetNode = NextDeepNode;
		} while (NextDeepNode != NULL);
	}

	printf("=================================================\n");
}