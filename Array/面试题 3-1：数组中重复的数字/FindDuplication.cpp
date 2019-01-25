// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。



#include <stdio.h>

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:             
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字

bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == NULL || length <= 0)
	{
		return false;
	}
	
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length-1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}



// ====================测试代码====================

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications = 0;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}

}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// 无效的输入- 空指针
void test5()
{
    int* numbers = NULL;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// 无效的输入 - 长度为n的数组包含0~n-1之外的数字
void test6()
{
    int numbers[] = { 2, 1, 3, 9, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}
void main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}