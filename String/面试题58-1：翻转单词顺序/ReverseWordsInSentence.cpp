// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

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

char* ReverseSentence(char *pData)
{
	if (pData == NULL)
	{
		return NULL;
	}
	
	char *pBegin = pData;
	char *pEnd = pData;
	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;

	Reverse(pBegin,pEnd);  // 翻转整个句子

	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin,--pEnd); // 翻转每个单词
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}



// ====================测试代码====================

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"student. a am I";
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"Wonderful";
}

// 鲁棒性测试
void Test3()
{
    char *input = NULL;
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"";
}

// 边界值测试，测试空字符串
void Test4()
{
    char input[] = "";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"";
}

// 边界值测试，字符串中只有空格
void Test5()
{
    char input[] = "   ";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"    ";
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}