#include "RedBlackTree.h"

// => 오른쪽 서브트리의 가장 작은 값

// Nil 노드
// RB 트리에서 leaf 노드는 Nil 노드
// 아무 데이터를 갖지 않지는 않지만 색깔만 검은색인 더미 노드이다
extern RBTNode* Nil;

RBTNode* RBT_CreateNode(ElementType NewData)
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));

	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	NewNode->Color = BLACK;

	return NewNode;
}

void RBT_DestroyNode(RBTNode* Node)
{
	free(Node);
}

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target)
{
	if (Tree == Nil)
		return NULL;

	if (Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);

	if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);

	return Tree;
}

RBTNode* RBT_SearchMinNode(RBTNode* Tree)
{
	if (Tree == Nil)
		return Nil;

	if (Tree->Left == Nil)
		return Tree;

	return RBT_SearchMinNode(Tree->Left);
}

void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode)
{
	// 이진 탐색 트리의 노드 삽입을 수행한다
	RBT_InsertNodeHelper(Tree, NewNode);

	// 새 노드는 빨간색으로 칠하고 양쪽 자식에 Nil을 연결한다
	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;

	// 무너진 레드 블랙 트리 규칙을 바로 잡는다
	RBT_RebuildAfterInsert(Tree, NewNode);
}

void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode)
{
	if ((*Tree) == NULL)
	{
		(*Tree) = NewNode;
		return;
	}

	if ((*Tree)->Data < NewNode->Data)
	{
		if ((*Tree)->Right == Nil)
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper(&(*Tree)->Right, NewNode);
		}
	}
	else if ((*Tree)->Data > NewNode->Data)
	{
		if ((*Tree)->Left == Nil)
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper(&(*Tree)->Left, NewNode);
		}
	}
}

RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Data)
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);

	if (Target == NULL)
	{
		return NULL;
	}

	if (Target->Left == Nil || Target->Right == Nil)
	{
		Removed = Target;
	}
	else
	{
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;
	}

	if (Removed->Left != Nil)
		Successor = Removed->Left;
	else
		Successor = Removed->Right;

	Successor->Parent = Removed->Parent;

	if (Removed->Parent == NULL)
	{
		(*Root) = Successor;
	}
	else
	{
		if (Removed == Removed->Parent->Left)
		{
			Removed->Parent->Left = Successor;
		}
		else
		{
			Removed->Parent->Right = Successor;
		}
	}

	if (Removed->Color == BLACK)
	{
		RBT_RebuildAfterRemove(Root, Successor);
	}

	return Removed;
}

void RBT_DestroyTree(RBTNode* Tree)
{
	if (Tree->Right != Nil)
		RBT_DestroyTree(Tree->Right);

	if (Tree->Left != Nil)
		RBT_DestroyTree(Tree->Left);

	Tree->Left = Nil;
	Tree->Right = Nil;

	RBT_DestroyNode(Tree);
}

// 레드 블랙 트리의 규칙 ===============================================
// 1. 모든 노드는 빨간색 아니면 검은색이다
// 2. 루트 노드는 검은색이다
// 3. 잎 노드는 검은색이다
// 4. 빨간 노드의 자식들은 모두 검은색이다
//    하지만 검은색 노드의 자식은 빨간색일 필요는 없다
//    즉, 빨간 노드는 연속적으로 존재할 수 없다
// 5. 루트 노드에서 모든 잎 노드 사이에 있는 검은색 노드의 수는 동일하다
// ===================================================================

