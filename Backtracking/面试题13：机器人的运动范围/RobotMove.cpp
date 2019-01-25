// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

/*

	和面试题12类似，可将方格看成一个 m * n 的矩阵，同样，出边界格子外，每个格子都有四个相邻的格子
	算法思想使用回溯法，movingCount为初始化函数，movingCountCore为计算能到达的格子个数的函数
	check函数用来判断机器人能否进入坐标为（row，col）的方格，而函数getDigitSum用来得到一个数字的位数之和

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	bool *visited = (bool *)malloc(sizeof(bool) * (rows * cols));
	memset(visited,false,rows * cols);

	int count = movingCountCore(threshold,rows,cols,0,0,visited);
	
	free(visited);
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold,rows,cols,row,col,visited))
	{
		visited[row * cols + col] = true;
		count = 1 + movingCountCore(threshold,rows,cols,row - 1,col,visited)+\
					movingCountCore(threshold,rows,cols,row,col - 1,visited)+\
					movingCountCore(threshold,rows,cols,row + 1,col,visited)+\
					movingCountCore(threshold,rows,cols,row,col + 1,visited);
	}
	return count;
}


bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && col >= 0 && row < rows && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
	{
		return true;
	}
	return false;
}

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}



// ====================测试代码====================


// 方格多行多列
void test1()
{
    printf("%d\n",movingCount(5, 10, 10));  // 21
}

// 方格多行多列
void test2()
{
    printf("%d\n",movingCount(15, 20, 20)); // 359
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    printf("%d\n",movingCount(10, 1, 100));	// 29
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    printf("%d\n",movingCount(10, 1, 10)); // 10
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    printf("%d\n",movingCount(15, 100, 1));  // 79
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    printf("%d\n",movingCount(15, 10, 1));  // 10
}

// 方格只有一行一列
void test7()
{
    printf("%d\n",movingCount(15, 1, 1));  // 1
}

// 方格只有一行一列
void test8()
{
    printf("%d\n",movingCount(0, 1, 1));  // 1
}

// 机器人不能进入任意一个方格
void test9()
{
    printf("%d\n",movingCount(-10, 10, 10));  // 0
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}
