#ifndef __LINKED_LIST_FINAL_H_
#define __LINKED_LIST_FINAL_H_

#include <string.h>

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

void GetPostfix2(char* InfixExpression, char* PostfixExpression);
double Calculate2(char* PostfixExpression, int IsPostfix);
#endif
