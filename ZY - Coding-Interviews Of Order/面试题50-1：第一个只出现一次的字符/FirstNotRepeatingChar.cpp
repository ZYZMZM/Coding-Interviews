// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char FirstNotRepeatingChar(char* pString)
{
	if (pString == NULL)
	{
		return '\0';
	}

	const int size = 256;
	unsigned int hashTable[size];
	for (unsigned int i = 0; i < size; i++)
	{
		hashTable[i] = 0;
	}
	char *pHashKey = pString;
	while (*pHashKey != '\0')
	{
		hashTable[*pHashKey++]++;
	}

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
		{
			return *pHashKey;
		}
		pHashKey++;
	}
	return '\0';
}


// ====================测试代码====================
void Test(char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(nullptr, '\0');

    return 0;
}