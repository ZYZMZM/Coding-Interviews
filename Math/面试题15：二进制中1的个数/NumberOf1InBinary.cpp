// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <stdio.h>

int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		flag <<=  1;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	while (n != 0)
	{
		++count;
		n = n & (n-1);
	}
	return count;
}


// ====================测试代码====================

int main(int argc, char* argv[])
{
    // 输入0，期待的输出是0
    printf("%d  %d\n",NumberOf1_Solution1(0),NumberOf1_Solution2(0));

    // 输入1，期待的输出是1
    printf("%d  %d\n",NumberOf1_Solution1(1),NumberOf1_Solution2(1));

    // 输入10，期待的输出是2
    printf("%d  %d\n",NumberOf1_Solution1(10),NumberOf1_Solution2(10));

    // 输入0x7FFFFFFF，期待的输出是31
    printf("%d  %d\n",NumberOf1_Solution1(0x7FFFFFFF),NumberOf1_Solution2(0x7FFFFFFF));

    // 输入0xFFFFFFFF（负数），期待的输出是32
    printf("%d  %d\n",NumberOf1_Solution1(0xFFFFFFFF),NumberOf1_Solution2(0xFFFFFFFF));

    // 输入0x80000000（负数），期待的输出是1
    printf("%d  %d\n",NumberOf1_Solution1(0x80000000),NumberOf1_Solution2(0x80000000));

    return 0;
}


