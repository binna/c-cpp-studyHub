//#include "0_LinkedListStack_My.h"
//
//int main(void)
//{
//	ListStack* Stack = LS_CreateStack0();
//
//	LS_Print0(Stack);
//	
//	LS_Push0(&Stack, 10);
//
//	LS_Print0(Stack);
//
//	LS_Pop0(Stack);
//
//	LS_Print0(Stack);
//
//	LS_Push0(&Stack, 10);
//	LS_Push0(&Stack, 20);
//	LS_Push0(&Stack, 30);
//	LS_Push0(&Stack, 40);
//	LS_Push0(&Stack, 50);
//
//	LS_Print0(Stack);
//	printf("%s\n", LS_IsEmpty0(Stack) ? "비었음" : "안 비었음");
//
//	LS_Pop0(Stack);
//
//	LS_Print0(Stack);
//
//	LS_Pop0(Stack);
//	LS_Pop0(Stack);
//
//	LS_Print0(Stack);
//
//	LS_Pop0(Stack);
//	LS_Pop0(Stack);
//	LS_Pop0(Stack);
//	LS_Pop0(Stack);
//
//	LS_Print0(Stack);
//
//	printf("%s\n", LS_IsEmpty0(Stack) ? "비었음" : "안 비었음");
//
//	return 0;
//}

//#include "1_LinkedListStack_Book.h"
//
//int main(void)
//{
//	int Count = 0;
//	Node* Popped;
//
//	LinkedListStack* Stack;
//
//	LLS_CreateStack1(&Stack);
//
//	LLS_Push1(Stack, LLS_CreateNode1("abc"));
//	LLS_Push1(Stack, LLS_CreateNode1("def"));
//	LLS_Push1(Stack, LLS_CreateNode1("efg"));
//	LLS_Push1(Stack, LLS_CreateNode1("hij"));
//
//	Count = LLS_GetSize1(Stack);
//	printf("Size : %d, Top : %s\n\n", Count, LLS_Top1(Stack)->Data);
//
//	for (int i = 0; i < Count; i++)
//	{
//		if (LLS_IsEmpty1(Stack))
//			break;
//
//		Popped = LLS_Pop1(Stack);
//
//		printf("Popped: %s, ", Popped->Data);
//
//		LLS_DestroyNode1(Popped);
//
//		if (!LLS_IsEmpty1(Stack))
//		{
//			printf("Current Top : %s\n", LLS_Top1(Stack)->Data);
//		}
//		else
//		{
//			printf("Stack Is Empty.\n");
//		}
//	}
//	return 0;
//}

#include "2_LinkedListStack_Final.h"

int main(void)
{
	LinkedListStack* Stack = NULL;

	printf("%s\n", LLS_IsEmpty2(Stack) ? "비었음" : "안 비었음");

	Node* Top = LLS_Top2(Stack);
	if (Top == NULL)
	{
		printf("!!! NULL\n");
	}
	else
	{
		printf("!!! %d\n", Top->Data);
	}

	LLS_Push2(Stack, 10);

	LLS_Print2(Stack);

	LLS_CreateStack2(&Stack);

	LLS_Push2(Stack, 10);

	Top = LLS_Top2(Stack);
	if (Top == NULL)
	{
		printf("!!! NULL\n");
	}
	else 
	{
		printf("!!! %d\n", Top->Data);
	}

	Top = LLS_Top2(Stack);
	if (Top == NULL)
	{
		printf("!!! NULL\n");
	}
	else
	{
		printf("!!! %d\n", Top->Data);
	}
	printf("%s\n", LLS_IsEmpty2(Stack) ? "비었음" : "안 비었음");
	LLS_Print2(Stack);

	LLS_DestoryNode2(LLS_Pop2(Stack));

	Top = LLS_Top2(Stack);
	if (Top == NULL)
	{
		printf("!!! NULL\n");
	}
	else
	{
		printf("!!! %d\n", Top->Data);
	}

	printf("%s\n", LLS_IsEmpty2(Stack) ? "비었음" : "안 비었음");
	LLS_Print2(Stack);

	LLS_Push2(Stack, 10);
	LLS_Push2(Stack, 20);
	LLS_Push2(Stack, 30);
	LLS_Push2(Stack, 40);
	LLS_Push2(Stack, 50);

	Top = LLS_Top2(Stack);
	if (Top == NULL)
	{
		printf("!!! NULL\n");
	}
	else
	{
		printf("!!! %d\n", Top->Data);
	}

	printf("%s\n", LLS_IsEmpty2(Stack) ? "비었음" : "안 비었음");
	LLS_Print2(Stack);

	LLS_DestroyStack2(Stack);
	
	return 0;
}