#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree->Right != NULL)
		BST_DestroyNode(Tree->Right);

	if (Tree->Left != NULL)
		BST_DestroyNode(Tree->Left);

	Tree->Right = NULL;
	Tree->Left = NULL;

	BST_DestroyNode(Tree);
}

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Data == Target)
		return Tree;

	if (Tree->Data > Target)
		return BST_SearchNode(Tree->Left, Target);

	return BST_SearchNode(Tree->Right, Target);
}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == NULL)
		return NULL;

	if (Tree->Left == NULL)
		return Tree;

	return BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
	if (Tree->Data < Child->Data)
	{
		if (Tree->Right == NULL)
			Tree->Right = Child;
		else
			BST_InsertNode(Tree->Right, Child);
	}
	else if (Tree->Data > Child->Data)
	{
		if (Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode(Tree->Left, Child);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* Removed = NULL;

	if (Tree == NULL)
		return NULL;

	if (Tree->Data > Target)
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	else if(Tree->Data < Target)
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	else		// 목표값을 찾은 경우
	{
		Removed = Tree;

		// 잎 노드인 경우 바로 삭제
		if (Tree->Left == NULL && Tree->Right == NULL)
		{
			if (Tree->Left == NULL)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		else
		{
			// 자식이 양쪽에 다 있는 경우
			if (Tree->Left != NULL && Tree->Right != NULL)
			{
				// 최소값 노드를 찾아 제거한 뒤 현재의 노드에 위치시킨다
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);
				Removed = BST_RemoveNode(Tree, NULL, MinNode->Data);	// MinNode에 대해 BST_RemoveNode 함수를 호출하는 이유는 
																		// 이 노드에 대해서도 제거 후의 뒤처리가 필요하기 때문이다
				Tree->Data = MinNode->Data;
			}
			else	// 자식이 하나만 있는 경우
			{
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL)
					Temp = Tree->Left;
				else
					Temp = Tree->Right;

				if (Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Right = Temp;
			}
		}
	}
	
	return Removed;
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if (Node == NULL)
		return;

	// 왼쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Left);

	// 루트 노드 출력
	printf("%d ", Node->Data);
	
	// 오른쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Right);
}