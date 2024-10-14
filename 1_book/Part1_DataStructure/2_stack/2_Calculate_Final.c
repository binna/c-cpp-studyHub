#include "2_Calculate_Final.h"

char NUMBER[] = { '0', '1','2','3','4','5','6','7','8','9','.' };
int NUMBER_SIZE = sizeof(NUMBER);

int IsNumber2(char Cipher)
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		if (Cipher == NUMBER[i])
			return 1;
	}

	return 0;
}

unsigned int GetNextToken2(char* Expression, char* Token, int* TYPE)
{
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++)
	{
		Token[i] = Expression[i];

		if (IsNumber2(Expression[i]) == 1)
		{
			*TYPE = OPERAND;

			if (IsNumber2(Expression[i + 1]) != 1)
				break;
		}
		else
		{
			*TYPE = Expression[i];
			break;
		}
	}

	Token[++i] = '\0';
	return i;
}

int GetPriority2(char Operator, int InStack)
{
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (InStack)
			Priority = 3;
		else
			Priority = 0;
		break;
	case MULTIPLY:
	case DIVIDE:
		Priority = 1;
		break;
	case PLUS:
	case MINUS:
		Priority = 2;
		break;
	}

	return Priority;
}

// 우선순위가 
// 토큰이 더 빠를 경우 true
// 스택이 빠른 경우 false
int IsHighPriorInToken2(int OperatorInStack, char OperatorInToken)
{
	return GetPriority2(OperatorInStack, 1) > GetPriority2(OperatorInToken, 0);
}

void GetPostfix2(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;

	char Token[32];
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	LLS_CreatStack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken2(&InfixExpression[Position], Token, &Type);

		if (Type == OPERAND)
		{
			strcat_s(PostfixExpression, strlen(PostfixExpression) + strlen(Token) + 1, Token);
			strcat_s(PostfixExpression, strlen(PostfixExpression) + strlen(" ") + 1, " ");
		}
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(Stack))
			{
				Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] == LEFT_PARENTHESIS)
				{
					LLS_DestroyNode(Popped);
					break;
				}
				else
				{
					strcat_s(PostfixExpression, strlen(PostfixExpression) + strlen(Popped->Data) + 1, Popped->Data);
					LLS_DestroyNode(Popped);
				}
			}
		}
		else
		{
			// 1. 스택이 비어있지 않고
			// 2. 스택 안에 있는 연산자와 Token 비교, 스택 안에 있는 연산자가 우선순위가 빠른 경우 
			while (!LLS_IsEmpty(Stack) && !IsHighPriorInToken2(LLS_Top(Stack)->Data[0], Token[0]))
			{
				Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] != LEFT_PARENTHESIS)
					strcat_s(PostfixExpression, strlen(PostfixExpression) + strlen(Popped->Data) + 1, Popped->Data);

				LLS_DestroyNode(Popped);
			}

			LLS_Push(Stack, LLS_CreateNode(Token));
		}
	}

	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);

		if (Popped->Data[0] != LEFT_PARENTHESIS)
			strcat_s(PostfixExpression, strlen(PostfixExpression) + strlen(Popped->Data) + 1, Popped->Data);

		LLS_DestroyNode(Popped);
	}

	LLS_DestroyStack(Stack);
}

double Calculate2(char* expression, int IsPostfix)
{
	LinkedListStack* Stack;
	Node* ResultNode;

	char PostfixExpression[100];

	memset(PostfixExpression, 0, sizeof(PostfixExpression));

	if (IsPostfix)
	{
		if (expression == "")
			return -1.0;

		strcpy_s(PostfixExpression, strlen(expression) + 1, expression);
	}
	else
		GetPostfix2(expression, PostfixExpression);

	printf(">> %s\n", expression);
	printf(">> %s\n", PostfixExpression);

	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	LLS_CreatStack(&Stack);

	while (Read < Length)
	{
		Read += GetNextToken2(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
		{
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode);
		}
		else
		{
			char ResultString[32];
			double Operator1, Operator2, TempResult = 0.0;
			Node* OperatorNode;

			OperatorNode = LLS_Pop(Stack);
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			OperatorNode = LLS_Pop(Stack);
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS:
				TempResult = Operator1 + Operator2;
				break;
			case MINUS:
				TempResult = Operator1 - Operator2;
				break;
			case MULTIPLY:
				TempResult = Operator1 * Operator2;
				break;
			case DIVIDE:
				TempResult = Operator1 / Operator2;
				break;
			}

			_gcvt_s(ResultString, sizeof(ResultString), TempResult, 10);
			LLS_Push(Stack, LLS_CreateNode(ResultString));
		}
	}

	ResultNode = LLS_Pop(Stack);
	Result = atof(ResultNode->Data);

	LLS_DestroyNode(ResultNode);
	LLS_DestroyStack(Stack);

	return Result;
}