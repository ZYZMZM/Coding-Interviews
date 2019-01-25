// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

#include <stdio.h>
#include <math.h>
#include "LinkList.h"


BNode* FindFirstCommonNode(BNode *pHead1, BNode *pHead2)
{
	int length1 = GetLength(pHead1);
	int length2 = GetLength(pHead2);
	int length = length1 - length2;

	BNode *pLong = pHead1;
	BNode *pShort = pHead2;

	if (length1 < length2)
	{
		pLong = pHead2;
		pShort = pHead1;
		length = length2 - length1;
	}

	for (int i = 0; i < length; i++)
	{
		pLong = pLong->next;
	}

	while (pLong != NULL && pShort != NULL && pLong != pShort)
	{
		pLong = pLong->next;
		pShort = pShort->next;
	}

	BNode *pFirstCommonNode = pLong;
	return pFirstCommonNode;
}



// ====================测试代码====================

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
	BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,6);
	Insert_tail(&N1,7);

	Insert_tail(&N2,4);
	Insert_tail(&N2,5);

	N2->next->next = N1->next->next->next;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// 没有公共结点
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	
	Insert_tail(&N2,5);
	Insert_tail(&N2,6);
	Insert_tail(&N2,7);

	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	Insert_tail(&N1,7);

	Insert_tail(&N2,5);
	Insert_tail(&N2,6);

	N2->next->next = N1->next->next->next->next;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合   
void Test4()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	Insert_tail(&N1,5);

	N2 = N1;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// 输入的两个链表有一个空链表
void Test5()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);

	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// 输入的两个链表都是空链表
void Test6()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
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