#include<stdio.h>
#include"BNode.h"
#include<stdlib.h>
//#include<vld.h>
#include<assert.h>

BNode *Intersection(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;
	BTlist p3 = Lc;
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			p2 = p2->next;
		}
		else
		{
			BNode *pGet = (BNode *)malloc(sizeof(BNode));
			pGet->data = p2->data;
			pGet->next = NULL;

			if (p3 == NULL)
			{
				Lc = pGet;  // 第一个交集元素节点存入Lc
				p3 = Lc;
			}
			else
			{
				while (p3->next != NULL)
				{
					p3 = p3->next;
				}
				p3->next = pGet;
			}

			//Insert_tail(&Lc,p2->data);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	return Lc;
}

BNode *Union(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			Insert_tail(&Lc,p1->data);
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			Insert_tail(&Lc,p2->data);
			p2 = p2->next;
		}
		else
		{
			Insert_tail(&Lc,p1->data);
			p2 = p2->next;
			p1 = p1->next;
		}
	}
	while (p1 != NULL)
	{
		Insert_tail(&Lc,p1->data);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		Insert_tail(&Lc,p2->data);
		p2 = p2->next;
	}
	return Lc;
}

BNode *Difference_Set(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;
	while(p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			Insert_tail(&Lc,p1->data);
			p1 = p1->next;
		}
		else if(p1->data > p2->data)
		{
			p2 = p2->next;
		}
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		Insert_tail(&Lc,p1->data);
		p1 = p1->next;
	}
	return Lc;
}

bool IsPresent(BTlist plist,int elem)
{
	BTlist p = plist;
	while(p != NULL)
	{
		if (p->data == elem)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

BNode *Intersection_1(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;
	
	while(p1 != NULL)
	{
		if (IsPresent(p2,p1->data))
		{
			Insert_tail(&Lc,p1->data);
		}
		p1 = p1->next;
	}
	return Lc;
}

BNode *Union_1(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;

	while(p1 != NULL)
	{
		Insert_tail(&Lc,p1->data);
		p1 = p1->next;
	}

	while(p2 != NULL)
	{
		if(!IsPresent(Lc,p2->data))
		{
			Insert_tail(&Lc,p2->data);
		}
		p2 = p2->next;
	}
	return Lc;
}

BNode *Difference_Set_1(BTlist plist1,BTlist plist2)
{
	BTlist Lc;
	Lc = NULL;  // 初始化无头单链表
	BTlist p1 = plist1;
	BTlist p2 = plist2;

	while(p1 != NULL)
	{
		if(!IsPresent(p2,p1->data))
		{
			Insert_tail(&Lc,p1->data);
		}
		p1 = p1->next;
	}
	return Lc;
}
int main()
{
	BTlist head;
	InitList(&head);
	BTlist head1;
	InitList(&head1);
	BTlist Lc;
	InitList(&Lc);
	/*Insert_tail(&head,1);
	Insert_tail(&head,2);
	Insert_tail(&head,3);
	Insert_tail(&head,7);
	Insert_tail(&head,9);
	Insert_tail(&head,11);*/

	Insert_tail(&head,10);
	Insert_tail(&head,15);
	Insert_tail(&head,4);
	Insert_tail(&head,20);
	Show(head);
	
	/*Insert_tail(&head1,3);
	Insert_tail(&head1,4);
	Insert_tail(&head1,5);
	Insert_tail(&head1,6);
	Insert_tail(&head1,7);
	Insert_tail(&head1,10);*/

	Insert_tail(&head1,8);
	Insert_tail(&head1,4);
	Insert_tail(&head1,2);
	Insert_tail(&head1,10);
	Show(head1);
	Lc = Difference_Set_1(head,head1);
	Show(Lc);

	/*Insert_tail(&head,900);
	Insert_pos(&head,0,20);
	Show(head);
	printf("%d\n",GetLength(head));

	BTlist p = Search(head,6);
	Show(p);
	BTlist p1 = Search_pri(head,6);
	Show(p1);
	Delete(&head,20);
	Show(head);
	printf("%d\n",GetLength(head));*/
	/*Destroy(head);
	Destroy(head1);*/
	return 0;
}

