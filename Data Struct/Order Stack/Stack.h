#pragma once

#define STACK_LEN 20

typedef struct Sqstack
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;

void InitStack(Pstack ps);

bool IsFull(Pstack ps);

bool Push(Pstack ps,int val);

bool IsEmpty(Pstack ps);

bool Pop(Pstack ps,int *rtv);//删除

bool GetTop(Pstack ps,int *rtv);//得到栈顶元素，但是不删除

void Clear(Pstack ps);//top 指针的操作

void Destroy(Pstack ps);//这里没有动态内存分配

void Show(Pstack ps);