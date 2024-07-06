// #include "LinkedListMy.h"
//
// int main(void)
// {
//     Node* list = NULL;
//
//     printf("size : %d\n", Size(list));
//
//      AppendNode(&list, 0);
//      AppendNode(&list, 1);
//      AppendNode(&list, 3);
//      AppendNode(&list, 4);
//      AppendNode(&list, 5);
//      AppendNode(&list, 6);
//
//      Print(list);
//      printf("size : %d\n", Size(list));
//
//      InsertNode(&list, 0, 1000);
//      InsertNode(&list, 3, 3000);
//      InsertNode(&list, 7, 7000);
//
//      Print(list);
//      printf("size : %d\n", Size(list));
//
//      InsertNode(&list, 9, 8000);
//      InsertNode(&list, 10, 9000);
//
//      Print(list);
//      printf("size : %d\n", Size(list));
//
//      DeleteNode(&list, 9);
//      DeleteNode(&list, 5);
//      DeleteNode(&list, -1);
//
//      Print(list);
//      printf("select : %d\n", Select(list, -5));
//      printf("select : %d\n", Select(list, 0));
//      printf("select : %d\n", Select(list, 3));
//      printf("select : %d\n", Select(list, 5));
//      printf("select : %d\n", Select(list, 10));
//
//
//     free(list);
//     return 0;
// }

// #include "1_LinkedListBook.h"
//
// int main(void)
// {
//     int count = 0;
//
//     Node* List = NULL;
//     Node* Current = NULL;
//     Node* NewNode = NULL;
//
//     // 노드 5개 추가
//     for (int i  = 0; i < 5; i++)
//     {
//         NewNode = SLL_CreateNode(i);
//         SLL_AppendNode(&List, NewNode);
//     }
//
//     NewNode = SLL_CreateNode(-1);
//     SLL_InsertNewHead(&List, NewNode);
//
//     NewNode = SLL_CreateNode(-2);
//     SLL_InsertNewHead(&List, NewNode);
//
//     // 리스트 출력
//     count = SLL_GetNodeCount(List);
//     for (int i = 0; i < count; i++)
//     {
//         Current = SLL_GetNodeAt(List, i);
//         printf("List[%d] : %d\n", i, Current->Data);
//     }
//
//     // 리스트의 세 번째 노드 뒤에 새 노드 삽입
//     printf("\nInserting 3000 After [2]...\n\n");
//
//     Current = SLL_GetNodeAt(List, 2);
//     NewNode = SLL_CreateNode(3000);
//
//     SLL_InsertAfter(Current, NewNode);
//
//     // 리스트 출력
//     count = SLL_GetNodeCount(List);
//     for (int i = 0; i < count; i++)
//     {
//         Current = SLL_GetNodeAt(List, i);
//         printf("List[%d] : %d\n", i, Current->Data);
//     }
//
//
//     // 모든 노드를 메모리에서 제거
//     printf("\nDestroying List... : %d\n", SLL_GetNodeCount(List));
//
//     count = SLL_GetNodeCount(List);
//     for (int i = 0; i < count; i++)
//     {
//         printf("%d : ", i);
//         Current = SLL_GetNodeAt(List, 0);
//
//         if (Current != NULL)
//         {
//             printf("List[%d] : %d\n", i, Current->Data);
//             SLL_RemoveNode(&List, Current);
//             SLL_DestroyNode(Current);
//         }
//     }
//
//     printf(">>>>> END\n");
//
//     // 리스트 출력
//     count = SLL_GetNodeCount(List);
//     for (int i = 0; i < count; i++)
//     {
//         Current = SLL_GetNodeAt(List, i);
//         printf("List[%d] : %d\n", i, Current->Data);
//     }
//
//     return 0;
// }

// 위의 책의 코드에서 아쉬운 점
// 1. 메인에서 노드를 생성하는 부분
// 2. 위치에 따른 Insert, Modify, Delete가 없음
//    ㄴ Insert 같은 경우는 주소를 보내줘야 중간 삽입되는데 그부분이 아쉬움
// 3. 예외처리의 부재

// 내 코드에서 개선할 점
// 1. 무한루프 제거
// 2. 노드 생성 부분은 함수로 빼기
#include "2_LinkedList_Final.h"

int main(void)
{
    Node* List = NULL;

    printf("size : %d\n", SLL_GetNodeSize2(List));

    SLL_AppendNode2(&List, 0);
    SLL_AppendNode2(&List, 1);
    SLL_AppendNode2(&List, 2);
    SLL_AppendNode2(&List, 3);
    SLL_AppendNode2(&List, 4);
    SLL_AppendNode2(&List, 5);

    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    SLL_InsertNode2(&List, 0, 1000);
    SLL_InsertNode2(&List, 3, 3000);
    SLL_InsertNode2(&List, 7, 7000);

    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    SLL_InsertNode2(&List, 9, 8000);
    SLL_InsertNode2(&List, 10, 9000);

    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    SLL_RemoveNode2ByLocation(&List, 9);
    SLL_RemoveNode2ByLocation(&List, 5);
    SLL_RemoveNode2ByLocation(&List, -1);

    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    Node* FoundNode = SLL_GetNode2(List, -5);
    if (FoundNode != NULL)
    {
        printf("select -5 : %d\n", FoundNode->Data);
    }

    FoundNode = SLL_GetNode2(List, 0);
    if (FoundNode != NULL)
    {
        printf("select 0 : %d\n", FoundNode->Data);
    }

    FoundNode = SLL_GetNode2(List, 3);
    if (FoundNode != NULL)
    {
        printf("select 3 : %d\n", FoundNode->Data);
    }

    FoundNode = SLL_GetNode2(List, 5);
    if (FoundNode != NULL)
    {
        printf("select 5 : %d\n", FoundNode->Data);
    }

    FoundNode = SLL_GetNode2(List, 10);
    if (FoundNode != NULL)
    {
        printf("select 10 : %d\n", FoundNode->Data);
    }

    printf("\n\n");
    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    FoundNode = SLL_GetNode2(List, 3);
    SLL_RemoveNode2ByNode(&List, FoundNode);

    Print2(List);
    printf("size : %d\n\n\n", SLL_GetNodeSize2(List));

    free(List);
    return 0;
}