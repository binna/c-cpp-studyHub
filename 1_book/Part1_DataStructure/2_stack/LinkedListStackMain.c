#include "0_LinkedListStack_My.h"

int main(void)
{
	ListStack* Stack = LS_CreateStack0();

	LS_Print0(Stack);
	
	LS_Push0(&Stack, 10);

	LS_Print0(Stack);

	LS_Pop0(Stack);

	LS_Print0(Stack);

	LS_Push0(&Stack, 10);
	LS_Push0(&Stack, 20);
	LS_Push0(&Stack, 30);
	LS_Push0(&Stack, 40);
	LS_Push0(&Stack, 50);

	LS_Print0(Stack);
	printf("%s\n", LS_IsEmpty0(Stack) ? "비었음" : "안 비었음");

	LS_Pop0(Stack);

	LS_Print0(Stack);

	LS_Pop0(Stack);
	LS_Pop0(Stack);

	LS_Print0(Stack);

	LS_Pop0(Stack);
	LS_Pop0(Stack);
	LS_Pop0(Stack);
	LS_Pop0(Stack);

	LS_Print0(Stack);

	printf("%s\n", LS_IsEmpty0(Stack) ? "비었음" : "안 비었음");

	return 0;
}