
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int data;
    struct LinkedListNode* nextNode;
}Node;

void appendNode(Node** list, const int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("System Notice : Out of memory\n");
        return;
    }

    newNode->data = data;
    newNode->nextNode = NULL;

    if (*list == NULL)
    {
        *list = newNode;
        return;
    }

    Node* tailNode = *list;
    while (tailNode->nextNode != NULL) {
        tailNode = tailNode->nextNode;
    }
    tailNode->nextNode = newNode;
}

// 중간 삽입
void insertNode(Node** list, int location, int data)
{
    if (location < 0)
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

    newNode->data = data;
    newNode->nextNode = NULL;

    Node* prevNode = *list;
    Node* targetNode = *list;
    while (location-- > 0) {
        if (targetNode->nextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }

        prevNode = targetNode;
        targetNode = targetNode->nextNode;
    }

    if (prevNode == targetNode)
    {
        if (targetNode->nextNode == NULL)
        {
            *list = newNode;
            return;
        }
        newNode->nextNode = *list;
        *list = newNode;
        return;
    }

    prevNode->nextNode = newNode;
    newNode->nextNode = targetNode;
}

// 수정
void modifyNode(Node** list, int data, int location)
{
    if (*list == NULL)
    {
        printf("System Notice : No saved linked list\n");
        return;
    }

    if (location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return;
    }

    if (location == 0)
    {
        (*list)->data = data;
        return;
    }

    Node* targetNode = *list;
    while (location-- > 0) {
        if (targetNode->nextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }
        targetNode = targetNode->nextNode;
    }

    targetNode->data = data;
}

// 삭제
void deleteNode(Node** list, int location)
{
    if (*list == NULL)
    {
        printf("System Notice : No deleted linked list\n");
        return;
    }

    if (location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return;
    }

    Node* prevNode = *list;
    Node* targetNode = *list;
    while (location-- > 0) {
        if (targetNode->nextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return;
        }
        prevNode = targetNode;
        targetNode = targetNode->nextNode;
    }

    if (prevNode == targetNode)
    {
        if (targetNode->nextNode == NULL)
        {
            *list = NULL;
            return;
        }
        *list = targetNode->nextNode;
        free(targetNode);
        return;
    }

    prevNode->nextNode = targetNode->nextNode;
    free(targetNode);
}

// 검색
int select(Node* list, int location)
{
    if (list == NULL)
    {
        printf("System Notice : a linked list that does not exist\n");
        return -1;
    }

    if (location < 0)
    {
        printf("System Notice : Negative number is not allowed\n");
        return -1;
    }

    Node* targetNode = list;
    while (location-- > 0) {
        if (targetNode->nextNode == NULL)
        {
            printf("System Notice : Invalid index\n");
            return -1;
        }
        targetNode = targetNode->nextNode;
    }

    return targetNode->data;
}

int size(Node* list)
{
    if (list == NULL)
    {
        printf("System Notice : a linked list that does not exist\n");
        return -1;
    }

    int count = 0;
    Node* targetNode = list;
    while (1)
    {
        count += 1;

        targetNode = targetNode->nextNode;
        if (targetNode == NULL)
            break;
    }

    return count;
}

// 출력
void print(Node* list)
{
    printf("print start ----\n");
    if (list == NULL)
    {
        printf("System Notice : No saved linked list\n");
        return;
    }

    Node* targetNode = list;
    while (1)
    {
        printf(">> data : %d\n", targetNode->data);
        targetNode = targetNode->nextNode;

        if (targetNode == NULL)
            break;
    }
    printf("----------------\n");
}

int main(void) {

    Node* list = NULL;

    printf("size : %d\n", size(list));

    appendNode(&list, 0);
    appendNode(&list, 1);
    appendNode(&list, 3);
    appendNode(&list, 4);
    appendNode(&list, 5);
    appendNode(&list, 6);

    print(list);
    printf("size : %d\n", size(list));

    insertNode(&list, 0, 1000);
    insertNode(&list, 3, 3000);
    insertNode(&list, 7, 7000);

    print(list);
    printf("size : %d\n", size(list));

    insertNode(&list, 9, 8000);
    insertNode(&list, 10, 9000);

    print(list);
    printf("size : %d\n", size(list));

    deleteNode(&list, 9);
    deleteNode(&list, 5);
    deleteNode(&list, -1);

    print(list);
    printf("select : %d\n", select(list, -5));
    printf("select : %d\n", select(list, 0));
    printf("select : %d\n", select(list, 3));
    printf("select : %d\n", select(list, 5));
    printf("select : %d\n", select(list, 10));


    free(list);
    system("pause");

    return 0;
}