// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。

#include <stdio.h>

int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (right + left) >> 1;
		if (numbers[middle] == middle)
		{
			return middle;
		}
		if (numbers[middle] > middle)   // 若middle值 大于 其 下标，则右边所有元素都是值大于下标
		{
			right = middle - 1;  // 在middle左边找
		}
		else
		{
			left = middle + 1;  // 右边找
		}
	}
	return -1;
}



// ====================测试代码====================

void Test1()
{
    int numbers[] = { -3, -1, 1, 3, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 3
}

void Test2()
{
    int numbers[] = { 0, 1, 3, 5, 6 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 0
}

void Test3()
{
    int numbers[] = { -1, 0, 1, 2, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 4
}

void Test4()
{
    int numbers[] = { -1, 0, 1, 2, 5 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
}

void Test5()
{
    int numbers[] = { 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 0
}

void Test6()
{
    int numbers[] = { 10 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
}

void Test7()
{
	int *numbers = NULL;
    int length = -1;
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
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
}