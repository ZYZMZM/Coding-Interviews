// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。


/*
	思路：由于不需要讨论大数问题，则求解较为容易，但是需要考虑的细节较多，分别有输入的指数
	小于1（负数或为0），当指数为负数时，可以先对指数求绝对值，计算出次方后再取倒数。我们规定
	当底数base为0且指数是负数时，我们直接返回0就可以，避免对0求倒数。
*/
#include <stdio.h>

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.000000;
	}
	unsigned int absExponent = (unsigned int)(exponent);

	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double result = PowerWithUnsignedExponent(base,absExponent);
	if (exponent < 0)
	{
		result = 1.0/result;
	}
	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1.0;
	}
	if (exponent == 1)
	{
		return base;
	}
	double result = PowerWithUnsignedExponent(base,exponent >> 1);
	result *= result;

	if ((exponent & 0x1) == 1)  // 说明指数为奇数
	{
		result *= base;
	}
	return result;
}

#if 0
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 0; i <= exponent; i++)
	{
		result *= result;
	}
	return result 
}
#endif

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	return false;
}


 //====================测试代码====================

int main()
{
     //底数、指数都为正数
	printf("%lf\n",Power(2,3));  // 8
    // 底数为负数、指数为正数
    printf("%lf\n",Power(-2,3));  // -8

	// 指数为负数
	printf("%lf\n",Power(2,-3));  // 0.125

	// 指数为0
	printf("%lf\n",Power(2,0));  // 1
  
	// 底数、指数都为0
	printf("%lf\n",Power(0,0));  // 1
  
	// 底数为0、指数为正数
	printf("%lf\n",Power(0,4));  // 0
   
	// 底数为0、指数为负数
	printf("%lf\n",Power(0,-1));  // 0
    return 0;
}