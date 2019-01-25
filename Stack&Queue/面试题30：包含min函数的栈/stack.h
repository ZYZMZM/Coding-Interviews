#pragma once

#define STACK_LEN 20

typedef struct Sqstack
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;

void InitStack(Pstack ps);

bool IsFull(Pstack ps);

bool Push(Pstack ps,Pstack ps1,int val);

bool IsEmpty(Pstack ps);

bool Pop(Pstack ps,Pstack ps1,int *rtv);//删除

int Min(Pstack ps);

bool GetTop(Pstack ps,int *rtv);//得到栈顶元素，但是不删除

void Clear(Pstack ps);//top 指针的操作

void Show(Pstack ps);