// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <stdio.h>

int GetMissingNumber(const int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (left + right) >> 1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
			{
				return middle;
			}
			else
			{
				right = middle - 1;
			}
		}
		else
		{
			left = middle + 1;  
		}
	}
	if (left == length)
	{
		return length;
	}
	return -1;
}



// ====================测试代码====================


// 缺失的是第一个数字0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 0
}

// 缺失的是最后一个数字
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 5
}

// 缺失的是中间某个数字0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 3
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
    int numbers[] = { 1 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 0
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test5()
{
    int numbers[] = { 0 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 1
}

// 空数组
void Test6()
{
	int *numbers = NULL;
	int length = 0;
	printf("%d\n",GetMissingNumber(numbers,length));  // -1
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}