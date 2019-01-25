#include <stdio.h>
#include "Stack.h"

void EnterQue(Pstack s1,int val)
{
	if (s1 == NULL)
	{
		return;
	}
	Push(s1,val);			// 入队
}

int LeaveQueue(Pstack s1,Pstack s2)
{
	int leave = 0;
	int arr[100];
	
	if (s1->top == 0 && s2->top == 0)
	{
		printf("EMPTY QUEUE\n");
	}
	else
	{
		if (s1->top != 0 && s2->top == 0)
		{
			int i = 0;
			while (s1->top != 0)
			{
				Pop(s1,&arr[i]);
				Push(s2,arr[i]);
			}
		}
		Pop(s2,&leave);
		return leave;
	}
}


// ====================测试代码====================

int main()
{
	Sqstack s1;
	InitStack(&s1);
	Sqstack s2;
	InitStack(&s2);

	for (int i = 0; i < 5; i++)
	{
		EnterQue(&s1,i);
	}
	int leave = LeaveQueue(&s1,&s2);
	printf("%d出队\n",leave);		// 0

	leave = LeaveQueue(&s1,&s2);
	printf("%d出队\n",leave);		// 1
	
	leave = LeaveQueue(&s1,&s2);	// 2
	printf("%d出队\n",leave);

	leave = LeaveQueue(&s1,&s2);	// 3
	printf("%d出队\n",leave);

	for (int i = 5; i < 7; i++)
	{
		EnterQue(&s1,i);
	}

	leave = LeaveQueue(&s1,&s2);
	printf("%d出队\n",leave);		// 4
	
	leave = LeaveQueue(&s1,&s2);	// 5
	printf("%d出队\n",leave);

	leave = LeaveQueue(&s1,&s2);	// 6
	printf("%d出队\n",leave);

	leave = LeaveQueue(&s1,&s2);	// EMPTY QUEUE
}


