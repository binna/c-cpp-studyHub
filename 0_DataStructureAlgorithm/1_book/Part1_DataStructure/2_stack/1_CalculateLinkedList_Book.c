#include "1_CalculateLinkedList_Book.h"

void LLS_CreatStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	if (NewNode->Data == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return NULL;
	}

	strcpy_s(NewNode->Data, strlen(NewData) + 1, NewData);
	NewNode->NextNode = NULL;
	return NewNode;
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
	}
	else
	{
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}

	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		Node* CurrentTop = Stack->List;

		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;

		if (CurrentTop != NULL)
			CurrentTop->NextNode = NULL;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	unsigned int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count += 1;
	}

	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}