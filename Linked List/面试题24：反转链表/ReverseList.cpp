// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。


#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

BNode* ReverseList(BNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	BNode *pReversedHead = NULL;
	BNode *pNode = pHead;
	BNode *pPrev = NULL;
	while (pNode != NULL)
	{
		BNode *pNext = pNode->next;
		if (pNext == NULL)
		{
			pReversedHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}


// ====================测试代码====================
BNode* Test(BNode* pHead)
{
    printf("The original list is: \n");
	Show(pHead);

    BNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    Show(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Test(N);
}

// 输入的链表只有一个结点
void Test2()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Test(N);
}

// 输入空链表
void Test3()
{
    BTlist N;
	InitList(&N);
	Test(N);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
