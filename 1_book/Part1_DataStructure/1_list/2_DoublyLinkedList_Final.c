#include "2_DoublyLinkedList_Final.h"

Node* DLL_CreateNode2(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NewNode;
	}

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DLL_AppendNode2(Node** Head, ElementType NewData)
{
	Node* NewNode = DLL_CreateNode2(NewData);

	if (NewNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	if (*Head == NULL)
	{
		*Head = NewNode;
		return;
	}

	Node* TailNode = *Head;
	while (TailNode->NextNode != NULL)
	{
		TailNode = TailNode->NextNode;
	}

	TailNode->NextNode = NewNode;
	NewNode->PrevNode = TailNode;
}

void DLL_InsertNode2(Node** Head, int Location, ElementType NewData)
{
	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* NewNode = DLL_CreateNode2(NewData);

	if (NewNode == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	if (Location == 0)
	{
		NewNode->NextNode = *Head;
		*Head = NewNode;
		return;
	}

	Node* TargetNode = *Head;
	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			if (Location == 0)
			{
				TargetNode->NextNode = NewNode;
				NewNode->PrevNode = TargetNode;
				return;
			}
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}

	TargetNode->PrevNode->NextNode = NewNode;

	NewNode->PrevNode = TargetNode->PrevNode;
	NewNode->NextNode = TargetNode;

	TargetNode->PrevNode = NewNode;
}

void DLL_ModifyNode2(Node** Head, int Location, ElementType NewData)
{
	if (*Head == NULL)
	{
		printf("System Notice : No saved doubly linked list\n");
		return;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = *Head;
	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}
	TargetNode->Data = NewData;
}

void DLL_RemoveNode2ByLocation(Node** Head, int Location)
{
	if (*Head == NULL)
	{
		printf("System Notice : No deleted doubly linked list\n");
		return;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative number is not allowed\n");
		return;
	}

	Node* TargetNode = *Head;

	if (Location == 0)
	{
		TargetNode->NextNode->PrevNode = NULL;
		(*Head) = TargetNode->NextNode;
		free(TargetNode);
		return;
	}

	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return;
		}
		TargetNode = TargetNode->NextNode;
	}

	if (TargetNode->NextNode != NULL)
	{
		TargetNode->NextNode->PrevNode = TargetNode->PrevNode;
		TargetNode->PrevNode->NextNode = TargetNode->NextNode;
	}
	else
	{
		TargetNode->PrevNode->NextNode = NULL;
	}

	free(TargetNode);
}

void DLL_RemoveNode2ByNode(Node** Head, Node* Remove)
{
	if (*Head == NULL)
	{
		printf("System Notice : No doubly Deleted linked list\n");
		return;
	}

	Node* TargetNode = *Head;

	if (*Head == Remove)
	{
		*Head = Remove->NextNode;

		if (*Head != NULL)
			(*Head)->PrevNode = NULL;

		free(TargetNode);
		return;
	}

	while (TargetNode != NULL)
	{
		if (TargetNode == Remove)
		{
			Node* Temp = Remove;

			if (Remove->PrevNode != NULL)
				Remove->PrevNode->NextNode = Temp->NextNode;
			
			if (Remove->NextNode != NULL)
				Remove->NextNode->PrevNode = Temp->PrevNode;

			free(Remove);
		}
		TargetNode = TargetNode->NextNode;
	}
}

Node* DLL_GetNode2(Node* Head, int Location)
{
	if (Head == NULL)
	{
		printf("System Notice : a doubly linked list that does not exist\n");
		return NULL;
	}

	if (Location < 0)
	{
		printf("System Notice : Negative numver is not allowed\n");
		return NULL;
	}

	Node* TargetNode = Head;

	if (Location == 0)
	{
		return TargetNode;

	}

	while (Location--)
	{
		if (TargetNode->NextNode == NULL || Location < 0)
		{
			printf("System Notice : Invalid index\n");
			return NULL;
		}
		TargetNode = TargetNode->NextNode;
	}
	return TargetNode;
}

int DLL_GetNodeSize2(Node* Head)
{
	unsigned int Count = 0;

	Node* TargetNode = Head;
	while (TargetNode != NULL)
	{
		TargetNode = TargetNode->NextNode;
		Count += 1;
	}

	return Count;
}

void DLL_Print2(Node* Head)
{
	printf("DLL ======================\n");
	if (Head == NULL)
	{
		printf("System Notice : No saved doubly linked list\n");
		return;
	}
	
	Node* TargetNode = Head;
	int i = 0;
	
	while (TargetNode != NULL)
	{
		printf(">>> data[%d] : %d\n", i, TargetNode->Data);
		TargetNode = TargetNode->NextNode;
		i += 1;
	}
	printf("==========================\n");
}