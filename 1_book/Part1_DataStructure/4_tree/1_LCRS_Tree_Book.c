#include "1_LCRS_Tree_Book.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChile = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;
    return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
    free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
    if (Root->RightSibling != NULL)
        LCRS_DestroyTree(Root->RightSibling);

    if (Root->LeftChile != NULL)
        LCRS_DestroyTree(Root->LeftChile);

    Root->LeftChile = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode)
{
    if (ParentNode->LeftChile == NULL)
        ParentNode->LeftChile = ChildNode;
    else
    {
        LCRSNode* TempNode = ParentNode->LeftChile;
        while (TempNode->RightSibling != NULL)
        {
            TempNode = TempNode->RightSibling;
        }
        TempNode->RightSibling = ChildNode;
    }
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
    int i = 0;
    for (i = 0; i < Depth; i++)
    {
        printf(" ");
    }

    printf("%c\n", Node->Data);

    if (Node->LeftChile != NULL)
        LCRS_PrintTree(Node->LeftChile, Depth + 1);

    if (Node->RightSibling != NULL)
        LCRS_PrintTree(Node->RightSibling, Depth);
}