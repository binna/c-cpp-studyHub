#ifndef __TREE_MY_H_
#define __TREE_MY_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TagTree
{
	int Data;

	struct TagTree* leftNode;
	struct TagTree* rightNode;
}Tree;

void LCRS_TreeCreateNode0(Tree** Root, int deep, int NewData);
void LCRS_TreeDeleteNode0(Tree** Root, int deep, int childNo);

int LCRS_TreeGetNode0(Tree** Root, int deep, int childNo);

void LCRS_TreePrintNode0(Tree* Root);
#endif