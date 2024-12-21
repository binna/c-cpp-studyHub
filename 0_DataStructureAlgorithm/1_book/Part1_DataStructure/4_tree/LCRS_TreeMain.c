//#include "0_LCRS_Tree_My.h"
//
//int main(void)
//{
//	Tree* Root = NULL;
//
//	LCRS_TreePrintNode0(Root);
//	LCRS_TreeDeleteNode0(&Root, 0, 1);
//	LCRS_TreeCreateNode0(&Root, 1, 10);
//
//	printf("========================================\n");
//
//	LCRS_TreeCreateNode0(&Root, 0, 10);
//	LCRS_TreeCreateNode0(&Root, 5, 50);
//	LCRS_TreeCreateNode0(&Root, 1, 11);
//	LCRS_TreeCreateNode0(&Root, 1, 12);
//	LCRS_TreeCreateNode0(&Root, 2, 20);
//	LCRS_TreeCreateNode0(&Root, 3, 30);
//	LCRS_TreeCreateNode0(&Root, 3, 31);
//
//	LCRS_TreePrintNode0(Root);
//
//	LCRS_TreeDeleteNode0(&Root, 4, 1);
//	LCRS_TreeDeleteNode0(&Root, 1, 2);
//	LCRS_TreeDeleteNode0(&Root, 1, 5);
//	LCRS_TreeDeleteNode0(&Root, 1, 3);
//	
//	LCRS_TreePrintNode0(Root);
//
//	LCRS_TreeCreateNode0(&Root, 1, 15);
//	LCRS_TreeCreateNode0(&Root, 1, 16);
//	LCRS_TreeCreateNode0(&Root, 1, 17);
//	LCRS_TreeCreateNode0(&Root, 1, 18);
//	LCRS_TreeCreateNode0(&Root, 1, 19);
//
//	LCRS_TreePrintNode0(Root);
//
//	LCRS_TreeDeleteNode0(&Root, 1, 3);
//	LCRS_TreeDeleteNode0(&Root, 1, 2);
//	LCRS_TreeDeleteNode0(&Root, 1, 1);
//	LCRS_TreeDeleteNode0(&Root, 1, 1);
//	LCRS_TreeDeleteNode0(&Root, 1, 1);
//	LCRS_TreeDeleteNode0(&Root, 1, 1);
//
//	LCRS_TreePrintNode0(Root);
//
//	printf("%d\n", LCRS_TreeGetNode0(Root, 0, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 1, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 1));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 2));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 2, 5));
//	printf("%d\n", LCRS_TreeGetNode0(Root, 3, 1));
//
//	return 0;
//}

//#include "1_LCRS_Tree_Book.h"
//
//int main(void)
//{
//	// 노드 생성
//	LCRSNode* Root = LCRS_CreateNode1('A');
//
//	LCRSNode* B = LCRS_CreateNode1('B');
//	LCRSNode* C = LCRS_CreateNode1('C');
//	LCRSNode* D = LCRS_CreateNode1('D');
//	LCRSNode* E = LCRS_CreateNode1('E');
//	LCRSNode* F = LCRS_CreateNode1('F');
//	LCRSNode* G = LCRS_CreateNode1('G');
//	LCRSNode* H = LCRS_CreateNode1('H');
//	LCRSNode* I = LCRS_CreateNode1('I');
//	LCRSNode* J = LCRS_CreateNode1('J');
//	LCRSNode* K = LCRS_CreateNode1('K');
//
//	// 트리에 노드 추가
//	LCRS_AddChildNode1(Root, B);
//
//	LCRS_AddChildNode1(B, C);
//	LCRS_AddChildNode1(B, D);
//
//	LCRS_AddChildNode1(D, E);
//	LCRS_AddChildNode1(D, F);
//
//	LCRS_AddChildNode1(Root, G);
//	
//	LCRS_AddChildNode1(G, H);
//
//	LCRS_AddChildNode1(Root, I);
//
//	LCRS_AddChildNode1(I, J);
//
//	LCRS_AddChildNode1(J, K);
//
//	// 트리 출력
//	LCRS_PrintTree1(Root, 0);
//
//	// 트리 소멸
//	LCRS_DestroyTree1(Root);
//
//	return 0;
//}

