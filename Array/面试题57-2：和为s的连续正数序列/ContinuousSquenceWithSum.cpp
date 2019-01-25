// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <stdio.h>

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
	//if (sum < 3)   // sum < 3 没有连续正数序列
	//{
	//	return;
	//}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) >> 1;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small,big);
		}
		
		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small,big);
			}
		}
		big++;
		curSum += big;
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
}


// ====================测试代码====================
void Test(int sum)
{
	printf("sum==%d\nBegin:\n",sum);
    FindContinuousSequence(sum);
	printf("END\n\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(3);
    Test(4);
    Test(9);
    Test(15);
    Test(100);

    return 0;
}
