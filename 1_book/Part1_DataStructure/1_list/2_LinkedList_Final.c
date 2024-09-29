#include "2_LinkedList_Final.h"

Node* SLL_CreateNode2(const ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        printf("System Notice : Out of Memory\n");
        return NewNode;
    }

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    return NewNode;
}

void SLL_AppendNode2(Node** Head, const ElementType NewData)
{
    Node* NewNode = SLL_CreateNode2(NewData);
    if (NewNode == NULL)
        return;

    if (*Head == NULL)
    {
        *Head = NewNode;
        return;
    }

    Node* TailNode = *Head;
    while (TailNode->NextNode != NULL)
    {
        TailNode = TailNode->NextNode;
    }
    TailNode->NextNode = NewNode;
}

void SLL_InsertNode2(Node** Head, int Location, const ElementType NewData)
{
    if (Location < 0)
    {
        printf("System Notice : Negative Number is not allowed\n");
        return;
    }

    Node* NewNode = SLL_CreateNode2(NewData);
    if (NewNode == NULL)
        return;

    Node* PrevNode = *Head;
    Node* TargetNode = *Head;
    while (Location-- > 0)
    {
        if (TargetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }

        PrevNode = TargetNode;
        TargetNode = TargetNode->NextNode;
    }

    if (PrevNode == TargetNode)
    {
        if(TargetNode == NULL)
        {
            *Head = NewNode;
            return;
        }
        NewNode->NextNode = *Head;
        *Head = NewNode;
        return;
    }

    PrevNode->NextNode = NewNode;
    NewNode->NextNode = TargetNode;
}

void SLL_ModifyNode2(Node** Head, int Location, const ElementType Data)
{
    if (*Head == NULL)
    {
        printf("System Notice : No saved linked list\n");
        return;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowdn\n");
        return;
    }

    if (Location == 0)
    {
        (*Head)->Data = Data;
        return;
    }

    Node* TatgetNode = *Head;
    while (Location-- > 0) {
        if (TatgetNode->NextNode == NULL) {
            printf("System Notice : Invalid index\n");
            return;
        }
        TatgetNode = TatgetNode->NextNode;
    }
    TatgetNode->Data = Data;
}

void SLL_RemoveNode2ByLocation(Node** Head, int Location)
{
    if (*Head == NULL)
    {
        printf("System Notice : No Deleted linked list\n");
        return;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowdn\n");
        return;
    }

    Node* PrevNode = *Head;
    Node* TargetNode = *Head;
    while (Location-- > 0)
    {
        if (TargetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }
        PrevNode = TargetNode;
        TargetNode = TargetNode->NextNode;
    }

    if (PrevNode == TargetNode)
    {
        if (TargetNode->NextNode == NULL)
        {
            *Head = NULL;
            free(TargetNode);
            return;
        }
        *Head = TargetNode->NextNode;
        free(TargetNode);
        return;
    }

    PrevNode->NextNode = TargetNode->NextNode;
    free(TargetNode);
}

void SLL_RemoveNode2ByNode(Node** Head, Node* Remove)
{
    if (*Head == NULL)
    {
        printf("System Notice : No Deleted linked list\n");
        return;
    }

    Node* TargetNode = *Head;
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
        free(TargetNode);
        return;
    }

    while(TargetNode != NULL && TargetNode->NextNode != Remove)
    {
        TargetNode = TargetNode->NextNode;
    }

    if (TargetNode != NULL)
    {
        TargetNode->NextNode = Remove->NextNode;
        free(Remove);
    }
}

Node* SLL_GetNode2(Node* Head, int Location)
{
    if (Head == NULL)
    {
        printf("System Notice : Linked list that does not exist\n");
        return NULL;
    }

    if (Location < 0)
    {
        printf("System Notice : Negative number is not allowdn\n");
        return NULL;
    }

    Node* TargetNode = Head;
    while (Location-- > 0)
    {
        if (TargetNode->NextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return NULL;
        }
        TargetNode = TargetNode->NextNode;
    }
    return  TargetNode;
}

int SLL_GetNodeSize2(Node* Head)
{
    int size = 0;

    if (Head == NULL)
        return size;

    Node* TargetNode = Head;
    while (TargetNode != NULL)
    {
        size += 1;
        TargetNode = TargetNode->NextNode;
    }
    return size;
}

void SLL_Print2(Node* Head)
{
    printf("print start ----\n");

    if (Head == NULL)
        return;

    Node* TargetNode = Head;
    while (TargetNode != NULL)
    {
        printf(">> data : %d\n", TargetNode->Data);
        TargetNode = TargetNode->NextNode;
    }

    printf("print end ------\n");
}