#include "2_LCRS_Tree_Final.h"

int main(void)
{
	LCRSNode* Root = NULL;
	LCRS_CreateTree2(&Root);

	LCRS_PrintTree2(Root);

	LCRS_AddChildNodeByDepth2(Root, 0, 'A');
	LCRS_AddChildNodeByDepth2(Root, 0, 'B');
	LCRS_AddChildNodeByDepth2(Root, 0, 'C');

	LCRS_AddChildNodeByDepth2(Root, 1, 'D');
	LCRS_AddChildNodeByDepth2(Root, 1, 'E');
	LCRS_AddChildNodeByDepth2(Root, 1, 'F');
	LCRS_AddChildNodeByDepth2(Root, 1, 'G');
	LCRS_AddChildNodeByDepth2(Root, 1, 'H');

	LCRS_AddChildNodeByDepth2(Root, 3, 'I');
	LCRS_AddChildNodeByDepth2(Root, 3, 'J');
	LCRS_AddChildNodeByDepth2(Root, 3, 'K');
	LCRS_AddChildNodeByDepth2(Root, 3, 'L');

	LCRS_AddChildNodeByDepth2(Root, 2, 'M');
	LCRS_AddChildNodeByDepth2(Root, 2, 'N');
	LCRS_AddChildNodeByDepth2(Root, 2, 'O');
	LCRS_AddChildNodeByDepth2(Root, 2, 'P');

	LCRS_PrintTree2(Root);

	LCRS_DeleteChildNode2(Root, 0, 3);
	LCRS_DeleteChildNode2(Root, 2, 3);
	LCRS_DeleteChildNode2(Root, 3, 1);
	LCRS_DeleteChildNode2(Root, 2, 5);
	LCRS_DeleteChildNode2(Root, 2, 1);
	LCRS_DeleteChildNode2(Root, 2, 1);
	LCRS_DeleteChildNode2(Root, 2, 1);
	LCRS_DeleteChildNode2(Root, 2, 1);
	LCRS_DeleteChildNode2(Root, 2, 1);

	LCRS_PrintTree2(Root);

	LCRS_AddChildNodeByDepth2(Root, 2, 'm');
	LCRS_AddChildNodeByDepth2(Root, 2, 'n');
	LCRS_AddChildNodeByDepth2(Root, 2, 'o');
	LCRS_AddChildNodeByDepth2(Root, 2, 'p');

	LCRS_PrintTree2(Root);

	LCRS_DeleteChildNode2(Root, 1, 1);
	LCRS_DeleteChildNode2(Root, 1, 1);
	LCRS_DeleteChildNode2(Root, 1, 1);
	LCRS_DeleteChildNode2(Root, 1, 1);
	LCRS_DeleteChildNode2(Root, 1, 1);
	LCRS_DeleteChildNode2(Root, 1, 1);

	LCRS_PrintTree2(Root);

	printf("=> %c\n", LCRS_GetNodeData2(Root, 1, 2));
	printf("=> %c\n", LCRS_GetNodeData2(Root, 1, 1));

	printf("=> %c\n", LCRS_GetNodeData2(Root, 2, 2));
	printf("=> %c\n", LCRS_GetNodeData2(Root, 2, 4));

	printf("=> %c\n", LCRS_GetNodeData2(Root, 3, 1));
	printf("=> %c\n", LCRS_GetNodeData2(Root, 3, 5));

	printf("=> %c\n", LCRS_GetNodeData2(Root, 1, 5));

	LCRS_DestroyTree2(Root);

	return 0;
}