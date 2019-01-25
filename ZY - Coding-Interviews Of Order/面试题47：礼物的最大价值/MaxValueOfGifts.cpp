// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Max(int digit1,int digit2)
{
	int max = digit1 > digit2 ? digit1 : digit2;
	return max;
}


int getMaxValue_solution1(const int* values, int rows, int cols)
{
	if (values == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	int **maxValues = (int **)malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; i++)
	{
		maxValues[i] = (int *)malloc(sizeof(int) * cols);
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//当前格的上面和左边一格能够取得的最大值，初始化为0
			int left = 0;
			int up = 0;

			if (i > 0)
			{
				//如果不是第一行，那么可以取到上面一格的最大值
				up = maxValues[i-1][j];
			}
			if (j > 0)
			{
				//如果不是第一列，可以取到左边一格的最大值
				left = maxValues[i][j-1];
			}

			//得到当前格能够取到的最大值   
			maxValues[i][j] = Max(up,left) + values[i * cols + j];
		}
	}

	int maxValue = maxValues[rows - 1][cols - 1];

	for (int i = 0; i < rows; i++)
	{
		free(maxValues[i]);
	}
	free(maxValues);

	return maxValue;
}


int getMaxValue_solution2(const int* values, int rows, int cols)
{
	if (values == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	//只用一行缓存来缓存上一行的最大值
	int *maxValues = (int *)malloc(sizeof(int) * cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int left = 0;
			int up = 0;

			if (i > 0)
			{
				//取上面一格的最大值
				up = maxValues[j];
			}
			if (j > 0)
			{
				//因为左边一格的最大值会及时更新到缓存，所以这里取的是左边一格的数据  
				left = maxValues[j - 1];
			}

			//对当前行的数据实时更新到缓存
			maxValues[j] = Max(left,up) + values[i * cols + j];
		}
	}
	int maxValue = maxValues[cols - 1];
	free(maxValues);
	return maxValue;
}

// ====================测试代码====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
    if(getMaxValue_solution1(values, rows, cols) == expected)
		printf("%s: solution1 passed.\n",testName);
    else
        printf("%s: solution1 FAILED.\n",testName);


    if(getMaxValue_solution2(values, rows, cols) == expected)
        printf("%s: solution2 passed.\n",testName);
    else
        printf("%s: solution2 FAILED.\n",testName);
}

void test1()
{
    // 三行三列
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // 空指针
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
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
