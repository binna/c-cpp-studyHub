#include "0_LinkedListMy.h"

// 노드 추가
void AppendNode(Node** List, int Data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("System Notice : Out of memory\n");
        return;
    }

    newNode->Data = Data;
    newNode->NextNode = NULL;

    if (*List == NULL)
    {
        *List = newNode;
        return;
    }

    Node* tailNode = *List;
    while (tailNode->NextNode != NULL) {
        tailNode = tailNode->NextNode;
    }
    tailNode->NextNode = newNode;
}

// 노드 중간 삽입
void InsertNode(Node** List, int Location, int Data)
{
    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowedn");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("System Notice : Out of memory\n");
        return;
    }

    newNode->Data = Data;
    newNode->NextNode = NULL;

    Node* prevNode = *List;
    Node* targetNode = *List;
    while (Location-- > 0) {
        if (targetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }

        prevNode = targetNode;
        targetNode = targetNode->NextNode;
    }

    if (prevNode == targetNode)
    {
        if (targetNode->NextNode == NULL)
        {
            *List = newNode;
            return;
        }
        newNode->NextNode = *List;
        *List = newNode;
        return;
    }

    prevNode->NextNode = newNode;
    newNode->NextNode = targetNode;
}

// 수정
void ModifyNode(Node** List, int Data, int Location)
{
    if (*List == NULL)
    {
        printf("System Notice : No saved linked list\n");
        return;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return;
    }

    if (Location == 0)
    {
        (*List)->Data = Data;
        return;
    }

    Node* targetNode = *List;
    while (Location-- > 0) {
        if (targetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }
        targetNode = targetNode->NextNode;
    }

    targetNode->Data = Data;
}

// 삭제
void DeleteNode(Node** List, int Location)
{
    if (*List == NULL)
    {
        printf("System Notice : No deleted linked list\n");
        return;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return;
    }

    Node* prevNode = *List;
    Node* targetNode = *List;
    while (Location-- > 0) {
        if (targetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }
        prevNode = targetNode;
        targetNode = targetNode->NextNode;
    }

    if (prevNode == targetNode)
    {
        if (targetNode->NextNode == NULL)
        {
            *List = NULL;
            return;
        }
        *List = targetNode->NextNode;
        free(targetNode);
        return;
    }

    prevNode->NextNode = targetNode->NextNode;
    free(targetNode);
}

// 검색
int Select(Node* List, int Location)
{
    if (List == NULL)
    {
        printf("System Notice : a linked list that does not exist\n");
        return -1;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return -1;
    }

    Node* targetNode = List;
    while (Location-- > 0) {
        if (targetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return -1;
        }
        targetNode = targetNode->NextNode;
    }

    return targetNode->Data;
}

int Size(Node* List)
{
    if (List == NULL)
    {
        printf("System Notice : a linked list that does not exist\n");
        return -1;
    }

    int count = 0;
    Node* targetNode = List;
    while (1)
    {
        count += 1;

        targetNode = targetNode->NextNode;
        if (targetNode == NULL)
            break;
    }

    return count;
}

// 출력
void Print(Node* List)
{
    printf("print start ----\n");
    if (List == NULL)
    {
        printf("System Notice : No saved linked list\n");
        return;
    }

    Node* targetNode = List;
    while (1)
    {
        printf(">> data : %d\n", targetNode->Data);
        targetNode = targetNode->NextNode;

        if (targetNode == NULL)
            break;
    }
    printf("----------------\n");
}