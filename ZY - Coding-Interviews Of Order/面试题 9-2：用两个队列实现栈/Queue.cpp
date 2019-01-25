#include"queue.h"
#include<stdio.h>
#include<assert.h>

void InitQueueS(QueueS queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
}

bool IsFull(QueueS queue)
{
	return (queue->rear + 1) % SIZE == queue->front;  
}


bool EnterQueue(QueueS queue,int val)
{
	assert(queue != NULL);
	if (IsFull(queue))
	{
		return false;
	}
	queue->elem[queue->rear] = val;
	queue->rear = (queue->rear+1) % SIZE;  // 不可以直接++  因为循环队列  最后一个元素的下一个下标可能是0号元素
	return true;
}



bool LeaveQueue(QueueS queue,int *rtv)
{
	assert(queue != NULL);
	if (IsEmpty(queue))
	{
		return false;
	}
	if (rtv != NULL)
	{
		*rtv = queue->elem[queue->front];
	}
	queue->front = (queue->front + 1) % SIZE;
	return true;
}


void Show(QueueS queue)
{
	int i = queue->front;
	while (i != queue->rear)
	{
		printf("%d ",queue->elem[i]);
		i = (i+1) % SIZE;
	}
	printf("\n");
}


int GetLength(QueueS queue)
{
	return (queue->rear - queue->front + SIZE) % SIZE;
}


bool IsEmpty(QueueS queue)
{
	assert(queue != NULL);
	return queue->front == queue->rear;
}

void Clear(QueueS queue)
{
	queue->front = queue->rear;
}
