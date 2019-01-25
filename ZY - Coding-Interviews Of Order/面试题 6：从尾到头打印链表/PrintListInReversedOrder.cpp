// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include<stdio.h>
#include<assert.h>
#include "LinkList.h"

void PrintListReversingly_Recursively(Node* pHead)
{
	if (pHead->next != NULL)
	{
		PrintListReversingly_Recursively(pHead->next);
		printf("%d ",pHead->next->data);	// 	pHead->next == NULL 会返回 上层函数 输出 pHead->next->data 最后一个节点数据
	}
}


// ====================测试代码====================


// 1->2->3->4->5
void Test1()
{
	Node list;
	InitList(&list);
	Insert_tail(&list,1);
	Insert_tail(&list,2);
	Insert_tail(&list,3);
	Insert_tail(&list,4);
	Insert_tail(&list,5);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

// 只有一个结点的链表: 1
void Test2()
{
    Node list;
	InitList(&list);
	Insert_tail(&list,1);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

// 空链表
void Test3()
{
    Node list;
	InitList(&list);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}



