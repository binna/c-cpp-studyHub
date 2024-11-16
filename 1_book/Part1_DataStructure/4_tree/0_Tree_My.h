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

void TreeCreateNode0(Tree** Root, int deep, int NewData);
void TreeDeleteNode0(Tree** Root, int deep, int childNo);

int TreeGetNode0(Tree** Root, int deep, int childNo);

void TreePrintNode0(Tree* Root);
#endif