#include<stdio.h>
#include"LinkList.h"
#include<stdlib.h>
//#include<vld.h>
#include<assert.h>
/*
1、逆置单链表
2、反转单链表
3、合并两个有序的单链表
4、判断单链表是否有环？环的入口点？环的长度？
5、判断两个单链表是否相交？交点？
6、O(1)时间删除单链表的一个节点
7、最快时间内找到单链表倒数第K个节点？
8、最快时间内删除单链表倒数第K个节点？
*/



//1、逆置单链表
void Reverse(List plist)
{
	Node *p = plist->next;
	plist->next = NULL;
	while (p != NULL)
	{
		Node *pNext = p->next;
		p->next = plist->next;
		plist->next = p;
		p = pNext;
	}
}


//2、反转单链表
Node *Reverse_1(List plist)
{
	Node *ReverseHead = NULL;
	Node *prev = NULL;
	Node *cur = plist;
	while (cur != NULL)
	{
		Node *curNext =cur->next;
		if (curNext == NULL)
		{
			ReverseHead = cur;
		}
		cur->next = prev;
		prev = cur;
		cur = curNext;
	}
	return ReverseHead;
}

void Show_1(List plist)
{
	Node *p = plist;
	while (p->next != NULL)
	{
		printf("%d ",p->data);
		p = p->next; 
	}
	printf("\n");
}


//3、合并两个有序的单链表
Node Merge_list(List La,List Lb)
{
	Node Lc;
	InitList(&Lc);
	List p1 = La->next;
	List p2 = Lb->next;
	List p3 = &Lc;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	if (p1 != NULL)
	{
		p3->next = p1;
	}
	if (p2 != NULL)
	{
		p3->next = p2;
	}
	return Lc;
}



//4、判断单链表是否有环？环的入口点？环的长度？
void CreateLoop(List plist)
{
	Node *p = plist;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = plist->next->next->next;
}

Node * IsLoop(List plist)
{
	Node *pslow = plist->next;
	Node *pfast = pslow->next;
	while (pfast != NULL && pslow != NULL)
	{
		if (pfast == pslow)
		{
			return pfast;
		}
		pslow = pslow->next;
		pfast = pfast->next;
		if (pfast != NULL)
		{
			pfast = pfast->next;
		}
	}
	return NULL;
}

int LoopLen(List plist)
{
	Node *loop = IsLoop(plist);
	Node *p = loop;
	if (p == NULL)
	{
		return NULL;
	}
	int len = 1;
	while (p->next != loop)
	{
		len++;
		p = p->next;
	}
	return len;
}

Node *Loopstart(List plist)
{
	Node *p1 = plist;
	Node *p2 = plist;
	int len = LoopLen(plist);
	for (int i = 0; i < len; i++)
	{
		p1 = p1->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}



//5、判断两个单链表是否相交？交点？
void CreatCut(List plist1,List plist2)
{
	plist1->next->next = plist2->next->next->next;
}

bool IsCut(List plist1,List plist2)
{
	int len1 = GetLength(plist1);
	int len2 = GetLength(plist2);
	Node *p1 = plist1;
	Node *p2 = plist2;
	int pos = len1 - len2;
	if (pos < 0)
	{
		p1 = plist2;
		p2 = plist1;
		pos = len2 - len1;
	}
	for (int i = 0; i < pos; i++)
	{
		p1 = p1->next;
	}
	while (p1 != NULL && p2 != NULL && p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == p2 && p1 != NULL)
	{
		return true;
	}
	return false;
}

Node *FirstNode(List plist1,List plist2)
{
	int len1 = GetLength(plist1);
	int len2 = GetLength(plist2);
	Node *p1 = plist1;
	Node *p2 = plist2;
	int pos = len1 - len2;
	if (pos < 0)
	{
		p1 = plist2;
		p2 = plist1;
		pos = len2 - len1;
	}
	for (int i = 0; i < pos; i++)
	{
		p1 = p1->next;
	}
	while (p1 != NULL && p2 != NULL && p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	if (p1 == p2 && p1 != NULL)
	{
		return p1;
	}
	return NULL;
}




//6、O(1)时间删除单链表的一个节点
void DeleteNode(List plist,List pDel)
{
	if (pDel->next != NULL)
	{
		Node *pDelNext = pDel->next;
		pDel->next = pDelNext->next;
		pDel->data = pDelNext->data;
		free(pDelNext);
		pDelNext = NULL;
	}
	else
	{
		Node *p = plist;
		while (p->next != pDel)
		{
			p = p->next;
		}
		p->next = NULL;
	}
}

//7、最快时间内找到单链表倒数第K个节点？
Node *Lask_K(List plist,int k)
{
	Node *p1 = plist;
	Node *p2 = plist;
	for (int i = 0; i < k-1; i++)
	{
		if (p1->next != NULL)
		{
			p1 = p1->next;
		}
		else
		{
			return NULL;
		}
	}
	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

//8、最快时间内删除单链表倒数第K个节点？
void DelLask_K(List plist,int k)
{
	Node *p1 = plist;
	Node *p2 = plist;
	for (int i = 0; i < k; i++)
	{
		if (p1->next != NULL)
		{
			p1 = p1->next;
		}
		else
		{
			return;
		}
	}
	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	Node *pDel = p2->next;
	p2->next = pDel->next;
	free(pDel);
	pDel = NULL;
}






int main()
{
	Node head;//头结点
	InitList(&head);
	Node head1;//头结点
	InitList(&head1);
	for(int i = 0; i < 10;i++)
	{
		Insert_tail(&head,i);
	}
	Insert_tail(&head,100);
	Show(&head);
	CreateLoop(&head);
	if (IsLoop(&head))
	{
		printf("ok");
	}
	else
	{
		printf("wrong");
	}
	//Show(&head);

	//for(int i = 5; i < 15;i++)
	//{
	//	Insert_tail(&head1,i);
	//}
	//Show(&head1);

	//CreatCut(&head,&head1);
	//if(IsCut(&head,&head1)) {printf("is cut\n");}
	//else{printf("isn't cut\n");}
	//Node *p = FirstNode(&head,&head1);
	//printf("%d\n",p->data);

	/*DeleteNode(&head,head.next->next->next);
	Show(&head);*/	
	/*Node *p =Lask_K(&head,3);
	printf("%d\n",p->data);
	DelLask_K(&head,3);
	Show(&head);*/

	//Show(&head);
	

	//Destroy(&head);
	/*Show(&head);
	Node *p = LastK(&head,3);
	printf("%d\n",p->data);
	DeleteLastK(&head,-1);
	Show(&head);*/
	/*Reverse2(&head);
	Show(&head);*/
	//Show2(Reverse1(&head));
	/*Insert_pos(&head,3,99);
	Show(&head);
	Delete(&head,5);
	Show(&head);
	int len = GetLength(&head);
	printf("len == %d\n",len);
	Destroy(&head);*/
	return 0;
}