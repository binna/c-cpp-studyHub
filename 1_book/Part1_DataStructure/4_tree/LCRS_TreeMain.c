//#include "0_LCRS_Tree_My.h"
//
//int main(void)
//{
//	Tree* Root = NULL;
//
//	LCRS_TreePrintNode0(Root);
//	LCRS_TreeDeleteNode0(&Root, 0, 1);
//
//	LCRS_TreeCreateNode0(&Root, 1, 10);
//	LCRS_TreeCreateNode0(&Root, 5, 50);
//	LCRS_TreeCreateNode0(&Root, 1, 11);
//	LCRS_TreeCreateNode0(&Root, 1, 12);
//	LCRS_TreeCreateNode0(&Root, 2, 20);
//	LCRS_TreeCreateNode0(&Root, 3, 30);
//	LCRS_TreeCreateNode0(&Root, 3, 31);
//
//	LCRS_TreePrintNode0(Root);
//
//	LCRS_TreeDeleteNode0(&Root, 1, 1);
//	LCRS_TreeDeleteNode0(&Root, 1, 5);
//	LCRS_TreeDeleteNode0(&Root, 5, 1);
//
//	printf("========================================\n");
//
//	LCRS_TreeDeleteNode0(&Root, 1, 2);
//	LCRS_TreeDeleteNode0(&Root, 3, 2);
//	LCRS_TreeDeleteNode0(&Root, 3, 1);
//
//	LCRS_TreePrintNode0(Root);
//
//	printf("%d\n", LCRS_TreeGetNode0(Root, 1, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 1, 0));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 5));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 3, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 3, 0));
//	return 0;
//}

#include "1_LCRS_Tree_Book.h"

int main(void)
{
	// 노드 생성
	LCRSNode* Root = LCRS_CreateNode('A');

	LCRSNode* B = LCRS_CreateNode('B');
	LCRSNode* C = LCRS_CreateNode('C');
	LCRSNode* D = LCRS_CreateNode('D');
	LCRSNode* E = LCRS_CreateNode('E');
	LCRSNode* F = LCRS_CreateNode('F');
	LCRSNode* G = LCRS_CreateNode('G');
	LCRSNode* H = LCRS_CreateNode('H');
	LCRSNode* I = LCRS_CreateNode('I');
	LCRSNode* J = LCRS_CreateNode('J');
	LCRSNode* K = LCRS_CreateNode('K');

	// 트리에 노드 추가
	LCRS_AddChildNode(Root, B);

	LCRS_AddChildNode(B, C);
	LCRS_AddChildNode(B, D);

	LCRS_AddChildNode(D, E);
	LCRS_AddChildNode(D, F);

	LCRS_AddChildNode(Root, G);
	
	LCRS_AddChildNode(G, H);

	LCRS_AddChildNode(Root, I);

	LCRS_AddChildNode(I, J);

	LCRS_AddChildNode(J, K);

	// 트리 출력
	LCRS_PrintTree(Root, 0);

	// 트리 소멸
	LCRS_DestroyTree(Root);

	return 0;
}