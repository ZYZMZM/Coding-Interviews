// 面试题59（二）：队列的最大值
// 题目：定义一个队列并实现函数max得到队列里的最大值,
// 要求函数max、push_back、pop_front的时间复杂度都是o(1)。
#include<stdio.h>
#include<assert.h>
#include "QueueWithMax.h"

void push_back(QueueS queue,QueueS maxElem,int val)
{
	while (!IsEmpty(maxElem) && val >= Get_back(maxElem))
	{
		Pop_back(maxElem);
	}
	Push_back(maxElem,val);
	Push_back(queue,val);
}

void pop_front(QueueS queue,QueueS maxElem)
{
	assert(queue != NULL && maxElem != NULL);
	if (IsEmpty(queue) || IsEmpty(maxElem))
	{
		return;
	}
	if (Get_front(maxElem) == Get_front(queue))
	{
		Pop_front(maxElem);
	}
	Pop_front(queue);
}

int max(QueueS maxElem)
{
	if (IsEmpty(maxElem))
	{
		return -1;
	}
	return Get_front(maxElem);
}


int main()
{
	Queue qu;
	InitQueueS(&qu);
	Queue ma;
	InitQueueS(&ma);
	for(int i = 0;i < 10;i++)
	{
		push_back(&qu,&ma,i);
	}
	Show(&qu); 
	printf("max == %d\n",max(&ma));


	push_back(&qu,&ma,2);
	push_back(&qu,&ma,600);
	push_back(&qu,&ma,5);
	Show(&qu); 
	printf("max == %d\n",max(&ma));


	pop_front(&qu,&ma);
	pop_front(&qu,&ma);
	pop_front(&qu,&ma);
	Show(&qu);
	printf("max == %d\n",max(&ma));

	pop_front(&qu,&ma);
	pop_front(&qu,&ma);
		pop_front(&qu,&ma);
	pop_front(&qu,&ma);
	Show(&qu);
	printf("max == %d\n",max(&ma));


	return 0;
}
