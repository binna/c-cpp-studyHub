#include "2_LinkedListStack_Final.h"

void LLS_CreateStack2(LinkedListStack** Stack)
{
	if ((*Stack) != NULL)
	{
		printf("System Notice : Already exist Stack Info\n");
		return;
	}

	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack2(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty2(Stack))
	{
		Node* Popped = LLS_Pop2(Stack);
		LLS_DestoryNode2(Popped);
	}

	free(Stack);
}

Node* LLS_CreateNode2(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void LLS_DestoryNode2(Node* Node)
{
	free(Node);
}

void LLS_Push2(LinkedListStack* Stack, ElementType NewData)
{
	if (Stack == NULL)
	{
		printf("System Notice : Stack not created\n");
		return;
	}

	Node* NewNode = LLS_CreateNode2(NewData);

	if (NewNode == NULL)
		return;

	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
		Stack->Top = NewNode;
		return;
	}

	Node* OldTop = Stack->List;
	while (OldTop->NextNode != NULL)
	{
		OldTop = OldTop->NextNode;
	}

	OldTop->NextNode = NewNode;
	Stack->Top = NewNode;
}

Node* LLS_Pop2(LinkedListStack* Stack)
{
	if (Stack == NULL)
	{
		printf("System Notice : Stack not created\n");
		return NULL;
	}

	Node* TopNode = Stack->Top;

	if (Stack->List == NULL)
	{
		printf("System Notice : No Deleted Data\n");
		return NULL;
	}

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
		return TopNode;
	}

	Node* CurrentTop = Stack->List;

	while (CurrentTop->NextNode != NULL && CurrentTop->NextNode != Stack->Top)
	{
		CurrentTop = CurrentTop->NextNode;
	}

	Stack->Top = CurrentTop;

	if (CurrentTop != NULL)
		CurrentTop->NextNode = NULL;

	return TopNode;
}

Node* LLS_Top2(LinkedListStack* Stack)
{
	if (Stack == NULL)
		return NULL;

	return Stack->Top;
}

int LLS_GetSize2(LinkedListStack* Stack)
{
	unsigned int Count = 0;
	
	if (Stack != NULL)
	{
		Node* CurrentNode = Stack->List;

		while (CurrentNode != NULL)
		{
			CurrentNode = CurrentNode->NextNode;
			Count += 1;
		}
	}

	return Count;
}

int LLS_IsEmpty2(LinkedListStack* Stack)
{
	return (Stack == NULL) || (Stack->List == NULL);
}

void LLS_Print2(LinkedListStack* Stack)
{
	if (Stack == NULL || Stack->List == NULL)
	{
		printf("Linked List Stack ==================\n");
		printf("Size : %d\n", LLS_GetSize2(Stack));
		printf("No Data\n");
		printf("====================================\n");
		return;
	}

	printf("Linked List Stack ==================\n");
	printf("Size : %d\n", LLS_GetSize2(Stack));

	Node* CurrentNode = Stack->List;
	int i = 0;
	
	while (CurrentNode != NULL) 
	{
		printf(">> Data[%d] : %d\n", i++, CurrentNode->Data);
		CurrentNode = CurrentNode->NextNode;
	}
	printf("====================================\n");
}