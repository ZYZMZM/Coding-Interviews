// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "LinkList.h"

//===========================方法一：非递归方法===================================
BNode* Merge_1(BNode* pHead1, BNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}
	BNode *p1 = pHead1;
	BNode *p2 = pHead2;
	BNode *pHead3 = NULL;
	if (p1->data <= p2->data)
	{
		pHead3 = pHead1;
		p1 = p1->next;
	}
	else
	{
		pHead3 = pHead2;
		p2 = p2->next;
	}

	BNode *ptemp = pHead3;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			ptemp->next = p1;
			p1 = p1->next;
		}
		else
		{
			ptemp->next = p2;
			p2 = p2->next;
		}
		ptemp = ptemp->next;
	}
	if (p1 != NULL)
	{
		ptemp->next = p1;
	}
	if (p2 != NULL)
	{
		ptemp->next = p2;
	}
	return pHead3;
}


//===========================方法二：递归方法===================================
BNode* Merge_2(BNode* pHead1, BNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}

	BNode *pMergeHead = NULL;
	if (pHead1->data < pHead2->data)
	{
		pMergeHead = pHead1;
		pMergeHead->next = Merge_2(pHead1->next,pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->next = Merge_2(pHead1,pHead2->next);
	}
	return pMergeHead;
}



// ====================测试代码====================
BNode* Test(char* testName, BNode* pHead1, BNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
	Show(pHead1);

    printf("The second list is:\n");
    Show(pHead2);

    printf("The merged list is:\n");
	BNode* pMergedHead = Merge_1(pHead1, pHead2);
	//BNode* pMergedHead = Merge_2(pHead1, pHead2);
    Show(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
	BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);
	Insert_tail(&N1,3);
	Insert_tail(&N1,5);

	BTlist N2;
	InitList(&N2);
	Insert_tail(&N2,2);
	Insert_tail(&N2,4);
	Insert_tail(&N2,6);

	BNode* pMergedHeadTest = Test("Test1",N1,N2);
	//Destroy(pMergedHeadTest);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
	BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);
	Insert_tail(&N1,3);
	Insert_tail(&N1,5);

	BTlist N2;
	InitList(&N2);
	Insert_tail(&N2,1);
	Insert_tail(&N2,3);
	Insert_tail(&N2,5);

	BNode* pMergedHeadTest = Test("Test2",N1,N2);
	//Destroy(pMergedHeadTest);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);

	BTlist N2;
	InitList(&N2);
	Insert_tail(&N2,2);

	BNode* pMergedHeadTest = Test("Test3",N1,N2);
	//Destroy(pMergedHeadTest);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
   BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);
	Insert_tail(&N1,3);
	Insert_tail(&N1,5);

	BTlist N2;
	InitList(&N2);

	BNode* pMergedHeadTest = Test("Test4",N1,N2);
	//Destroy(pMergedHeadTest);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
	BTlist N1;
	InitList(&N1);

	BTlist N2;
	InitList(&N2);

	BNode* pMergedHeadTest = Test("Test5",N1,N2);
	//Destroy(pMergedHeadTest);
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

