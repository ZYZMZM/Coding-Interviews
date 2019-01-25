// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？
// 例如，链表 1->2->3->3->4->4->5
// 结点被删除之后，1->2->5


#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"
void DeleteDuplication(BNode** pHead)
{
	if (*pHead == NULL)
	{
		return;
	}

	BNode *pPreNode = NULL;
	BNode *pNode = *pHead;
	while (pNode != NULL)
	{
		BNode *pNext = pNode->next;
		bool needDel = false;
		if (pNext != NULL && pNext->data == pNode->data)
		{
			needDel = true;
		}

		if (!needDel)
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else
		{
			int data = pNode->data;
			BNode *pDel = pNode;
			while (pDel != NULL && pDel->data == data)
			{
				pNext = pDel->next;
				free(pDel);
				pDel = NULL;
				pDel = pNext;
			}
			if (pPreNode == NULL)
			{
				*pHead = pNext;
			}
			else
			{
				pPreNode->next = pNext;
			}
			pNode = pNext;
		}
	}
}

// ====================测试代码====================

// 某些结点是重复的
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 没有重复的结点
void Test2()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Insert_tail(&N,6);
	Insert_tail(&N,7);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 所有结点的值都相同
void Test4()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 所有结点都成对出现
void Test5()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,4);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
   	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Insert_tail(&N,5);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");

}

// 链表中只有两个不重复的结点
void Test7()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 结点中只有一个结点
void Test8()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 结点中只有两个重复的结点
void Test9()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// 空链表
void Test10()
{
    BTlist N;
	InitList(&N);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
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
    Test8();
    Test9();
    Test10();

    return 0;
}