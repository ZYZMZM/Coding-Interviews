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

bool IsEmpty(Pstack ps)
{
	return ps->top == 0;
}

bool Push(Pstack ps,Pstack ps1,int val)
{
	assert(ps != NULL);
	if (IsFull(ps) || IsFull(ps1))
	{
		return false;
	}
	if (IsEmpty(ps) && IsEmpty(ps1))
	{
		ps->elem[ps->top++] = val;
		ps1->elem[ps1->top++] = val;
	}
	else
	{
		ps->elem[ps->top++] = val;

		int min = 0;
		GetTop(ps1,&min);
		if (min < val)
		{
			ps1->elem[ps1->top++] = min;
		}
		else
		{
			ps1->elem[ps1->top++] = val;
		}
	}
	return true;
}


bool Pop(Pstack ps,Pstack ps1,int *rtv) //删除
{
	assert(ps != NULL);
	if (IsEmpty(ps) || IsEmpty(ps1))
	{
		return false;
	}
	if (rtv != NULL)
	{
		ps->top--;
		*rtv = ps->elem[ps->top];
		ps1->top--;
		
	}	
	return true;
}

int Min(Pstack ps)
{
	assert(ps != NULL);
	int min = 0;
	GetTop(ps,&min);
	return min;
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
