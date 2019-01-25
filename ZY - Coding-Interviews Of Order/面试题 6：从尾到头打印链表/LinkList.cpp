#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "LinkList.h"

void InitList(List plist)//初始化单链表
{
	assert(plist != NULL);
	plist->next = NULL;
}

static Node* GetNode(int val)
{
	Node *pGet = (Node *)malloc(sizeof(Node));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next =NULL;
	return pGet;
}

bool Insert_head(List plist,int val)//头插法
{
	assert(plist != NULL);
	Node *pGet = GetNode(val);
	pGet->next = plist->next;
	plist->next = pGet;
	return true;
}

bool Insert_tail(List plist,int val)//尾插法
{
	assert(plist != NULL);
	Node *p = plist;	
	while (p->next != NULL)
	{
		p = p->next;
	}
	Node *pGet = GetNode(val);
	p->next = pGet;
	return true;
}

bool Insert_pos(List plist,int pos,int val)//pos 位置插入
{
	assert(plist != NULL);
	if (pos < 0 || pos > GetLength(plist))
	{
		return false;
	}
	Node *p = plist;	
	for (int i = 0; i < pos-1; i++)
	{
		p = p->next;
	}
	Node *pGet = GetNode(val);
	pGet->next = p->next;
	p->next = pGet;
	return true;
}

bool IsEmpty(List plist)
{
	if (plist == NULL || plist->next == NULL)
	{
		return true;
	}
	return false;
}

Node *Search_pre(List plist,int key)//查找 key 的前驱
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		return NULL;
	}
	Node *p = plist;	
	while (p->next != NULL)
	{
		if (p->next->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool Delete(List plist,int key)  //删除 key 这个结点
{
	assert(plist != NULL);
	Node *p = Search_pre(plist,key);
	if (p == NULL)
	{
		return false;
	}
	Node *pDel = p->next;
	p->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return true;
}


void Destroy(List plist)//摧毁函数（如果有动态开辟内存）
{
	assert(plist != NULL);
	Node *pDel = NULL;
	while (plist->next != NULL)
	{
		pDel = plist->next;
		plist->next = pDel->next;
		free(pDel);
		pDel = NULL;
	}
}

int GetLength(List plist)//得到单链表的长度
{
	assert(plist != NULL);
	int len = 0;
	Node *p = plist->next;	
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void Show(List plist)//打印单链表
{
	assert(plist != NULL);
	Node *p = plist->next;	
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
