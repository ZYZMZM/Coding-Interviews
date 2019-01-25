// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <stdio.h>

int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == NULL || length <= 0 )
	{
		return -1;
	}

	int bitSum[32] = {0};

	for (int i = 0; i < length; i++)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = numbers[i] & bitMask;
			if (bit != 0)
			{
				bitSum[j] += 1;
			}
			bitMask <<= 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;   // result 每次左移一位
		result += bitSum[i] % 3;   // 每次将右边一位存入result
	}
	return result;
}



// ====================测试代码====================

// 所有数字都是正数，唯一的数字是最小的
void Test1()
{
    int numbers[] = { 1, 1, 2, 2, 3 ,2, 1};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 4
}

// 所有数字都是正数，唯一的数字是最大的
void Test3()
{
    int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 7
}

// 唯一的数字是负数
void Test4()
{
    int numbers[] = { -10, 214, 214, 214 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // -10
}

// 除了唯一的数字，其他数字都是负数
void Test5()
{
    int numbers[] = { -209, 3467, -209, -209 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3467
}

// 重复的数字有正数也有负数
void Test6()
{
    int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 1023
}

// 所有数字都是负数
void Test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // -1023
}

// 唯一的数字是0
void Test8()
{
    int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 0
}

// 除了唯一的数字，其他数字都是0
void Test9()
{
    int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3467
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
}