#include "0_LCRS_Tree_My.h"

int main(void)
{
	Tree* Root = NULL;

	LCRS_TreePrintNode0(Root);
	LCRS_TreeDeleteNode0(&Root, 0, 1);

	LCRS_TreeCreateNode0(&Root, 1, 10);
	LCRS_TreeCreateNode0(&Root, 5, 50);
	LCRS_TreeCreateNode0(&Root, 1, 11);
	LCRS_TreeCreateNode0(&Root, 1, 12);
	LCRS_TreeCreateNode0(&Root, 2, 20);
	LCRS_TreeCreateNode0(&Root, 3, 30);
	LCRS_TreeCreateNode0(&Root, 3, 31);

	LCRS_TreePrintNode0(Root);

	LCRS_TreeDeleteNode0(&Root, 1, 1);
	LCRS_TreeDeleteNode0(&Root, 1, 5);
	LCRS_TreeDeleteNode0(&Root, 5, 1);

	printf("========================================\n");

	LCRS_TreeDeleteNode0(&Root, 1, 2);
	LCRS_TreeDeleteNode0(&Root, 3, 2);
	LCRS_TreeDeleteNode0(&Root, 3, 1);

	LCRS_TreePrintNode0(Root);

	printf("%d\n", LCRS_TreeGetNode0(Root, 1, 1));
	printf("%d\n", LCRS_TreeGetNode0(Root, 1, 0));
	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 1));
	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 5));
	printf("%d\n", LCRS_TreeGetNode0(Root, 3, 1));
	printf("%d\n", LCRS_TreeGetNode0(Root, 3, 0));
	return 0;
}