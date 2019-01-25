// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。


#include<stdio.h>
#include "stack.h"

int main()
{
	Sqstack st;
	InitStack(&st);
	Sqstack st1;
	InitStack(&st1);
	Push(&st,&st1,3);
	printf("min==%d\n",Min(&st1));
	
	Push(&st,&st1,4);
	printf("min==%d\n",Min(&st1));

	Push(&st,&st1,2);
	printf("min==%d\n",Min(&st1));

	Push(&st,&st1,1);
	printf("min==%d\n",Min(&st1));

	Show(&st);
	Show(&st1);
	
	int tmp = 0;
	Pop(&st,&st1,&tmp);
	printf("弹出%d\n",tmp);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));


	Pop(&st,&st1,&tmp);
	printf("弹出%d\n",tmp);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));
	
	Push(&st,&st1,0);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));

	return 0;
}
