// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。



#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include "Linklist.h"

BNode* FindKthToTail(BNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}

	BNode *pFast = pListHead;
	BNode *pSlow = pListHead;

	for (unsigned int i = 0; i < k-1; i++)
	{
		if (pFast->next != NULL)
		{
			pFast = pFast->next;
		}
		else
		{
			return NULL; // 即链表中的节点个数小于k个
		}
	}

	while (pFast->next != NULL)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}



// ====================测试代码====================
// 测试要找的结点在链表中间
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,2);
	printf("%d\n",result->data);   // 4
	Destroy(N);
}

// 测试要找的结点是链表的尾结点
void Test2()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,1);
	printf("%d\n",result->data);   //  5
	Destroy(N);
}

// 测试要找的结点是链表的头结点
void Test3()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,5);   //   1
	printf("%d\n",result->data);
	Destroy(N);
}

// 测试空链表
void Test4()
{
    BTlist N;
	InitList(&N);
	BNode *result = FindKthToTail(N,100);
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,6);  // NULL
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
	Destroy(N);
}

// 测试输入的第二个参数为0
void Test6()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,0);
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
	Destroy(N);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

