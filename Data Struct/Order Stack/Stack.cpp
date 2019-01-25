#include"Stack.h"
#include<stdio.h>
#include<assert.h>

void InitStack(Pstack ps)
{
	assert(ps != NULL);
	ps->top = 0;
}

bool IsFull(Pstack ps)
{
	return ps->top == STACK_LEN;
}


bool Push(Pstack ps,int val)
{
	assert(ps != NULL);
	if (IsFull(ps))
	{
		return false;
	}
	ps->elem[ps->top++] = val;
}

bool IsEmpty(Pstack ps)
{
	return ps->top == 0;
}

bool Pop(Pstack ps,int *rtv) //删除
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		return false;
	}
	if (rtv != NULL)
	{
		ps->top--;
		*rtv = ps->elem[ps->top];
	}	
	return true;
}


bool GetTop(Pstack ps,int *rtv)  //得到栈顶元素，但是不删除
{
	if (IsEmpty(ps))
	{
		return false;
	}
	if (rtv != NULL)
	{
		*rtv = ps->elem[ps->top-1];
	}
	return true;
}

void Clear(Pstack ps)   //top 指针的操作
{
	ps->top = 0;
}

void Show(Pstack ps)
{
	for (int i = 0; i < ps->top; i++)
	{
		printf("%d ",ps->elem[i]);
	}
	printf("\n");
}
