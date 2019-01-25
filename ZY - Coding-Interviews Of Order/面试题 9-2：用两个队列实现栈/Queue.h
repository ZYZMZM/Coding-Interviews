#pragma once
#define SIZE 11
typedef struct Queue
{
	int elem[SIZE];
	int front;
	int rear;
}Queue,*QueueS;

void InitQueueS(QueueS queue);

bool EnterQueue(QueueS queue,int val);

bool LeaveQueue(QueueS queue,int *rtv);

void Show(QueueS queue);

int GetLength(QueueS queue);

bool IsEmpty(QueueS queue);

void Clear(QueueS queue);

void Destroy(QueueS queue);