// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <stdio.h>

int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == NULL || length < 2)
	{
		return 0x80000000;
	}

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i-1] < min)
		{
			min = numbers[i-1];
		}

		int curMaxDiff = numbers[i] - min;
		if (curMaxDiff > maxDiff)
		{
			maxDiff = curMaxDiff;
		}
	}
	return maxDiff;
}




// ==================== Test Code ====================
void Test(const int* numbers, unsigned length)
{
	printf("%d\n",MaxDiff(numbers, length));
}

void Test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 4
}

// 价格递增
void Test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 15
}

// 价格递减
void Test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // -1
}

// 价格全部相同
void Test4()
{
	int numbers[] = { 16, 16, 16, 16, 16 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 0
}

void Test5()
{
    int numbers[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 11
}

void Test6()
{
    int numbers[] = { 2, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 2
}

void Test7()
{
    int numbers[] = { 4, 2 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // -2
}

void Test8()
{
	int *numbers = NULL;
	int length = 0;
	Test(numbers,length);  // 
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
