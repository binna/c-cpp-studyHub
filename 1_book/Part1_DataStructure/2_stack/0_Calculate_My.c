#include "0_Calculate_My.h"

void CreateStack0(ListStack** Stack)
{
	if ((*Stack) != NULL)
	{
		printf("System Notice 1\n");
		return;
	}

	(*Stack) = (ListStack*)malloc(sizeof(ListStack));

	if ((*Stack) == NULL)
	{
		printf("System Notice\n");
		return;
	}

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void DestroyStack0(ListStack* Stack)
{
	free(Stack);
}

void Push0(ListStack* Stack, char NewData)
{
	if (Stack == NULL)
	{
		printf("System Notice 1\n");
		return;
	}

	Node* NewNode = (Node*)malloc(sizeof(Node));

	if (NewNode == NULL)
	{
		printf("System Notice 2\n");
		return;
	}

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

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

void Push0ByNode(ListStack* Stack, Node* NewNode)
{
	if (Stack == NULL)
	{
		printf("System Notice 1\n");
		return;
	}

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

Node* Pop0(ListStack* Stack)
{
	if (Stack == NULL)
	{
		printf("System Notice 3\n");
		return NULL;
	}

	if (Stack->List == NULL)
	{
		printf("System Notice 4\n");
		return NULL;
	}

	Node* OldTop = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
		return OldTop;
	}

	Node* TargetNode = Stack->List;
	while (TargetNode != NULL && TargetNode->NextNode != Stack->Top)
	{
		TargetNode = TargetNode->NextNode;
	}

	if (TargetNode != NULL)
		TargetNode->NextNode = NULL;

	Stack->Top = TargetNode;

	return OldTop;
}

int IsEmpty0(ListStack* Stack)
{
	return (Stack == NULL) || (Stack->List == NULL);
}

double Calculate0(const char* TargetCalPlaint)
{
	ListStack* Stack = NULL;

	CreateStack0(&Stack);

	double resultNum = 0;

	for (int i = 0; i < strlen(TargetCalPlaint); i++)
	{
		switch (TargetCalPlaint[i])
		{
		case '+':
		{
			Node* Temp1 = Pop0(Stack);
			Node* Temp2 = Pop0(Stack);

			double operand1 = Temp1->Data - '0';
			double operand2 = Temp2->Data - '0';

			free(Temp1);
			free(Temp2);

			resultNum = operand2 + operand1;
			Push0(Stack, (resultNum + '0'));
			break;
		}
		case '-':
		{
			Node* Temp1 = Pop0(Stack);
			Node* Temp2 = Pop0(Stack);

			double operand1 = Temp1->Data - '0';
			double operand2 = Temp2->Data - '0';

			free(Temp1);
			free(Temp2);

			resultNum = operand2 - operand1;
			Push0(Stack, (resultNum + '0'));
			break;
		}
		case '*':
		{
			Node* Temp1 = Pop0(Stack);
			Node* Temp2 = Pop0(Stack);

			double operand1 = Temp1->Data - '0';
			double operand2 = Temp2->Data - '0';

			free(Temp1);
			free(Temp2);

			resultNum = operand2 * operand1;
			Push0(Stack, (resultNum + '0'));
			break;
		}
		case '/':
		{
			Node* Temp1 = Pop0(Stack);
			Node* Temp2 = Pop0(Stack);

			double operand1 = Temp1->Data - '0';
			double operand2 = Temp2->Data - '0';

			free(Temp1);
			free(Temp2);

			resultNum = operand2 / operand1;
			Push0(Stack, (resultNum + '0'));
			break;
		}
		default:
			Push0(Stack, TargetCalPlaint[i]);
			break;
		}
	}

	DestroyStack0(Stack);

	return resultNum;
}

char* ConvertPostfix0(const char* infixPlaint)
{
	char* postfixPlaint = (char*)malloc(strlen(infixPlaint) + 1);
	int idx = 0;

	ListStack* operatorStack = NULL;

	CreateStack0(&operatorStack);

	for (int i = 0; i < strlen(infixPlaint); i++)
	{
		
		switch (infixPlaint[i])
		{
		case '(':
		{
			Push0(operatorStack, infixPlaint[i]);
			break;
		}
		case ')':
		{
			while (1)
			{
				Node* Popped = Pop0(operatorStack);

				if (Popped->Data == '(')
				{
					free(Popped);
					break;
				}
				
				postfixPlaint[idx++] = Popped->Data;
				printf("%c", Popped->Data);
				free(Popped);
			}
			break;
		}
		case '-':
		case '+':
		{
			if (IsEmpty0(operatorStack))
			{
				Push0(operatorStack, infixPlaint[i]);
				break;
			}

			Node* Popped = Pop0(operatorStack);

			if (Popped->Data == infixPlaint[i] || Popped->Data == '*' || Popped->Data == '/')
			{
				postfixPlaint[idx++] = Popped->Data;
				printf("%c", Popped->Data);
			}
			else
			{
				Push0ByNode(operatorStack, Popped);
			}

			Push0(operatorStack, infixPlaint[i]);
			break;
		}
		case '/':
		case '*':
		{
			if (IsEmpty0(operatorStack))
			{
				Push0(operatorStack, infixPlaint[i]);
				break;
			}

			Node* Popped = Pop0(operatorStack);

			if (Popped->Data == infixPlaint[i])
			{
				postfixPlaint[idx++] = Popped->Data;
				printf("%c", Popped->Data);
				free(Popped);
			}
			else
			{
				Push0ByNode(operatorStack, Popped);
			}

			Push0(operatorStack, infixPlaint[i]);
			break;
		}
		default:
			postfixPlaint[idx++] = infixPlaint[i];
			printf("%c", infixPlaint[i]);
			break;
		}

	}

	while (!IsEmpty0(operatorStack))
	{
		Node* Popped = Pop0(operatorStack);
		postfixPlaint[idx++] = Popped->Data;
		printf("%c", Popped->Data);
		free(Popped);
	}

	postfixPlaint[idx] = 0;
	printf("\n");

	return postfixPlaint;
}