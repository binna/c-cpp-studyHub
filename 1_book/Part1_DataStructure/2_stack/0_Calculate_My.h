#ifndef __CALCULATE_MY_H_
#define __CALCULATE_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TagNode
{
	char Data;
	struct TagNode* NextNode;
}Node;

typedef struct TagListStack
{
	struct TagNode* List;
	struct TagNode* Top;

}ListStack;

double Calculate0(const char* TargetCalPlaint);
char* ConvertPostfix0(const char* infixPlaint);
#endif