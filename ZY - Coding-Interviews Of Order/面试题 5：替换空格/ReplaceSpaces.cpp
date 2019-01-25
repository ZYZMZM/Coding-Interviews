// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <stdio.h>
#include <string.h>

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
	if (str == NULL || length <= 0)
	{
		return;
	}

	// 计算空格长度,字符串长度
	int blanklen = 0;
	int oldlen = 0;
	char *p = str;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			blanklen++;
		}
		p++;
		oldlen++;
	}

	int newlen = oldlen + blanklen * 2;
	if (newlen > length)
	{
		return;
	}
	int lenstr  = oldlen;

	while (lenstr >= 0)
	{
		if (str[lenstr] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[lenstr];
		}
		lenstr--;
	}
}


// ====================测试代码====================
// 空格在句子中间
void Test1()
{
    const int length = 100;
    char str[length] = "hello world";
	ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 空格在句子开头
void Test2()
{
    const int length = 100;
    char str[length] = " helloworld";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;
    char str[length] = "helloworld ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 连续有两个空格
void Test4()
{
    const int length = 100;
    char str[length] = "hello  world";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 传入nullptr
void Test5()
{
	char *str = NULL;
	ReplaceBlank(str,0);
	printf("%s\n",str);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;
    char str[length] = "";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;
    char str[length] = " ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;
    char str[length] = "helloworld";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;
    char str[length] = "   ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
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

    return 0;
}