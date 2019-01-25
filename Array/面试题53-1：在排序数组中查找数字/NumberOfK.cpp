// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,3, 3, 4, 5}和数字3，
// 由于3在这个数组中出现了4次，因此输出4。

#include <stdio.h>

int GetFirstK(const int* data, int length, int k, int start, int end);
int GetLastK(const int* data, int length, int k, int start, int end);

int GetNumberOfK(const int* data, int length, int k)
{
	if (data == NULL)
	{
		return 0;
	}
	int number = 0;
	if (length > 0)
	{
		int first = GetFirstK(data,length,k,0,length - 1);
		int last = GetLastK(data,length,k,0,length - 1);

		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}
	return number;
}

int GetFirstK(const int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];
	
	if (middleData == k)
	{
		if ((middleIndex > 0 && data[middleIndex-1] != k) || middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (middleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}
	return GetFirstK(data,length,k,start,end);
}

int GetLastK(const int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
		{
			return middleIndex;
		}
		else
		{
			start = middleIndex + 1;
		}
	}
	else if (middleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}
	return GetLastK(data,length,k,start,end);
}


// ====================测试代码====================

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));   // 4
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  //4
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  //4
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,2));   // 0
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,0));  // 0
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,6));   // 0
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));   // 4
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,4));   // 0
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  // 1
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,4));  // 0
}

// 鲁棒性测试，数组空指针
void Test11()
{
	int *data = NULL;
    int length = 0;
	printf("%d\n",GetNumberOfK(data,length,3));  // 0
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

    return 0;
}