// 삽입 규칙 ==========================================================
// ** 삽입하는 새 노드는 빨간색 **
// 1. 삼촌도 빨간색인 경우
//    부모 노드와 삼촌 노드를 검은색으로 칠하고 
//    할아버지 노드를 빨간색으로 칠하면 됨
//    ㄴ 4번 규칙을 위반하고 있는지 체크
// 2. 삼촌이 검은색이면서 새로 삽입한 노드가 부모 노드의 오른쪽 자식인 경우
//    부모 노드를 왼쪽으로 회전시켜 
//    이 상황을 세 번째 경우의 문제로 바꾼다
// 3. 삼촌이 검은색이면서 새로 삽입한 노드가 부모 노드의 왼쪽 자식인 경우
//    부모 노드를 검은색, 할아버지 노드를 빨간색으로 칠한 다음
//    할아버지 노드를 오른쪽으로 회전
//    ㄴ 세번째의 경우를 처리하고 난 다음에는 4번 규칙이 위반되지 않는다
// ===================================================================
void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X)
{
	// 4번 규칙을 위반하고 있는 동안에는 계속 반복한다
	while (X != (*Root) && X->Parent->Color == RED)
	{
		// 부모 노드가 할아버지 노드의 왼쪽 자식인 경우
		if (X->Parent == X->Parent->Parent->Left)
		{
			// 삼촌은 오른쪽
			RBTNode* Uncle = X->Parent->Parent->Right;
			if (Uncle->Color == RED)		// 삼촌이 빨간색인 경우
			{
				// 삽입 1번 규칙
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;

				// 4번 규칙을 위반하고 있는지 체크
				X = X->Parent->Parent;
			}
			else							// 삼촌이 검은색인 경우
			{
				if (X == X->Parent->Right)	// X가 오른쪽 자식일 때
				{
					// 삽입 2번 규칙
					X = X->Parent;
					RBT_RotateLeft(Root, X);
				}

				// 3번 규칙 처리
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateRight(Root, X->Parent->Parent);
			}
		}

		// 부모 노드가 할아버지 노드의 오른쪽 자식인 경우
		else
		{
			// 삼촌은 왼쪽
			RBTNode* Uncle = X->Parent->Parent->Left;
			if (Uncle->Color == RED)
			{
				// 삽입 1번 규칙
				X->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				X->Parent->Parent->Color = RED;

				// 4번 규칙을 위반하고 있는지 체크
				X = X->Parent->Parent;
			}
			else							// 삼촌이 검은색인 경우
			{
				if (X == X->Parent->Left)	// X가 왼쪽 자식일 때,
				{
					// 삽입 2번 규칙
					X = X->Parent;
					RBT_RotateRight(Root, X);
				}

				// 삽입 3번 규칙
				X->Parent->Color = BLACK;
				X->Parent->Parent->Color = RED;
				RBT_RotateLeft(Root, X->Parent->Parent);
			}
		}
	}

	// 루트 노드는 반드시 검은색이어야 한다
	(*Root)->Color = BLACK;
}

