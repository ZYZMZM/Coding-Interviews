// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H



/*

思路：首先定义一个布尔类型的矩阵，此矩阵和字符矩阵大小相同，用来标识路径是否已经进入了每个格子当中
		两层嵌套循环依次遍历字符矩阵中的每一个元素，并调用一个比对函数进行判断
		比对函数的设计：当矩阵中的某一格子元素与字符串下标为pathlength的字符相等时，从该格子相邻的上下
		左右4个格子中匹配与字符串下标为pathlength+1的字符相等的，若4个格子都没有找到，则字符串下标为
		pathlength的字符在字符矩阵中的定位不正确，我们回到前一个字符 （--pathlength）,然后重新定位

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
	{
		return false;
	}

	bool *visited = (bool *)malloc(sizeof(bool) * (rows * cols));
	memset(visited,0,rows * cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			{
				return true;
			}
		}
	}
	free(visited);
	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
	{
		return true;
	}

	bool hasPath = false;
	if (row >= 0 && col >= 0 && row < rows && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		++pathLength;
		visited[row *cols + col] = true;

		hasPath = hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited);
		
		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}

// ====================测试代码====================
//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";
	if (hasPath(matrix,1,1,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";
	if (hasPath(matrix,1,1,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

void Test12()
{
	const char* matrix = NULL;
	const char* str = NULL;
    if (hasPath(matrix,0,0,str))
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
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}

