#include "0_ArrayStack_My.h"

Stack init1(int Size)
{
	if (Size <= 0)
	{
		printf("System Notice : Invalid index\n");
		return;
	}

	ElementType* NewData = (Stack*)malloc(sizeof(ElementType) * Size);
	if (NewData == NULL)
	{
		printf("System Notice : Out of memory\n");
		return;
	}

	for (int i = 0; i < Size; i++)
	{
		NewData[i] = i;
	}
	
	Stack NewStack = { 0, Size, NewData };

	return NewStack;
}

void Push1(Stack* Stack, ElementType NewData)
{
	if (Stack->Top >= Stack->Size)
	{
		printf("System Notice : Memory exceeded\n");
		return;
	}

	Stack->Data[Stack->Top] = NewData;
	Stack->Top += 1;
}

void Pop1(Stack* Stack)
{
	if (Stack->Top <= 0)
	{
		printf("System Notice : No data to delete\n");
		return;
	}

	if (Stack->Top > 0)
		Stack->Top -= 1;

	Stack->Data[Stack->Top] = 0;
}

void Print1(Stack* Stack)
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
		printf(">> data[%d] : %d\n", i, Stack->Data[i]);
	}
	printf("==========================================\n");
}