#include<stdio.h>
#include "Queue.h"

void EnterStack(Queue *qu1,Queue *qu2,int val)
{
	int len1 = GetLength(qu1);
	if (len1 != 0)
	{
		EnterQueue(qu1,val);
	}
	else
	{
		EnterQueue(qu2,val);
	}
}

int LeaveStack(Queue *qu1,Queue *qu2)
{
	int len1 = GetLength(qu1);
	int len2 = GetLength(qu2);
	int arr[100];

	if (len1 != 0 && len2 == 0)
	{
		int i = 0;
		for (; i < len1 - 1; i++)
		{
			LeaveQueue(qu1,&arr[i]);
			EnterQueue(qu2,arr[i]);
		}
		LeaveQueue(qu1,&arr[i]);
		return arr[i];
	}
	else if (len1 == 0 && len2 != 0)
	{
		int i = 0;
		for (; i < len2 - 1; i++)
		{
			LeaveQueue(qu2,&arr[i]);
			EnterQueue(qu1,arr[i]);
		}
		LeaveQueue(qu2,&arr[i]);
		return arr[i];
	}
	else
	{
		printf("EMPTY STACK");
	}
}

// ====================测试代码====================

int main()
{
	Queue qu1;
	InitQueueS(&qu1);
	Queue qu2;
	InitQueueS(&qu2);

	for (int i = 0; i < 5; i++)
	{
		EnterStack(&qu1,&qu2,i);  // 0 - 4 入栈
	}

	int leave = LeaveStack(&qu1,&qu2);  
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);


	for (int i = 5; i < 10; i++)
	{
		EnterStack(&qu1,&qu2,i);  // 5 - 9 入栈
	}

	leave = LeaveStack(&qu1,&qu2);  
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);  
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);  
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);

	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);
	
	leave = LeaveStack(&qu1,&qu2);
	printf("%d出栈\n",leave);
}