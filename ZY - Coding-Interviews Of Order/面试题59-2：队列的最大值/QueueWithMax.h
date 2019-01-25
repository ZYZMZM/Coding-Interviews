#pragma once

#define SIZE 90
typedef struct Queue
{
	int elem[SIZE];
	int front;
	int rear;
}Queue,*QueueS;

void InitQueueS(QueueS queue);

bool Push_front(QueueS queue,int val);

bool Push_back(QueueS queue,int val);

bool Pop_front(QueueS queue);

bool Pop_back(QueueS queue);

int Get_front(QueueS queue);

int Get_back(QueueS queue);

void Show(QueueS queue);

int GetLength(QueueS queue);

bool IsEmpty(QueueS queue);

void Clear(QueueS queue);

void Destroy(QueueS queue);