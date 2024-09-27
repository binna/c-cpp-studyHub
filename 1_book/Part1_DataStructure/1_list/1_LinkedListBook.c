#include "1_LinkedListBook.h"

// 노드 생성
Node* SLL_CreateNode1(ElementType const NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;         // 데이터를 저장
    NewNode->NextNode = NULL;        // 다음 노드에 대한 포인터는 NULL로 초기화

    return NewNode;                  // 생성한 노드의 주소를 반환
}

// 노드 소멸
void SLL_DestroyNode1(Node* Node)
{
    free(Node);
}

// 노드 추가
void SLL_AppendNode1(Node** Head, Node* NewNode)
{
    // 헤드 노드가 NULL이면 새로운 노드가 헤드
    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }

    // 헤드 노드가 있는 경우
    // 1. 테일을 찾아
    Node* Tail = (*Head);
    while (Tail->NextNode != NULL)
    {
        Tail = Tail->NextNode;
    }

    // 2.NewNode를 연결
    Tail->NextNode = NewNode;
}

// 노드 삽입
void SLL_InsertAfter1(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertNewHead1(Node** Head, Node* NewHead)
{
    // 헤드 노드가 없다면
    if (*Head == NULL)
    {
        (*Head) = NewHead;
        return;
    }

    // 헤드 노드가 있다면
    NewHead->NextNode = (*Head);
    (*Head) = NewHead;
}

void SLL_RemoveNode1(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        return;
    }

    Node* Current = *Head;
    while (Current != NULL && Current->NextNode != Remove)
    {
        Current = Current->NextNode;
    }

    if (Current != NULL)
    {
        Current->NextNode = Remove->NextNode;
    }
}

// 노드 탐색
Node* SLL_GetNodeAt1(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

// 노드 수 세기
int SLL_GetNodeCount1(Node* Head)
{
    int Count  = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}