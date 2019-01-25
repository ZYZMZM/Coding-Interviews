// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Swap(int *arr,int low,int high)
{
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

int Partition(int *arr,int low,int high)
{
	srand((unsigned)time(NULL));
	Swap(arr,low,low + rand() % (high - low + 1));

	int start = low;
	int end = high;
	int index = arr[low];

	while (start < end)
	{
		while(start < end && arr[end] >= index) { end--;}
		arr[start] = arr[end];
		while(start < end && arr[start] <= index) { start++;}
		arr[end] = arr[start];
	}
	arr[start] = index;
	return start;
}


void GetLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
	if (input == NULL || output == NULL || n <= 0 || k <= 0 || k > n)
	{
		return;
	}

	int start = 0;
	int end = n - 1;
	int index = Partition(input,start,end);
	
	while (index != k-1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(input,start,end);
		}
		else
		{
			start = index + 1;
			index = Partition(input,start,end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}



// ====================测试代码====================

void Print(int *result,int k)
{
	for (int i = 0; i < k; i++)
	{
		printf("%d ",result[i]);
	}
	printf("\n");
}

// k小于数组的长度
void Test1()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    //int expected[] = {1, 2, 3, 4};
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = 4;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// k等于数组的长度
void Test2()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    //int expected[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = length;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// k大于数组的长度
void Test3()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    //int* expected = nullptr;
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = length+1;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// k等于1
void Test4()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    //int expected[] = {1};
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = 1;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// k等于0
void Test5()
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    //int* expected = nullptr;
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = 0;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// 数组中有相同的数字
void Test6()
{
    int data[] = {4, 5, 1, 6, 2, 7, 2, 8};
    //int expected[] = {1, 2};
	int length = sizeof(data)/sizeof(data[0]);
	int result[100] = {0};
	int k = 2;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
}

// 输入空指针
void Test7()
{
	int *data = NULL;
    //int* expected = nullptr;
	int length = 0;
	int result[100] = {0};
	int k = 0;
	GetLeastNumbers_Solution1(data,length,result,k);
	Print(result,k);
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

    return 0;
}

