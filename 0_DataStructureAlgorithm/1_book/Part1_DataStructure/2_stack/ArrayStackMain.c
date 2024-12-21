//#include "0_ArrayStack_My.h"
//
//int main(void)
//{
//	Stack Stack = init1(5);
//
//	Print1(&Stack);
//	
//	Push1(&Stack, 10);
//	Push1(&Stack, 20);
//	Push1(&Stack, 30);
//	Push1(&Stack, 40);
//	Push1(&Stack, 50);
//	Push1(&Stack, 60);
//
//	Print1(&Stack);
//
//	Pop1(&Stack);
//	Pop1(&Stack);
//	Pop1(&Stack);
//	Pop1(&Stack);
//	Pop1(&Stack);
//	Pop1(&Stack);
//	Pop1(&Stack);
//
//	for (int i = 0; i < Stack.Size; i++)
//	{
//		printf(">> data[%i] : %d\n", i, Stack.Data[i]);
//	}
//
//	Print1(&Stack);
//
//	Push1(&Stack, 100);
//	Push1(&Stack, 200);
//	Push1(&Stack, 300);
//
//	Print1(&Stack);
//
//	return 0;
//}


//#include "1_ArrayStack_Book.h"
//
//int main(void)
//{
//	int i = 0;
//	ArrayStack* Stack = NULL;
//
//	AS_CreateStack1(&Stack, 5);
//
//	printf("isFull : %d\n", AS_IsFull1(Stack));
//
//	AS_Push1(Stack, 3);
//	AS_Push1(Stack, 37);
//	AS_Push1(Stack, 11);
//	AS_Push1(Stack, 12);
//
//	printf("Capacity : %d, Size : %d, Top%d\n\n", 
//		Stack->Capacity, AS_GetSize1(Stack), AS_Top1(Stack));
//	printf("isFull : %d\n", AS_IsFull1(Stack));
//
//	while (1)
//	{
//		if (AS_IsEmpty1(Stack))
//			break;
//
//		printf("Popped : %d, ", AS_Pop1(Stack));
//
//		if (!AS_IsEmpty1(Stack))
//			printf("Current Top : %d\n", AS_Top1(Stack));
//		else
//			printf("Stack Is Empty.\n");
//	}
//
//	printf("isFull : %d\n", AS_IsFull1(Stack));
//
//	AS_Push1(Stack, 50);
//	AS_Push1(Stack, 60);
//	AS_Push1(Stack, 70);
//	AS_Push1(Stack, 80);
//	AS_Push1(Stack, 90);
//
//	printf("isFull : %d\n", AS_IsFull1(Stack));
//
//	AS_DestroyStack1(Stack);
//		
//	return 0;
//}


#include "2_ArrayStack_Final.h"

int main(void)
{
	ArrayStack* Stack = NULL;

	AS_CreateStack2(&Stack, 5);

	Print2(Stack);

	printf("Is Full : %d, Is Empty : %d\n",
		AS_IsFull2(Stack), AS_IsEmpty2(Stack));

	AS_Push2(Stack, 10);
	AS_Push2(Stack, 20);
	AS_Push2(Stack, 30);
	AS_Push2(Stack, 40);
	AS_Push2(Stack, 50);
	AS_Push2(Stack, 60);

	Print2(Stack);

	printf("Is Full : %d, Is Empty : %d\n",
		AS_IsFull2(Stack), AS_IsEmpty2(Stack));

	int i = 0;
	while (!AS_IsEmpty2(Stack))
	{
		printf("%d¹øÂ° / Size %d =========================\n",
			++i, AS_GetSize2(Stack));
		AS_Pop2(Stack);
		Print2(Stack);
	}

	AS_DestroyStack2(Stack);

	return 0;
}