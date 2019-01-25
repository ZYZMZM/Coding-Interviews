// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。


/*
		思路：
		归并排序的合并过程。主要是考虑合并两个有序序列时，计算逆序对数。
		对于两个升序序列，设置两个下标：两个有序序列的末尾。每次比较两个末尾值，如果前末尾大于后末尾值，则有”后序列当前长度“个逆序对；
		否则不构成逆序对。然后把较大值拷贝到辅助数组的末尾，即最终要将两个有序序列合并到辅助数组并有序。
		这样，每次在合并前，先递归地处理左半段、右半段，则左、右半段有序，且左右半段的逆序对数可得到，再计算左右半段合并时逆序对的个数。
		总个数=左个数+右个数+左右合并时的个数
		注意：
		注意InversePairsCore形参的顺序是(data,copy)，而递归调用时实参是(copy,data)。
		要明白递归函数InversePairsCore的作用就行了，它是对data的左右半段进行合并，复制到辅助数组copy中有序。
		最后，data和copy两个数组都是有序的。
*/
#include <stdio.h>
#include <stdlib.h>

int InversePairsCore(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length)
{
	if (data == NULL || length < 0)
	{
		return 0;
	}
	int *copy = (int *)malloc(sizeof(int) * length);
	
	for (int i = 0; i < length; i++)
	{
		copy[i] = data[i];
	}
	int count = InversePairsCore(data,copy,0,length - 1);
	free(copy);
	return count;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) >> 1;

	int left = InversePairsCore(copy,data,start,start + length);
	int right = InversePairsCore(copy,data,start + length + 1,end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;

	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; i--)
	{
		copy[indexCopy--] = data[i];
	}

	for (; j >= start + length + 1; j--)
	{
		copy[indexCopy--] = data[j];
	}
	return left + right + count;
}


// ====================测试代码====================
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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

    return 0;
}