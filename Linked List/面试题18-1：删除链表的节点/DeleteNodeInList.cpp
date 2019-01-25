// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "LinkList.h"
void DeleteNode(BNode** pListHead, BNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return;
	}

	// 要删除的节点不是尾节点
	if (pToBeDeleted->next != NULL)
	{
		BNode *pNext = pToBeDeleted->next;
		pToBeDeleted->data = pNext->data;
		pToBeDeleted->next = pNext->next;

		free(pNext);
		pNext = NULL;
	}

	// 链表只有一个节点，删除头节点（也是尾节点）
	else if (*pListHead == pToBeDeleted)
	{
		free(pToBeDeleted);
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	
	// 链表中有多个节点，删除尾节点
	else
	{
		BNode *pNode = *pListHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		free(pToBeDeleted);
		pToBeDeleted = NULL;
	}
}

// ====================测试代码====================

// 链表中有多个结点，删除中间的结点
void Test1()
{
	BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1->next->next);
	Show(N1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1->next->next->next);
	Show(N1);
}


// 链表中有多个结点，删除头结点
void Test3()
{
    BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

// 链表为空
void Test5()
{
    BTlist N1;
	InitList(&N1);
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

