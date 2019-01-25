// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <stdio.h>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == NULL || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;

	for (int i = 0; i < nLength; i++)
	{
		if (nCurSum < 0)
		{
			nCurSum = pData[i];
		}
		else
		{
			nCurSum += pData[i];
		}
		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}
	return nGreatestSum;
}



// ====================测试代码====================

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   //  18
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   // -1
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   // 25
}

// 无效输入
void Test4()
{
	int *data = NULL;
    int length = 0;
	printf("%d\n",FindGreatestSumOfSubArray(data,length)); // null
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
