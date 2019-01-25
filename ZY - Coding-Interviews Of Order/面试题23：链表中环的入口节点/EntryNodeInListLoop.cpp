// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

BNode* MeetingNode(BNode* pHead)
{
	if (pHead == NULL)
	{
		return false;
	}
	BNode * pSlow = pHead;
	if (pSlow == NULL)
	{
		return false;
	}
	BNode *pFast = pSlow->next;
	while (pSlow != NULL && pFast != NULL)
	{
		if (pSlow == pFast)
		{
			return pFast;
		}
		pSlow = pSlow->next;

		pFast = pFast->next;
		if (pFast != NULL)
		{
			pFast = pFast->next;
		}
	}
	return NULL;
}

BNode* EntryNodeOfLoop(BNode* pHead)
{
	BNode *MeetNode = MeetingNode(pHead);
	if (MeetNode == NULL)
	{
		return NULL;
	}

	int NodesInLoop = 1;
	BNode *pNode1 = MeetNode;
	while (pNode1 ->next != MeetNode)
	{
		NodesInLoop++;
		pNode1 = pNode1->next;
	}

	pNode1 = pHead;
	for (int i = 0; i < NodesInLoop; i++)
	{
		pNode1 = pNode1->next;
	}
	BNode *pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}


// ==================== Test Code ====================

// A list has a node, without a loop
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
    //Destroy(N);
}

// A list has a node, with a loop
void Test2()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	N->next = N;
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
    //Destroy(N);
}

// A list has multiple nodes, with a loop 
void Test3()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *p = N;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = N->next->next;
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
   // Destroy(N);
}

// A list has multiple nodes, with a loop 
void Test4()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *p = N;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = N;
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
   // Destroy(N);
}

// A list has multiple nodes, with a loop 
void Test5()
{
     BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *p = N;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = p;
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
   // Destroy(N);
}

// A list has multiple nodes, without a loop 
void Test6()
{
     BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
    //Destroy(N);
}

// Empty list
void Test7()
{
    BTlist N;
	InitList(&N);
	BNode* pNode = EntryNodeOfLoop(N);
	if (pNode == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",pNode->data);
	}
   // Destroy(N);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
