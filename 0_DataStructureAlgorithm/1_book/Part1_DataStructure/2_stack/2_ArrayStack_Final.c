#include "2_ArrayStack_Final.h"

void AS_CreateStack2(ArrayStack** Stack, int Capacity)
{
	// 스택을 자유저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	if ((*Stack) == NULL)
	{
		printf("System Notice : No Stack Info\n");
		return;
	}

	// 입력된 Capacity 만큼 노드를 자유저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	if ((*Stack)->Nodes == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	// Capacity 및 Top 초기화
	(*Stack)->Top = 0;
	(*Stack)->Capacity = Capacity;

	// 노드 초기화
	for (int i = 0; i < Capacity; i++)
	{
		(*Stack)->Nodes->Data = 0;
	}
}

void AS_DestroyStack2(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push2(ArrayStack* Stack, ElementType Data)
{
	if (Stack == NULL)
	{
		printf("System Notice : No Stack Info\n");
		return;
	}

	if (Stack->Capacity <= Stack->Top)
	{
		printf("System Notice : Memory exceeded\n");
		return;
	}

	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top += 1;
}

ElementType AS_Pop2(ArrayStack* Stack)
{
	if (Stack == NULL)
	{
		printf("System Notice : No Stack Info\n");
		return;
	}

	if (Stack->Top <= 0)
	{
		printf("System Notice : No data to delete\n");
		return;
	}

	int Position = Stack->Top;
	ElementType ReturnData = Stack->Nodes[Position].Data;

	if (Stack->Top > 0)
		Stack->Top -= 1;

	Stack->Nodes[Position].Data = 0;

	return ReturnData;
}

ElementType AS_Top2(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;
	return Stack->Nodes[Position].Data;
}

int AS_GetSize2(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty2(ArrayStack* Stack)
{
	return Stack->Top == 0;
}

int AS_IsFull2(ArrayStack* Stack)
{
	return Stack->Top >= Stack->Capacity;
}

void Print2(ArrayStack* Stack)
{
	printf("Stack List ===============================\n");

	if (Stack == NULL)
	{
		printf("System Notice : No Stack Info\n");
		printf("==========================================\n");
		return;
	}

	printf("Size : %d\n", Stack->Top);

	if (Stack->Top <= 0)
	{
		printf("System Notice : No Data\n");
		printf("==========================================\n");
		return;
	}

	for (int i = 0; i < Stack->Top; i++)
	{
		printf(">> data[%d] : %d\n", i, Stack->Nodes[i].Data);
	}
	printf("==========================================\n");
}