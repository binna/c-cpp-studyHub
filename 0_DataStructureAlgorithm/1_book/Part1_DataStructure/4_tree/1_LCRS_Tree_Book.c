#include "1_LCRS_Tree_Book.h"

LCRSNode* LCRS_CreateNode1(ElementType NewData)
{
    LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChile = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;
    return NewNode;
}

void LCRS_DestroyNode1(LCRSNode* Node)
{
    free(Node);
}

void LCRS_DestroyTree1(LCRSNode* Root)
{
    if (Root->RightSibling != NULL)
        LCRS_DestroyTree1(Root->RightSibling);

    if (Root->LeftChile != NULL)
        LCRS_DestroyTree1(Root->LeftChile);

    Root->LeftChile = NULL;
    Root->RightSibling = NULL;

    LCRS_DestroyNode1(Root);
}

void LCRS_AddChildNode1(LCRSNode* ParentNode, LCRSNode* ChildNode)
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

void LCRS_PrintTree1(LCRSNode* Node, int Depth)
{
    int i = 0;
    for (i = 0; i < Depth; i++)
    {
        printf(" ");
    }

    printf("%c\n", Node->Data);

    if (Node->LeftChile != NULL)
        LCRS_PrintTree1(Node->LeftChile, Depth + 1);

    if (Node->RightSibling != NULL)
        LCRS_PrintTree1(Node->RightSibling, Depth);
}