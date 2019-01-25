// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <stdio.h>
#include <string.h>


void Reverse(char *pBegin,char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		pBegin++;
		pEnd--;
	}
}

char* LeftRotateString(char* pStr, int n)
{
	if (pStr == NULL)
	{
		return NULL;
	}

	int length = strlen(pStr);

	if (n < 0 || n > length)
	{
		return NULL;
	}

	char *firstBegin = pStr;
	char *firstEnd = pStr + n - 1;
	char *secondBegin = firstEnd + 1;
	char *secondEnd = pStr + length - 1;

	Reverse(firstBegin,firstEnd);	// 翻转字符串的前半部分
	Reverse(secondBegin,secondEnd);  // 翻转字符串的后半部分
	Reverse(firstBegin,secondEnd);  // 翻转整个字符串
	return pStr;
}



// ====================测试代码====================

// 功能测试
void Test1()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,2);
	printf("%s\n",expected);	// "cdefgab"
}

// 边界值测试
void Test2()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,1);
	printf("%s\n",expected);	// "bcdefga"
}

// 边界值测试
void Test3()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,6);
	printf("%s\n",expected);	// "gabcdef"
	
}

// 鲁棒性测试
void Test4()
{
	char *input = NULL;
	char *expected = LeftRotateString(input,6);
	printf("%s\n",expected);	// null
}

// 鲁棒性测试
void Test5()
{
    char input[] = "abcdefg";
    char *expected = LeftRotateString(input,0);
	printf("%s\n",expected);	// "abcdefg"
}

// 鲁棒性测试
void Test6()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,7);
	printf("%s\n",expected);	// "abcdefg"

}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
