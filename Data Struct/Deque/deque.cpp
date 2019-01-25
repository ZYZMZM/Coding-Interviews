#include"deque.h"
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


bool Push_front(QueueS queue,int val)
{
	assert(queue != NULL);
	if (IsFull(queue))
	{
		return false;
	}
	for (int i = queue->rear; i >= queue->front; i = (i-1) % SIZE)
	{
		queue->elem[i+1] = queue->elem[i];
	}
	queue->elem[queue->front] = val;
	queue->rear = (queue->rear+1) % SIZE;  // 不可以直接++  因为循环队列  最后一个元素的下一个下标可能是0号元素
	return true;
}

bool Push_back(QueueS queue,int val)
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

bool Pop_front(QueueS queue)
{
	assert(queue != NULL);
	if (IsEmpty(queue))
	{
		return false;
	}
	queue->front = (queue->front + 1) % SIZE;
	return true;
}

bool Pop_back(QueueS queue)
{
	assert(queue != NULL);
	if (IsEmpty(queue))
	{
		return false;
	}
	queue->rear = (queue->rear - 1) % SIZE;
	return true;
}

int Get_front(QueueS queue)
{
	assert(queue != NULL);
	if (IsEmpty(queue))
	{
		return -1;
	}
	int index = queue->front;
	return queue->elem[index];
}


int Get_back(QueueS queue)
{
	assert(queue != NULL);
	if (IsEmpty(queue))
	{
		return -1;
	}
	int index = (queue->rear - 1) % SIZE;
	return queue->elem[index];
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