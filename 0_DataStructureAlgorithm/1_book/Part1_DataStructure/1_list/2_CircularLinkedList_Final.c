#include "2_CircularLinkedList_Final.h"

Node* CDLL_CreateNode2(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void CDLL_AppendNode2(Node** Head, ElementType NewData)
{
	Node* NewNode = CDLL_CreateNode2(NewData);

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	if (*Head == NULL)
	{
		NewNode->PrevNode = NewNode;
		NewNode->NextNode = NewNode;
		*Head = NewNode;
		return;
	}

	Node* TailNode = (*Head)->PrevNode;

	TailNode->NextNode = NewNode;

	NewNode->NextNode = *Head;
	NewNode->PrevNode = TailNode;

	(*Head)->PrevNode = NewNode;
}

void CDLL_InsertNode2(Node** Head, int Location, ElementType NewData)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* NewNode = CDLL_CreateNode2(NewData);

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	if (Location == 0)
	{
		NewNode->PrevNode = (*Head)->PrevNode;
		NewNode->NextNode = (*Head);

		(*Head)->PrevNode->NextNode = NewNode;
		(*Head)->PrevNode = NewNode;
		(*Head) = NewNode;
		return;
	}

	Node* TargetNode = (*Head);
	while (Location--)
	{
		if (TargetNode->NextNode == (*Head))
		{
			printf("System Notice : Invalid value\n");
			return;
		}
		
		TargetNode = TargetNode->NextNode;
	}

	NewNode->PrevNode = TargetNode;
	NewNode->NextNode = TargetNode->NextNode;

	TargetNode->NextNode = NewNode;
	NewNode->NextNode->PrevNode = NewNode;
}

void CDLL_ModifyNode2(Node** Head, int Location, ElementType NewData)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = (*Head);
	while (Location--)
	{
		if (TargetNode->NextNode == (*Head))
		{
			printf("System Notice : Invalid value\n");
			return;
		}

		TargetNode = TargetNode->NextNode;
	}
	TargetNode->Data = NewData;
}

void CDLL_RemoveNode2ByLocation(Node* Head, int Location)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = Head;
	while (Location--)
	{
		if (TargetNode->NextNode == Head)
		{
			printf("System Notice : Invalid value\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}
}

void CDLL_RemoveNode2ByNode(Node** Head, Node* Remove)
{
	if (*Head == NULL)
	{
		printf("System Notice : No Circular Deleted linked list\n");
		return;
	}

	if ((*Head) == Remove)
	{
		Node* Temp = (*Head);
		if (Temp->PrevNode->NextNode == Temp->PrevNode)
		{
			(*Head) = NULL;
			free(Temp);
			return;
		}

		Temp->NextNode->PrevNode = (*Head)->PrevNode;
		Temp->PrevNode->NextNode = Temp->NextNode;
		(*Head) = Temp->NextNode;
		free(Temp);
		return;
	}

	Node* TargetNode = (*Head);
	while (TargetNode->NextNode != (*Head))
	{
		if (TargetNode == Remove)
		{
			TargetNode->PrevNode->NextNode = Remove->NextNode;
			TargetNode->NextNode->PrevNode = Remove->PrevNode;
			free(TargetNode);
			break;
		}
		TargetNode = TargetNode->NextNode;
	}
}

Node* CDLL_GetNode2(Node* Head, int Location)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = Head;
	while (Location--)
	{
		if (TargetNode->NextNode == Head)
		{
			printf("System Notice : Invalid value\n");
			return NULL;
		}

		TargetNode = TargetNode->NextNode;
	}
	return TargetNode;
}

int CDLL_GetNodeSize2(Node* Head)
{
	unsigned int Count = 0;

	Node* TargetNode = Head;
	
	do
	{
		Count += 1;
		TargetNode = TargetNode->NextNode;
	} while (TargetNode != Head);

	return Count;
}

void CDLL_Print2(Node* Head)
{
	if (Head == NULL)
	{
		printf("No List\n");
		return;
	}

	Node* TargetNode = Head;

	int i = 0;

	while (TargetNode != NULL)
	{
		printf("Prev: %d\n", TargetNode->PrevNode->Data);
		printf("¤¤ List[%d] : %d\n", i, TargetNode->Data);
		printf("Next: %d\n\n", TargetNode->NextNode->Data);

		TargetNode = TargetNode->NextNode;
		i += 1;

		if (TargetNode == Head)
			break;
	}
}