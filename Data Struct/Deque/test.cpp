#include"deque.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	Queue qu;
	InitQueueS(&qu);
	for(int i = 0;i < 10;i++)
	{
		Push_back(&qu,i);    //0-7
	}
	Show(&qu);   //0-7
	printf("%d\n",Get_back(&qu));
	printf("len == %d\n\n",GetLength(&qu));
	
	Push_front(&qu,100);
	Push_front(&qu,200);
	Push_front(&qu,300);
	
	Show(&qu);   //0-7
	printf("%d\n",Get_back(&qu));
	printf("len == %d\n\n",GetLength(&qu));

	Push_back(&qu,400);
	Push_back(&qu,500);
	Push_back(&qu,600);
	Show(&qu);   //0-7
	printf("%d\n",Get_back(&qu));
	printf("len == %d\n\n",GetLength(&qu));

	int tmp = 0;
	Pop_front(&qu);
	Pop_front(&qu);
	Pop_front(&qu);
	Show(&qu);   //0-7
	printf("%d\n",Get_back(&qu));
	printf("len == %d\n\n",GetLength(&qu));

	Pop_back(&qu);
	Pop_back(&qu);
	Show(&qu);//3-7
	printf("%d\n",Get_back(&qu));
	printf("len == %d\n\n",GetLength(&qu));


	return 0;
}