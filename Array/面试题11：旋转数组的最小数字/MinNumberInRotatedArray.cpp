// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include<stdio.h>

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}
	
	int index1 = 0;
	int index2 = length - 1;
	int middle = index1;  //  防止把数组前0个旋转至后面
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			return numbers[index2];
			break;
		}

		middle = (index1 + index2) / 2;

		if (numbers[index1] == numbers[index2] && numbers[middle] == numbers[index1])
		{
			return MinInOrder(numbers,index1,index2);
		}

		if (numbers[middle] >= numbers[index1])
		{
			index1 = middle;
		}
		else
		{
			index2 = middle;
		}
	}
	return numbers[index1];  // 如果旋转0个元素，numbers[index1] < numbers[index2],第一个即为最小的，输出第一个numbers[index1]
}
int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (numbers[i] < result)
		{
			result = numbers[i];
		}
	}
	return result;
}



// ====================测试代码====================

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
	int length = sizeof(array1)/sizeof(array1[0]);
	printf("%d\n",Min(array1,length));

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    length = sizeof(array2)/sizeof(array2[0]);
	printf("%d\n",Min(array2,length));

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    length = sizeof(array3)/sizeof(array3[0]);
	printf("%d\n",Min(array3,length));

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    length = sizeof(array4)/sizeof(array4[0]);
	printf("%d\n",Min(array4,length));

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    length = sizeof(array5)/sizeof(array5[0]);
	printf("%d\n",Min(array5,length));

    // 数组中只有一个数字
    int array6[] = { 2 };
    length = sizeof(array6)/sizeof(array6[0]);
	printf("%d\n",Min(array6,length));

    // 输入nullptr
	int *array7 =NULL;
    length = 0;
	printf("%d\n",Min(array7,length));

    return 0;
}
