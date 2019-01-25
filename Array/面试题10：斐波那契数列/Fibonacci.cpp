// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


#include<stdio.h>
// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return Fibonacci_Solution1(n-1)  +  Fibonacci_Solution1(n-2);
}

// ====================方法2：循环====================
long long Fibonacci_Solution2(unsigned n)
{
	int result[2] = {0,1};
	if (n < 2)
	{
		return result[n];
	}

	long long firstnum = result[0];
	long long secondnum = result[1];
	long long thirdnum = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		thirdnum = firstnum + secondnum;
		firstnum = secondnum;
		secondnum = thirdnum;
	}
	return thirdnum;
}


// ====================测试代码====================

int main(int argc, char* argv[])
{
	printf("%d\n",Fibonacci_Solution1(0));
	printf("%d\n",Fibonacci_Solution1(1));
	printf("%d\n",Fibonacci_Solution1(3));
	printf("%d\n",Fibonacci_Solution1(5));
	printf("%d\n",Fibonacci_Solution1(10));

	printf("%d\n",Fibonacci_Solution2(0));
	printf("%d\n",Fibonacci_Solution2(1));
	printf("%d\n",Fibonacci_Solution2(3));
	printf("%d\n",Fibonacci_Solution2(5));
	printf("%d\n",Fibonacci_Solution2(10));

	/*printf("%d\n",Fibonacci_Solution1(40));
	printf("%d\n",Fibonacci_Solution1(50));
	printf("%d\n",Fibonacci_Solution1(100));*/

	printf("%d\n",Fibonacci_Solution2(40));
	printf("%d\n",Fibonacci_Solution2(50));
	printf("%d\n",Fibonacci_Solution2(100));
	
    return 0;
}