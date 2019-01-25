#include<stdio.h>
#include"CricleList.h"

int main()
{
	CTlist head;
	InitList(&head);
	CTlist head1;
	InitList(&head1);
	CTlist Lc;
	InitList(&Lc);

	//Insert_head(&head,10);
	//Insert_head(&head,15);
	//Insert_head(&head,4);
	//Insert_head(&head,20);
	//CreateLoop(&head);

	//Insert_tail(&head,1);
	//Insert_tail(&head,2);
	//Insert_tail(&head,3);
	//Insert_tail(&head,89);
	////Insert_head(&head,1000);
	
	for (int i = 0; i < 5; i++)
	{
		Insert_tail(&head,i);
	}
	Show(&head);
	printf("len==%d\n",GetLength(&head));
	
	Delete(&head,2);
	Show(&head);
	printf("len==%d\n",GetLength(&head));
	
	Delete(&head,0);
	Show(&head);
	printf("len==%d\n",GetLength(&head));

	Delete(&head,4);
	Show(&head);
	printf("len==%d\n",GetLength(&head));

	Delete(&head,1);
	Show(&head);
	printf("len==%d\n",GetLength(&head));
	
}
