// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <stdio.h>

void BuildProductionArray(const int *arrayA, int ALength, int *arrayB)
{
	if (arrayA == NULL || ALength <= 0)
	{
		return;
	}
	arrayB[0] = 1;
	for (int i = 1; i < ALength; i++)
	{
		arrayB[i] = arrayB[i - 1] * arrayA[i - 1];   // 下三角
	}
	int temp = 1;
	for (int i = ALength - 2; i >= 0; i--)
	{
		temp *= arrayA[i + 1];
		arrayB[i] *= temp;        // 上三角
	}
}


//================= 测试用例 =================

void test(const int *arrayA, int ALength, int *arrayB)
{
	BuildProductionArray(arrayA,ALength,arrayB);
	for (int i = 0; i < ALength; i++)
	{
		printf("%d ",arrayB[i]);
	}
	printf("\n");
}

void test1()
{
    // 输入数组中没有0
    int input[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 120, 60, 40, 30, 24 }
}

static void test2()
{
    // 输入数组中有一个0
    int input[] = { 1, 2, 0, 4, 5 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 0, 0, 40, 0, 0 }
    
}

static void test3()
{
    // 输入数组中有两个0
    int input[] = { 1, 2, 0, 4, 0 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 0, 0, 0, 0, 0 }
}

static void test4()
{
    // 输入数组中有正、负数
    int input[] = { 1, -2, 3, -4, 5 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 120, -60, 40, -30, 24 }
}

static void test5()
{
    // 输入输入中只有两个数字
    int input[] = { 1, -2 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { -2, 1 }
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
