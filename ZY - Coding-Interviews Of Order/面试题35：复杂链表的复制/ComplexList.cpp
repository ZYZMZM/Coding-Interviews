// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ComplexList.h"

ComplexListNode* CreateNode(int data)
{
	ComplexListNode *pNode = (ComplexListNode *)malloc(sizeof(ComplexListNode));
	assert(pNode != NULL);
	pNode->data = data;
	pNode->next = NULL;
	pNode->slbing = NULL;
	return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
	if (pNode != NULL)
	{
		pNode->next = pNext;
		pNode->slbing = pSibling;
	}
}


void PrintList(ComplexListNode* pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL)
	{
		printf("data==%d\n",pNode->data);
		if (pNode->slbing != NULL)
		{
			printf("sibing==%d\n",pNode->slbing->data);
		}
		else
		{
			printf("no sibing\n");
		}
		pNode = pNode->next;
	}
}
