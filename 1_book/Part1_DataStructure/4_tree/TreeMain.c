#include "0_Tree_My.h"

int main(void)
{
	Tree* Root = NULL;

	TreePrintNode0(Root);
	TreeDeleteNode0(&Root, 0, 1);

	TreeCreateNode0(&Root, 1, 10);
	TreeCreateNode0(&Root, 5, 50);
	TreeCreateNode0(&Root, 1, 11);
	TreeCreateNode0(&Root, 1, 12);
	TreeCreateNode0(&Root, 2, 20);
	TreeCreateNode0(&Root, 3, 30);
	TreeCreateNode0(&Root, 3, 31);

	TreePrintNode0(Root);

	TreeDeleteNode0(&Root, 1, 1);
	TreeDeleteNode0(&Root, 1, 5);
	TreeDeleteNode0(&Root, 5, 1);

	printf("========================================\n");

	TreeDeleteNode0(&Root, 1, 2);
	TreeDeleteNode0(&Root, 3, 2);
	TreeDeleteNode0(&Root, 3, 1);

	TreePrintNode0(Root);

	printf("%d\n", TreeGetNode0(Root, 1, 1));
	printf("%d\n", TreeGetNode0(Root, 1, 0));
	printf("%d\n", TreeGetNode0(Root, 2, 1));
	printf("%d\n", TreeGetNode0(Root, 2, 5));
	printf("%d\n", TreeGetNode0(Root, 3, 1));
	printf("%d\n", TreeGetNode0(Root, 3, 0));
	return 0;
}