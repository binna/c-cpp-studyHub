#ifndef __CALCULATE_BOOK_H_
#define __CALCULATE_BOOK_H_

#include "1_CalculateLinkedList_Book.h"

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
};

int IsNumber(char Cipher);
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char OperatorInStack, char OperatorInToken);
void GetPostfix(char* InfixExpression, char* PostfixExpression);
double Calculate(char* PostfixExpression);
#endif
 