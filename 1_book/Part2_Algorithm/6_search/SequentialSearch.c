#include <stdio.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
}Node;

Node* SLL_SequentialSearch(Node* Head, int Target)
{
	Node* Current = Head;
	Node* Match = NULL;

	while (Current != NULL)
	{
		// 찾고자 하는 값을 해당 노드가 가지고 있으면
		// 노드의 주소를 Match에 저장한다
		if (Current->Data == Target)
		{
			Match = Current;
			break;
		}

		// 현재 노드에 찾는 값이 없으면
		// 다음 노드를 조사한다
		Current = Current->NextNode;
	}

	// 찾는 값을 갖고 있는 노드의 주소를 반환한다
	return Match;
}