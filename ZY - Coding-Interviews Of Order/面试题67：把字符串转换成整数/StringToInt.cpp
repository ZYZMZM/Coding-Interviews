// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。

#include <stdio.h>

long long StrToIntCore(const char* str, bool minus);

enum Static
{
	Kvaild = 0,
	KInvaild 
};

int status = KInvaild;

int StrToInt(char *str)
{
	long long num = 0;
	status = KInvaild;

	if (str != NULL && *str != '\0')
	{
		bool IsMinus = false;
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			IsMinus = true;
			str++;
		}

		if (*str != '\0')
		{
			num = StrToIntCore(str,IsMinus);
		}
	}
	return (int)num;
}

long long StrToIntCore(const char* str, bool IsMinus)
{
	long long num = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			int flag = IsMinus ? -1 : 1;
			num = num * 10 + flag * (*str - '0'); 
			if ((!IsMinus && num > 0x7FFFFFFF) || (IsMinus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			str++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	if (*str == '\0')
	{
		status = Kvaild;
	}
	return num;
}



// ====================测试代码====================
void Test(char* string)
{
	StrToInt(string);
	if (status == KInvaild)
	{
		printf("INPUT INVAILD!!!\n");
	}
	else
	{
		printf("%d\n",StrToInt(string));
	}
}

int main(int argc, char* argv[])
{
	Test(NULL);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}