// 삭제 규칙 ==========================================================
// - 삭제한 노드가 빨간색인 경우, 어떤 뒷처리도 할 필요가 없다
// - 삭제한 노드가 검은색인 경우, 4번과 5번의 규칙이 무너지기 때문에 조치가 필요하다
//                              이때 조치하는 것이 이중 흑색 처리 -> 5번 규칙보단 1번 규칙을 해결하는 것이 쉽기 때문에
// 1. 형제가 빨간색인 경우
//    형제를 검은색, 부모를 빨간색으로 칠하고
//    이중흑색 노드가 왼쪽 자식일 때는 좌회전을 수행
// 2. 형제가 검은색이고 형제의 양쪽 자식이 모두 검은색인 경우
//    형제 노드만 빨간색으로 칠한 다음,
//    이중흑색 노드가 갖고 있던 두 개의 검은색 중 하나를 부모 노드에게 넘김
// 3. 형제가 검은색이고 왼쪽 자식은 빨간색, 오른쪽 자식이 검은색인 경우
//    형제 노드를 빨간색으로 칠하고
//    왼쪽 자식을 검은색으로 칠한 다음,
//    형제 노드를 기준으로 우회전을 수행
// 4. 형제가 검은색이고 오른쪽 자식이 빨간색인 경우
//    이중흑색 노드의 부모 노드가 갖고 있는 색을 형제 노드에 칠한다
//    부모 노드와 형제 노드의 오른쪽 자식 노드를 검은색으로 칠하고 부모 노드를 기준으로 좌회전
// ===================================================================
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* Successor)
{
	RBTNode* Sibling = NULL;

	// 루트 노드이거나 빨간색 노드한테 검은색이 넘어가면 루프 종료
	while (Successor->Parent != NULL && Successor->Color == BLACK)
	{
		// 이중흑색 노드가 왼쪽 자식일 때
		if (Successor == Successor->Parent->Left)
		{
			Sibling = Successor->Parent->Right;

			// 1. 형제가 빨간색인 경우
			if (Sibling->Color == RED)
			{
				// 형제를 검은색, 부모를 빨간색으로 칠한다
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;

				// 이중흑색 노드가 왼쪽 자식일때는 좌회전을 수행
				RBT_RotateLeft(Root, Successor->Parent);
			}

			// 2. 3. 4. 형제가 검은색이고
			else
			{
				// 2. 형제의 양쪽 자식이 검은색일 때
				if (Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
				{
					// 형제 노드만 빨간색으로 칠한 다음
					Sibling->Color = RED;
					// 이중흑색 노드가 갖고 있던 두 개의 검은색 중 하나를 부모 노드에게 넘김
					Successor = Successor->Parent;
				}
				else
				{
					// 3. 형제의 왼쪽 자식이 빨간색일 때
					if (Sibling->Left->Color == RED)
					{
						// 형제 노드를 빨간색으로 칠하고
						// 왼쪽 자식을 검은색으로 칠한 다음,
						Sibling->Left->Color = BLACK;
						Sibling->Color = RED;

						// 형제 노드를 기준으로 우회전을 수행
						RBT_RotateRight(Root, Sibling);
						Sibling = Successor->Parent->Right;
					}

					// 4. 오른쪽 자식이 빨간색인 경우
					// 이중흑색 노드의 부모 노드가 갖고 있는 색을 형제 노드에 칠한다
					Sibling->Color = Successor->Parent->Color;
					
					// 부모 노드와 형제 노드의 오른쪽 자식 노드를 검은색으로 칠하고 
					Successor->Parent->Color = BLACK;
					Sibling->Right->Color = BLACK;

					// 부모 노드를 기준으로 좌회전
					RBT_RotateLeft(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}

		// Successor가 부모의 오른쪽 노드일 때 -> 왼쪽과 반대로
		else
		{
			Sibling = Successor->Parent->Left;

			// 1. 형제가 빨간색인 경우
			if (Sibling->Color == RED)
			{
				// 형제를 검은색, 부모를 빨간색으로 칠한다
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;

				// 이중흑색 노드가 왼쪽 자식일때는 우회전을 수행
				RBT_RotateRight(Root, Successor->Parent);
			}

			// 2. 3. 4. 형제가 검은색이고
			else
			{
				// 2. 형제의 양쪽 자식이 검은색일 때
				if (Sibling->Right->Color == BLACK && Sibling->Left->Color == BLACK)
				{
					// 형제 노드만 빨간색으로 칠한 다음
					Sibling->Color = RED;
					// 이중흑색 노드가 갖고 있던 두 개의 검은색 중 하나를 부모 노드에게 넘김
					Successor = Successor->Parent;
				}
				else
				{
					// 3. 형제의 왼쪽 자식이 빨간색일 때
					if (Sibling->Right->Color == RED)
					{
						// 형제 노드를 빨간색으로 칠하고
						// 왼쪽 자식을 검은색으로 칠한 다음,
						Sibling->Right->Color = BLACK;
						Sibling->Color = RED;

						// 형제 노드를 기준으로 좌회전을 수행
						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}

					// 4. 오른쪽 자식이 빨간색인 경우
					// 이중흑색 노드의 부모 노드가 갖고 있는 색을 형제 노드에 칠한다
					Sibling->Color = Successor->Parent->Color;
					

					// 부모 노드와 형제 노드의 오른쪽 자식 노드를 검은색으로 칠하고 
					Successor->Parent->Color = BLACK;
					Sibling->Left->Color = BLACK;

					// 부모 노드를 기준으로 좌회전
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}

	Successor->Color = BLACK;
} 

void RBT_PrintTree(RBTNode* Node, int Depth, int BlackCount)
{
	int i = 0;
	char c = 'X';
	int v = -1;
	char cnt[100];

	if (Node == NULL || Node == Nil)
	{
		return;
	}

	if (Node->Color == BLACK)
	{
		BlackCount++;
	}

	if (Node->Parent != NULL)
	{
		v = Node->Parent->Data;

		if (Node->Parent->Left == Node)
		{
			c = 'L';
		}
		else
		{
			c = 'R';
		}
	}

	if (Node->Left == Nil && Node->Right == Nil)
		sprintf_s(cnt, sizeof(cnt), "--------- %d", BlackCount);
	else
		sprintf_s(cnt, sizeof(cnt), "");

	for (i = 0; i < Depth; i++)
	{
		printf(" ");
	}

	printf("%d %s [%c,%d] %s\n", Node->Data, (Node->Color == RED) ? "RED" : "BLACK", c, v, cnt);

	RBT_PrintTree(Node->Left, Depth + 1, BlackCount);
	RBT_PrintTree(Node->Right, Depth + 1, BlackCount);
}

void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* RightChild = Parent->Right;

	Parent->Right = RightChild->Left;

	if (RightChild->Left != Nil)
	{
		RightChild->Left->Parent = Parent;
	}

	RightChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = RightChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = RightChild;
		}
		else
		{
			Parent->Parent->Right = RightChild;
		}

		RightChild->Left = Parent;
		Parent->Parent = RightChild;
	}
}

void RBT_RotateRight(RBTNode** Root, RBTNode* Parent)
{
	RBTNode* LeftChild = Parent->Left;

	Parent->Left = LeftChild->Right;

	if (LeftChild->Right != Nil)
	{
		LeftChild->Right->Parent = Parent;
	}

	LeftChild->Parent = Parent->Parent;

	if (Parent->Parent == NULL)
	{
		(*Root) = LeftChild;
	}
	else
	{
		if (Parent == Parent->Parent->Left)
		{
			Parent->Parent->Left = LeftChild;
		}
		else
		{
			Parent->Parent->Right = LeftChild;
		}

		LeftChild->Right = Parent;
		Parent->Parent = LeftChild;
	}
}