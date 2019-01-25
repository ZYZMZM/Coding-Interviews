// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <stdio.h>
#include <stdlib.h>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers,length,sizeof(int),Compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	// 统计数组中0的个数
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		numberOfZero++;
	}

	// 统计数组中的间隔数目
	int small = numberOfZero;   // 由于数组已经排序，则 在numberOfZero的位置的元素为第一个不为0的元素
	int big = small + 1;
	while (big < length)
	{
		if (numbers[small] == numbers[big])
		{
			return false;  // 有对子，不可能是顺子
		}
		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberOfGap > numberOfZero) ? false : true;
}

int Compare(const void *arg1, const void *arg2)
{
	return *(int *)arg1 - *(int *)arg2;
}



// ====================测试代码====================
void Test(int* numbers, int length)
{
    if (IsContinuous(numbers,length))
	{
		printf("Is Continuous\n");
	}
	else
	{
		printf("Isn't Continuous\n");
	}

}

void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

// 鲁棒性测试
void Test12()
{
	int *numbers = NULL;
    int length = 0;
	Test(numbers,length);  // false
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
    Test10();
    Test11();
    Test12();

    return 0;
}

