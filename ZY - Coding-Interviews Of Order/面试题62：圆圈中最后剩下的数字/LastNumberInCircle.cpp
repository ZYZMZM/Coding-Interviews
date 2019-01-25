// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

//===================约瑟夫环问题===========================================
#if 0
int LastRemaining_Solution1(unsigned int n, unsigned int m, unsigned int k)
{
	if (n == 0 || m == 0)
	{
		return -1;
	}
	CTlist numbers;
	InitList(&numbers);
	for (unsigned int i = 1; i <= n; i++)
	{
		Insert_tail(&numbers,i);
	}

	int result = 0;
	for (int i = 1; i < k; i++)
	{
		numbers = numbers->next;
	}
	while (GetLength(&numbers) > 1)
	{
		for (unsigned int i = 1; i < m; i++)
		{
			numbers = numbers->next;
		}
		result = numbers->next->data;   // 保存 删除结点的下一个元素，因为它可能是 剩余的最后一个节点
		printf("%d ",numbers->data);
		Delete(&numbers,numbers->data);  // 删除m位置的元素
	}
	return result;
}
int main()
{
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,4,2));  // 2
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,4,1)); // 1
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,1,4)); // 3
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,1,1)); // 9
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(41,3,1)); // 9
}

#endif

#include <stdio.h>
#include "CricleList.h"

// ====================方法1：使用环形链表模拟====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	CTlist numbers;
	InitList(&numbers);
	for (unsigned int i = 0; i < n; i++)
	{
		Insert_tail(&numbers,i);
	}

	int result = 0;
	while (GetLength(&numbers) > 1)
	{
		for (unsigned int i = 1; i < m; i++)
		{
			numbers = numbers->next;
		}
		result = numbers->next->data;   // 保存 删除结点的下一个元素，因为它可能是 剩余的最后一个节点
		Delete(&numbers,numbers->data);  // 删除m位置的元素
	}
	return result;
}


// ====================方法2====================
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int DelElem = 0;
	for (int i = 2; i <= n; i++)
	{
		DelElem = (DelElem + m) %  i;
		//printf("%d ",DelElem);
	}
	return DelElem;
}

// ====================测试用例===============================
void Test(unsigned int m,unsigned int n)
{
	printf("Solution1:%d\n",LastRemaining_Solution1(m,n));
	printf("Solution2:%d\n\n",LastRemaining_Solution2(m,n));
}

int main()
{
	Test(5,3); // 3
	Test(5,2); // 2
	Test(6,7); // 4
	Test(6,6); // 3
	Test(0,0); // -1
	Test(4000,997); // 1027
}

