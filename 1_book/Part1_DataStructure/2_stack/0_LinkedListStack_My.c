#include "0_LinkedListStack_My.h"

ListStack* LS_CreateStack0()
{
	ListStack* NewStack = (ListStack*)malloc(sizeof(ListStack));

	if (NewStack == NULL)
	{
		printf("System Notice : \n");
		return NULL;
	}

	NewStack->Capacity = 0;
	NewStack->Top = NULL;
	NewStack->Nodes = NULL;

	return NewStack;
}

Node* LS_CreateStackNode0(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice : \n");
		return NULL;
	}

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

void LS_Push0(ListStack** Stack, ElementType NewData)
{
	if ((*Stack) == NULL)
	{
		(*Stack) = LS_CreateStack0();

		if ((*Stack) == NULL)
			return;
	}

	Node* NewNode = LS_CreateStackNode0(NewData);

	if (NewNode == NULL)
		return;

	if ((*Stack)->Nodes == NULL)
	{
		(*Stack)->Nodes = NewNode;
		(*Stack)->Top = NewNode;
		(*Stack)->Capacity = 1;
		return;
	}

	NewNode->PrevNode = (*Stack)->Top;
	(*Stack)->Top->NextNode = NewNode;
	(*Stack)->Top = NewNode;
	(*Stack)->Capacity += 1;
}

ElementType LS_Pop0(ListStack* Stack)
{
	if (Stack == NULL || Stack->Capacity == 0)
	{
		printf("System Notice : No Data to deleted\n");
		return NULL;
	}

	ElementType ReturnData = Stack->Top->Data;
	Node* Temp = Stack->Top;

	if (Stack->Capacity == 1)
	{
		Stack->Nodes = NULL;
		Stack->Top = NULL;
		Stack->Capacity -= 1;

		free(Temp);

		return ReturnData;
	}

	Stack->Top = Temp->PrevNode;
	Temp->PrevNode->NextNode = NULL;
	Stack->Capacity -= 1;

	free(Temp);

	return ReturnData;
}

Node* LS_Top0(ListStack* Stack)
{
	if (Stack == NULL || Stack->Capacity == 0)
	{
		printf("System Notice : No Top Data\n");
		return;
	}

	return Stack->Top;
}

unsigned int LS_GetSize0(ListStack* Stack)
{
	return Stack->Capacity;
}

int LS_IsEmpty0(ListStack* Stack)
{
	return (Stack->Capacity == 0);
}

void LS_Print0(ListStack* Stack)
{
	if (Stack == NULL || Stack->Capacity == 0)
	{
		printf("Linked List Stack ==================\n");
		printf("Size : %d\n", LS_GetSize0(Stack));
		printf("No Data\n");
		printf("====================================\n");
		return;
	}

	printf("Linked List Stack ==================\n");
	printf("Size : %d\n", LS_GetSize0(Stack));
	Node* TargetNode = Stack->Top;
	int i = 0;
	while (TargetNode != NULL)
	{
		printf(">> Data[%d] : %d\n", i, TargetNode->Data);
		TargetNode = TargetNode->PrevNode;
	}
	printf("====================================\n");
}