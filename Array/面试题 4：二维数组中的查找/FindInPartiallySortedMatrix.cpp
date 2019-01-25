// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <stdio.h>

bool Find(int* matrix, int rows, int columns, int number)
{
	if (matrix == NULL)
	{
		return false;
	}
	
	int row  = 0;
	int column = columns - 1;
	while (row < rows && column < columns)
	{
		if (matrix[row * columns + column] == number)
		{
			return true;
		}
		else
		{
			if (number < matrix[row * columns + column])
			{
				column--;	// 要查找的数字比右上角的数字小，往左走
			}
			else
			{
				row++;		// 要查找的数字比右上角的数字大，往下走
			}
		}
	}
	return false;
}

// ====================测试代码====================

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	if (Find((int*)matrix,4,4,7))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,5))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,1))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,15))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,0))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,16))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

// 鲁棒性测试，输入空指针
void Test7()
{
	int *matrix = NULL;
    if (Find(matrix,0,0,16))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
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