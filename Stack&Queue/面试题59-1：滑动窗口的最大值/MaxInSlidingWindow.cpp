// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <stdio.h>
#include "deque.h"

void maxInWindows(int *num, unsigned int length,unsigned int size)
{
	int maxInWindow = 0;
	if (length >= size && size >= 1)
	{
		Queue qu;
		InitQueueS(&qu);

		for (unsigned int i = 0; i < size; i++)
		{
			while (!IsEmpty(&qu) && num[i] >= num[Get_back(&qu)])   // 把当前元素小的队列元素全部剔除，然后把当前元素存入队尾
			{
				Pop_back(&qu);
			}
			Push_back(&qu,i);
		}

		for (unsigned int i = size; i < length; i++)
		{
			maxInWindow = num[Get_front(&qu)];  // 滑动窗口的最大值总是位于队列的头部
			printf("%d ",maxInWindow);

			while (!IsEmpty(&qu) && num[i] >= num[Get_back(&qu)])
			{
				Pop_back(&qu);
			}
			if (!IsEmpty(&qu) && Get_front(&qu) <= (int)(i - size))
			{
				Pop_front(&qu);
			}
			Push_back(&qu,i);
		}
		maxInWindow = num[Get_front(&qu)];
		printf("%d ",maxInWindow);
		printf("\n");
	}
	else
	{
		printf("NULL\n");
	}
}
// ====================测试代码====================

void Test1()
{
    int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,3);  // 4, 4, 6, 6, 6, 5
}

void Test2()
{
    int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,3);  // 3, 3, 5, 5, 6, 7
}

// 输入数组单调递增
void Test3()
{
    int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,4);  // 7, 9, 11, 13, 15
}

// 输入数组单调递减
void Test4()
{
    int num[] = { 16, 14, 12, 10, 8, 6, 4 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,5);  // 16, 14, 12
}

// 滑动窗口的大小为1
void Test5()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,1);  // 10, 14, 12, 11
}

// 滑动窗口的大小等于数组的长度
void Test6()
{
    int num[] = { 10, 14, 12, 11 };
   unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,4);  // 14
}

// 滑动窗口的大小为0
void Test7()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,0);  // NULL
}

// 滑动窗口的大小大于输入数组的长度
void Test8()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,5);  // NULL
}

// 输入数组为空
void Test9()
{
    int *num = NULL;
    unsigned int length = 0;
	maxInWindows(num,length,5);  // NULL
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}