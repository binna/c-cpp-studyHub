#ifndef __SINGLE_LINKED_LIST_H_
#define __SINGLE_LINKED_LIST_H_

typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
}Node;

typedef struct tagFCMNode1
{
	int Data;
	int Cnt;
	struct tagFCMNode1* NextNode;
}FCMNode1;

typedef struct tagFCMNode2
{
	int Data;
	int Cnt;
	struct tagFCMNode2* PrevNode;
	struct tagFCMNode2* NextNode;
}FCMNode2;

#endif