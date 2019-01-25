// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是


/*
		*str == '.' 时 代码用||的原因：
         1. 小数可以没有整数部分，例如.123等于0.123；
         2. 小数点后面可以没有数字，例如233.等于233.0；
         3. 当然小数点前面和后面可以有数字，例如233.666

		*str == 'e'或'E' 时 代码用&&的原因：
		// 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
*/



#include <stdio.h>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
	if (str == NULL)
	{
		return false;
	}

	bool numeric = scanInteger(&str);

	if (*str == '.')		// 如果出现'.'，接下来是数字的小数部分
	{
		++str;

		// 注意顺序不能更改，因为涉及到 str是否继续向后遍历的问题 ，若numeric 在前，其为true时便不再判断下个函数，造成str没有向后遍历
		numeric = scanUnsignedInteger(&str) || numeric; 
	}

	if (*str == 'e' || *str == 'E')	// 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
	{
		++str;
		numeric = scanInteger(&str) && numeric;
	}
	return numeric && (*str == '\0');
}

bool scanUnsignedInteger(const char** str)
{
	int flag = 0;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
		flag = 1;
	}
	if (flag)
	{
		return true;
	}
	return false;
}

bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	return scanUnsignedInteger(str);
}



// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}
