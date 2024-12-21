#include "SBT_Tree_my.h"

SBTNode* SBT_CreateNode(ElementType Data)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Data = Data;
	NewNode->Left = NULL;
	NewNode->Rigth = NULL;

	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 소멸
	SBT_DestroyNode(Node->Left);

	// 오른쪽 하위 트리 소멸
	SBT_DestroyNode(Node->Rigth);

	// 루트 노드 소멸
	SBT_DestroyNode(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 루트 출력
	printf("  %c", Node->Data);

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Rigth);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_InorderPrintTree(Node->Left);

	// 루트 출력
	printf("   %c", Node->Data);

	// 오른쪽 하위 트리 출력
	SBT_InorderPrintTree(Node->Rigth);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PostorderPrintTree(Node->Rigth);

	// 루트 출력
	printf("   %c", Node->Data);
}