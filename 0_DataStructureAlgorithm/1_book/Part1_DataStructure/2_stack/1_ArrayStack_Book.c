#include "1_ArrayStack_Book.h"

// 역참조? 주소를 통해 값에 접근하는 것

void AS_CreateStack1(ArrayStack** Stack, int Capacity)
{
	// 스택을 자유저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice : No Stack Info\n");
		return;
	}

	// 입력된 Capacity만큼의 노드를 자유저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	if ((*Stack)->Nodes == NULL)
	{
		printf("System Notice : Out of Memory\n");
		return;
	}

	// Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_DestroyStack1(ArrayStack* Stack)
{
	// 노드를 자유저장소에서 해제
	free(Stack->Nodes);

	// 스택을 자유저장소에서 해제
	free(Stack);
}

void AS_Push1(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top += 1;
}

ElementType AS_Pop1(ArrayStack* Stack)
{
	int Position = --(Stack->Top);
	return Stack->Nodes[Position].Data;
}

ElementType AS_Top1(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;
	return Stack->Nodes[Position].Data;
}

int AS_GetSize1(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty1(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}

int AS_IsFull1(ArrayStack* Stack)
{
	return (Stack->Top == Stack->Capacity);
}